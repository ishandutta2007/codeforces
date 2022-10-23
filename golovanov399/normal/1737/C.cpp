#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	int mask = 0;
	bool border = true;
	set<pair<int, int>> S;
	pair<int, int> last;
	for (int i = 0; i < 4; ++i) {
		int x = nxt(), y = nxt();
		if (i == 3) {
			last = {x, y};
		} else {
			S.insert({x, y});
			border &= (x == 1 || x == n || y == 1 || y == n);
		}
		x %= 2;
		y %= 2;
		mask |= 1 << (2 * x + y);
	}
	int common_x = -1, common_y = -1;
	for (auto [x, y] : S) {
		int cnt_x = 0, cnt_y = 0;
		for (auto p : S) {
			cnt_x += x == p.first;
			cnt_y += y == p.second;
		}
		if (cnt_x == 2) {
			common_x = x;
		}
		if (cnt_y == 2) {
			common_y = y;
		}
	}
	cout << (mask == 15 || (!S.contains(last) && border && last.first != common_x && last.second != common_y) ? "NO" : "YES") << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}