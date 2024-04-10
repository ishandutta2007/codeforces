#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int ask(int i, int j, int k) {
	cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
	return nxt();
}

void solve() {
	int n = nxt();
	vector<int> cur = {0, 1, 2};
	int x = ask(0, 1, 2);
	for (int i = 3; i < n; ++i) {
		int y1 = ask(cur[0], cur[1], i);
		int y2 = ask(cur[0], cur[2], i);
		if (max({x, y1, y2}) == y1 && y1 > x) {
			cur[2] = i;
			x = y1;
		} else if (max({x, y1, y2}) == y2 && y2 > x) {
			cur[1] = i;
			x = y2;
		}
	}
	int mid = 0;
	while (find(all(cur), mid) != cur.end()) {
		++mid;
	}
	for (int i = 0; i < 3; ++i) {
		int old = cur[i];
		cur[i] = mid;
		if (ask(cur[0], cur[1], cur[2]) == x) {
			cout << "! " << cur[(i + 1) % 3] + 1 << " " << cur[(i + 2) % 3] + 1 << endl;
			return;
		}
		cur[i] = old;
	}
	assert(false);
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}