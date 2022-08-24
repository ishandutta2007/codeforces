
#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), m = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	vector<long long> p(n + 1);
	for (int i = 0; i < n; ++i) {
		p[i + 1] = p[i] + a[i];
	}
	vector<long long> dp(n + 1);
	for (int i = n - m; i >= 0; --i) {
		dp[i] = max(p[i + m] - p[i] - k + dp[i + m], 0ll);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, dp[i]);
		for (int j = 0; j < m && i + j <= n; ++j) {
			ans = max(ans, p[i + j] - p[i] - k + dp[i + j]);
		}
	}
	cout << ans << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}