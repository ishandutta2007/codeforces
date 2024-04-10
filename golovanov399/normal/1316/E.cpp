#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

template <typename T>
void remax(T& x, const T& y) {
	x = max(x, y);
}

const int N = 111111;
const int M = 130;
pair<long long, int> dp[N][M];

void solve() {
	int n = nxt(), p = nxt(), k = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<vector<int>> b(n, vector<int>(p, 0));
	for (auto& v : b) {
		generate(all(v), nxt);
	}

	vector<int> perm(n);
	iota(all(perm), 0);
	sort(all(perm), [&](int i, int j) {
		return a[i] > a[j];
	});

	for (int i = 0; i < n; ++i) {
		int idx = perm[i];
		for (int mask = 0; mask < (1 << p); ++mask) {
			remax(dp[i + 1][mask], {dp[i][mask].first, -2});
			int cur_k = i - __builtin_popcount(mask);
			if (cur_k < 0) {
				continue;
			}
			if (cur_k < k) {
				remax(dp[i + 1][mask], {dp[i][mask].first + a[idx], -1});
			}
			for (int j = 0; j < p; ++j) {
				if (mask & (1 << j)) {
					continue;
				}
				remax(dp[i + 1][mask | (1 << j)], {dp[i][mask].first + b[idx][j], j});
			}
		}
	}

	cout << dp[n][(1 << p) - 1].first << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}