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

const int N = 1e7 + 20;

#define int ll

ll b[N], a[N], pref[N], suff[N];

void run() {
	int n, l, r, x, y, z, b1, b2;
	cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
	b[0] = b1;
	b[1] = b2;
	for (int i = 2; i < n; i++) {
		b[i] = (b[i - 2] * x + b[i - 1] * y + z) & ((1LL << 32) - 1);
	}
	for (int i = 0; i < n; i++) {
		a[i] = b[i] % (r - l + 1) + l;
	}
	pref[0] = a[0];
	for (int i = 1; i < n; i++) {
		pref[i] = min(a[i], pref[i - 1]);
	}
	suff[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		suff[i] = max(a[i], suff[i + 1]);
	}
	ll ans = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			if (i + 1 < n && suff[i + 1] > a[i]) {
				ans = min(ans, a[i] * suff[i + 1]);
			}
		} else if (a[i] > 0) {
			if (i > 0 && pref[i - 1] < a[i]) {
				ans = min(ans, a[i] * pref[i - 1]);
			}
		}
	}
	if (ans == LLONG_MAX) {
		cout << "IMPOSSIBLE";
	} else {
		cout << ans;
	}
	cout << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests;
	// tests = 1;
	cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}