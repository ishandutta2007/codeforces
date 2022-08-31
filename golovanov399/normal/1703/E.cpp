#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vector<pair<int, int>> ij;
			int x = i, y = j;
			for ([[maybe_unused]] char c : ")))") {
				ij.push_back({x, y});
				swap(x, y);
				y = n - 1 - y;
			}
			make_unique(ij);
			if (pair{i, j} == ij[0]) {
				int cnt = 0;
				for (auto [x, y] : ij) {
					cnt += a[x][y] == '1';
				}
				ans += min(cnt, (int)ij.size() - cnt);
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}