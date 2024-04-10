#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str(x) to_string(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;
const int MOD998 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;

mt19937_64 rng((uint) chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T rnd(T l, T r) {
	return uniform_int_distribution<T>(l, r)(rng);
}

void run() {
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> cnt(3), left(3), right(3);
	for (int d = 0; d < 3; d++) {
		left[(l + d) % 3] = l + d;
		right[(r - d + 3) % 3] = r - d;
	}
	for (int rem = 0; rem < 3; rem++) {
		int rr = right[rem], le = left[rem];
		if (le <= rr) {
			cnt[rem] = (rr - le + 3) / 3;
		}
	}
	vector<int> dp(3);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		vector<int> new_dp(3);
		for (int rem = 0; rem < 3; rem++) {
			for (int pre = 0; pre < 3; pre++) {
				new_dp[(pre + rem) % 3] += (1LL * dp[pre] * cnt[rem] % MOD);
				new_dp[(pre + rem) % 3] %= MOD;
			}
		}
		dp.swap(new_dp);
	}
	cout << dp[0] << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}