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

ll sqr(ll x) {
	return x * x;
}

void run() {
	int n;
	cin >> n;
	n /= 2;
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
	}
	ll pref = 0;
	vector<ll> ans(2 * n);
	for (int i = 0; i < n; i++) {
		ll c = ll(sqrtl(pref)) * 2;
		ll x = LLONG_MAX;
		for (int d = 1; d * d <= a[i]; d++) {
			if (a[i] % d == 0) {
				ll big = a[i] / d;
				if (big - d > c && (big - d) % 2 == 0) {
					x = min(x, sqr((big - d) / 2));
				}
			}
		}
		if (x == LLONG_MAX) {
			cout << "No\n";
			return;
		}
		ans[2 * i + 1] = a[i];
		ans[2 * i] = x - pref;
		pref += ans[2 * i] + ans[2 * i + 1];
	}
	cout << "Yes\n";
	for (ll x : ans) {
		cout << x << " ";
	}
	cout << "\n";
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