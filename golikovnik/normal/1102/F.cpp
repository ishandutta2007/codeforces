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

#define last gjs13
#define prev jjk414kj

void run() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	if (n == 1) {
		int ans = INT_MAX;
		for (int i = 0; i + 1 < m; i++) {
			ans = min(ans, abs(a[0][i] - a[0][i + 1]));
		}
		cout << ans << "\n";
		return;
	}
	vector<vector<int>> g1(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int res = INT_MAX;
			for (int k = 0; k < m; k++) {
				res = min(res, abs(a[i][k] - a[j][k]));
			}
			g1[i][j] = g1[j][i] = res;
		}
	}
	vector<vector<int>> g2(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			int res = INT_MAX;
			for (int k = 0; k + 1 < m; k++) {
				res = min(res, abs(a[j][k] - a[i][k + 1]));
			}
			g2[i][j] = res;
		}
	}
	vector<vector<int>> dp1(n, vector<int>(1 << n)), dp2(n, vector<int>(1 << n));
	int ans = 0;
	for (int s = 0; s < n; s++) {
		for (int mask = 1; mask < (1 << n); mask++) {
			if ((mask & (1 << s)) == 0) {
				continue;
			}
			if (__builtin_popcount(mask) == 1) {
				dp1[s][mask] = dp2[s][mask] = INT_MAX;
				continue;
			}
			for (int last = 0; last < n; last++) {
				if (mask & (1 << last)) {
					if (last == s) {
						continue;
					}
					for (int prev = 0; prev < n; prev++) {
						if (mask & (1 << prev)) {
							if (prev == last) {
								continue;
							}
							dp1[last][mask] = max(dp1[last][mask], min(dp1[prev][mask ^ (1 << last)], g1[prev][last]));
							dp2[last][mask] = max(dp2[last][mask], min({dp1[prev][mask ^ (1 << last)], g1[prev][last], g2[s][last]}));
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			ans = max(ans, dp2[i][(1 << n) - 1]);
			fill(all(dp1[i]), 0);
			fill(all(dp2[i]), 0);
		}
	}
	cout << ans << "\n";
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