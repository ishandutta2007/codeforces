// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str to_string

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

const int N = 2222;

ll dp[N][N];

void run() {
	int n, m, k;
	cin >> n >> m >> k;
	dp[1][0] = m;
	for (int i = 2; i <= n; i++) {
		for (int pos = 0; pos <= i - 1; pos++) {
			dp[i][pos] = dp[i - 1][pos];
			if (pos) {
				dp[i][pos] += (dp[i - 1][pos - 1] * (m - 1)) % MOD998;
				dp[i][pos] %= MOD998;
			}
		}
	}
	cout << dp[n][k] << "\n";
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