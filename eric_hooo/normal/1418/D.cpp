#include <bits/stdc++.h>
using namespace std;

set <int> all;
multiset <int> space;

int get_pre(int x) {
	set <int> :: iterator it = all.lower_bound(x);
	if (it == all.begin()) return -1;
	it--;
	return *it;
}

int get_suc(int x) {
	set <int> :: iterator it = all.upper_bound(x);
	if (it == all.end()) return -1;
	return *it;
}

void Change(int x) {
	if (all.count(x)) {
		int pre = get_pre(x), suc = get_suc(x);
		if (pre != -1) space.erase(space.find(x - pre));
		if (suc != -1) space.erase(space.find(suc - x));
		if (pre != -1 && suc != -1) space.insert(suc - pre);
		all.erase(x);
	} else {
		all.insert(x);
		int pre = get_pre(x), suc = get_suc(x);
		if (pre != -1) space.insert(x - pre);
		if (suc != -1) space.insert(suc - x);
		if (pre != -1 && suc != -1) space.erase(space.find(suc - pre));
	}
}

int get_max() {
	return *(--all.end());
}

int get_min() {
	return *all.begin();
}

int get_max_space() {
	return *(--space.end());
}

int main () {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		Change(x);
	}
	if (all.size() <= 2) printf("0\n");
	else printf("%d\n", get_max() - get_min() - get_max_space());
	while (q--) {
		int op, x; scanf("%d%d", &op, &x);
		Change(x);
		if (all.size() <= 2) printf("0\n");
		else printf("%d\n", get_max() - get_min() - get_max_space());
	}
	return 0;
}