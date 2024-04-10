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
	cin >> n;
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
	}
	vector<int> pref_max(n + 1), pref_min(n + 1);
	pref_max[0] = -INF, pref_min[0] = INF;
	for (int i = 0; i < n; i++) {
		pref_max[i + 1] = max(pref_max[i], a[i]);
		pref_min[i + 1] = min(pref_min[i], a[i]);
	}
	vector<int> suff_max(n + 1), suff_min(n + 1);
	suff_min[n] = INF, suff_max[n] = -INF;
	for (int i = n - 1; i >= 0; i--) {
		suff_max[i] = max(suff_max[i + 1], a[i]);
		suff_min[i] = min(suff_min[i + 1], a[i]);
	}
	int ans = min(suff_max[1] - suff_min[1], pref_max[n - 1] - pref_min[n - 1]);
	for (int i = 1; i < n; i++) {
		ans = min(ans, max(pref_max[i], suff_max[i + 1]) - min(pref_min[i], suff_min[i + 1]));
	}
	cout << ans << "\n";
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