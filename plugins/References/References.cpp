/*
Copyright (C) 2006 - 2015 Evan Teran
                          evan.teran@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "References.h"
#include "DialogReferences.h"
#include "edb.h"
#include <QMenu>

namespace ReferencesPlugin {

//------------------------------------------------------------------------------
// Name: References
// Desc:
//------------------------------------------------------------------------------
References::References() : menu_(0), dialog_(0) {
}

//------------------------------------------------------------------------------
// Name: ~References
// Desc:
//------------------------------------------------------------------------------
References::~References() {
	delete dialog_;
}

//------------------------------------------------------------------------------
// Name: menu
// Desc:
//------------------------------------------------------------------------------
QMenu *References::menu(QWidget *parent) {

	Q_ASSERT(parent);

	if(!menu_) {
		menu_ = new QMenu(tr("Reference Searcher"), parent);
		menu_->addAction(tr("&Reference Search"), this, SLOT(show_menu()), QKeySequence(tr("Ctrl+R")));
	}

	return menu_;
}

//------------------------------------------------------------------------------
// Name: show_menu
// Desc:
//------------------------------------------------------------------------------
void References::show_menu() {

	if(!dialog_) {
		dialog_ = new DialogReferences(edb::v1::debugger_ui);
	}

	dialog_->show();
}

}
