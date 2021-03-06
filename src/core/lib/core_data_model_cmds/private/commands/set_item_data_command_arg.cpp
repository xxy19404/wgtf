#include "set_item_data_command_arg.hpp"
#include "core_data_model/abstract_item_model.hpp"

#include <limits>

namespace wgt
{
SetItemDataCommandArgument::SetItemDataCommandArgument() : pModel_(nullptr), roleId_(std::numeric_limits<size_t>::max())
{
}

void SetItemDataCommandArgument::setModel(AbstractItemModel& model)
{
	pModel_ = &model;
}

void SetItemDataCommandArgument::setIndex(const AbstractItemModel::ItemIndex& index)
{
	index_ = index;
}

void SetItemDataCommandArgument::setValue(size_t roleId, const Variant& newValue)
{
	roleId_ = roleId;

	assert(pModel_ != nullptr);
	assert(index_.isValid());
	auto pItem = pModel_->item(index_);
	assert(pItem != nullptr);

	oldValue_ = pItem->getData(index_.row_, index_.column_, roleId_);
	newValue_ = newValue;
}

} // end namespace wgt
