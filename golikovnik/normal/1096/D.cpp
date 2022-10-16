// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str(x) to_string(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const ll MOD998 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;

mt19937_64 rng((uint) chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T rnd(T l, T r) {
	return uniform_int_distribution<T>(l, r)(rng);
}

void run() {
	int n;
	string s;
	cin >> n >> s;
	vector<ll> a(n);
	for (ll &x : a) {
		cin >> x;
	}
	string t = "hard";
	vector<vector<ll>> dp(n + 1, vector<ll>(szof(t) + 1, LLINF));
	fill(all(dp[0]), 0);
	dp[0][0] = LLINF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= szof(t); j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i - 1]);
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			} else {
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
		}
	}
	cout << dp[n][szof(t)] << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests;
	tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}