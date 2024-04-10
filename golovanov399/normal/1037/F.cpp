#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), k = nxt();
	vector<long long> dp(n + 1);
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		if ((i - 1) % (k - 1) == 0) {
			++cur;
		}
		dp[i] = dp[i - 1] + cur;
	}

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = {nxt(), i};
	}
	sort(all(a));
	reverse(all(a));

	set<int> S;
	S.insert(-1);
	S.insert(n);
	long long ans = 0;
	const int mod = 1000000007;

	for (auto p : a) {
		int idx = p.second;
		auto it = S.lower_bound(idx);
		int nx = *it;
		int pr = *prev(it);
		S.insert(idx);

		ans += 1ll * (dp[nx - pr - 1] - dp[nx - idx - 1] - dp[idx - pr - 1] - 1) % mod * p.first % mod;
	}
	cout << ans % mod << "\n";

	return 0;
}