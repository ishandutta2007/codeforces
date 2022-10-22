#include <bits/stdc++.h>
using namespace std;

void chmax(long long &x, long long y) {
	x = max(x, y);
}

struct Block {
	int x, y; char type;
	long long realx, realy;
	string name;
	vector <Block *> son;
	Block() {son.clear();}
	long long get_x() {
		if (type != 'W' && son.empty()) return 0;
		return type == 'W' ? x : x * 2 + realx + (type == 'H' ? y * max(0, (int)son.size() - 1) : 0);
	}
	long long get_y() {
		if (type != 'W' && son.empty()) return 0;
		return type == 'W' ? y : x * 2 + realy + (type == 'H' ? 0 : y * max(0, (int)son.size() - 1));
	}
	void update() {
		realx = 0, realy = 0;
		for (int i = 0; i < son.size(); i++) {
			if (type == 'H') realx += son[i]->get_x(), chmax(realy, son[i]->get_y());
			else chmax(realx, son[i]->get_x()), realy += son[i]->get_y();
		}
	}
	void pack(Block *A) {
		son.push_back(A);
	}
};

string buf;
vector <Block *> all;

bool cmp(Block *A, Block *B) {
	return A->name < B->name;
}

string get_str(string :: iterator &it, char END) {
	string s;
	while (*it != END) {
		s.push_back(*it);
		it++;
	}
	return s;
}

int get_num(string :: iterator &it) {
	int x = 0;
	while ('0' <= *it && *it <= '9') {
		x = x * 10 + *it - '0';
		it++;
	}
	return x;
}

map <string, int> in;

int main () {
	int T; cin >> T;
	getline(cin, buf);
	while (T--) {
		getline(cin, buf);
		if (buf[0] == 'W') {
			string :: iterator it = buf.begin() + 7;
			Block *tmp = new Block(); tmp->type = 'W', tmp->name = get_str(it, '(');
			it++, tmp->realx = tmp->x = get_num(it), it++, tmp->realy = tmp->y = get_num(it);
			tmp->son.clear();
			all.push_back(tmp);
		} else if (buf[0] == 'H' || buf[0] == 'V') {
			buf.push_back(';');
			string :: iterator it = buf.begin() + 5;
			Block *tmp = new Block(); tmp->type = buf[0], tmp->name = get_str(it, ';');
			tmp->realx = tmp->realy = tmp->x = tmp->y = 0;
			all.push_back(tmp);
		} else {
			string :: iterator it = buf.begin();
			string name = get_str(it, '.');
			Block *tmp;
			for (int i = 0; i < all.size(); i++) {
				if (all[i]->name == name) {
					tmp = all[i];
					break;
				}
			}
			it++; string op = get_str(it, '(');
			if (op == "pack") {
				it++; string qwq = get_str(it, ')');
				for (int i = 0; i < all.size(); i++) {
					if (all[i]->name == qwq) {
						tmp->pack(all[i]), in[qwq]++;
					}
				}
			} else {
				it++; int val = get_num(it);
				if (op == "set_border") tmp->x = val;
				else tmp->y = val;
				tmp->update();
			}
		}
	}
	vector <Block *> ord;
	for (int i = 0; i < all.size(); i++) {
		if (in[all[i]->name] == 0) ord.push_back(all[i]);
	}
	for (int _ = 0; _ < ord.size(); _++) {
		Block *x = ord[_];
		for (int i = 0; i < x->son.size(); i++) {
			in[x->son[i]->name]--;
			if (in[x->son[i]->name] == 0) {
				ord.push_back(x->son[i]);
			}
		}
	}
	for (int i = ord.size() - 1; i >= 0; i--) {
		ord[i]->update();
	}
	sort(all.begin(), all.end(), cmp);
	for (int i = 0; i < all.size(); i++) {
		cout << all[i]->name << " " << all[i]->get_x() << " " << all[i]->get_y() << endl;
	}
	return 0;
}