#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int L = 30;

void solve() {
	int n = nxt(), m = nxt();
	vector<array<int, 3>> req(m);
	for (int i = 0; i < m; ++i) {
		req[i][0] = nxt() - 1;
		req[i][1] = nxt() - 1;
		req[i][2] = nxt();
	}
	vector<int> ans(n);
	vector<vector<pair<int, int>>> ls(n);
	for (auto [i, j, x] : req) {
		ls[max(i, j)].push_back({min(i, j), x});
	}
	for (int bit = 0; bit < L; ++bit) {
		vector<char> is_zero(n);
		for (auto [i, j, x] : req) {
			if (!(x & (1 << bit))) {
				is_zero[i] = 1;
				is_zero[j] = 1;
			}
		}
		vector<int> cur(n);
		for (auto [i, j, x] : req) {
			if (x & (1 << bit)) {
				assert(!is_zero[i] || !is_zero[j]);
				if (is_zero[i]) {
					cur[j] = 1;
				} else if (is_zero[j]) {
					cur[i] = 1;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (auto [j, x] : ls[i]) {
				if ((x & (1 << bit)) && !cur[j]) {
					cur[i] = 1;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			ans[i] += cur[i] << bit;
		}
	}
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}