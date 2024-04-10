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
	int n = nxt(), m = nxt();
	vector<deque<int>> a(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i].push_back(nxt());
		}
		sort(all(a[i]));
	}
	vector<vector<int>> ans(n);
	for (int i = 0; i < m; ++i) {
		pair<int, int> opt = {(int)2e9, -1};
		for (int j = 0; j < n; ++j) {
			opt = min(opt, {a[j].front(), j});
		}
		for (int j = 0; j < n; ++j) {
			if (opt.second == j) {
				ans[j].push_back(a[j].front());
				a[j].pop_front();
			} else {
				ans[j].push_back(a[j].back());
				a[j].pop_back();
			}
		}
	}
	for (auto v : ans) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}