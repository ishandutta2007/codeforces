#include <cstdio>
#include <cmath>

#include <algorithm>
#include <map>

typedef std::map<int, int> map;
typedef map::iterator iterator;
typedef int num;
typedef long long ll;

map top, down;

ll det(int x1, int y1, int x2, int y2);
bool check_top(int x, int y);
bool check_down(int x, int y);
bool remove_top(iterator it);
bool remove_down(iterator it);
void insert_top(int x, int y);
void insert_down(int x, int y);

int main() {
	int q, op, x, y;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			insert_top(x, y);
			insert_down(x, y);
		} else
			puts((check_top(x, y) && check_down(x, y)) ? "YES" : "NO");
	}
	return 0;
}

void insert_top(int x, int y) {
	if (check_top(x, y))
		return;
	top[x] = y;
	iterator it = top.find(x);
	iterator jt = it;
	if (it != top.begin()) {
		--jt;
		while (remove_top(jt++))
			--jt;
	}
	if (++jt != top.end())
		while (remove_top(jt--))
			++jt;
}

ll det(int x1, int y1, int x2, int y2) {
	return (ll)x1 * y2 - (ll)x2 * y1;
}

void insert_down(int x, int y) {
	if (check_down(x, y))
		return;
	down[x] = y;
	iterator it = down.find(x);
	iterator jt = it;
	if (it != down.begin()) {
		--jt;
		while (remove_down(jt++))
			--jt;
	}
	if (++jt != down.end())
		while (remove_down(jt--))
			++jt;
}

bool remove_top(iterator it) {
	if (it == top.begin())
		return false;
	iterator jt = it, kt = it;
	--jt;
	++kt;
	if (kt == top.end())
		return false;
	if (det(it->first - jt->first, it->second - jt->second, kt->first - jt->first, kt->second - jt->second) >= 0) {
		top.erase(it);
		return true;
	}
	return false;
}

bool remove_down(iterator it) {
	if (it == down.begin())
		return false;
	iterator jt = it, kt = it;
	--jt;
	++kt;
	if (kt == down.end())
		return false;
	if (det(it->first - jt->first, it->second - jt->second, kt->first - jt->first, kt->second - jt->second) <= 0) {
		down.erase(it);
		return true;
	}
	return false;
}

bool check_top(int x, int y) {
	iterator it = top.lower_bound(x);
	if (it == top.end())
		return false;
	if (it->first == x)
		return y <= it->second;
	if (it == top.begin())
		return false;
	iterator jt = it;
	--jt;
	return det(it->first - jt->first, it->second - jt->second, x - jt->first, y - jt->second) <= 0;
}

bool check_down(int x, int y) {
	iterator it = down.lower_bound(x);
	if (it == down.end())
		return false;
	if (it->first == x)
		return y >= it->second;
	if (it == down.begin())
		return false;
	iterator jt = it;
	--jt;
	return det(it->first - jt->first, it->second - jt->second, x - jt->first, y - jt->second) >= 0;
}