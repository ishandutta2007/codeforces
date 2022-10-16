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
	int w, h, u1, d1, u2, d2;
	cin >> w >> h >> u1 >> d1 >> u2 >> d2;
	if (d1 < d2) {
		swap(d1, d2);
		swap(u1, u2);
	}
	int ans = w;
	for (int cur = h; cur >= d1; cur--) {
		ans += cur;
	}
	ans -= u1;
	if (ans < 0) {
		ans = 0;
	}
	for (int cur = d1 - 1; cur >= d2; cur--) {
		ans += cur;
	}
	ans -= u2;
	if (ans < 0) {
		ans = 0;
	}
	for (int cur = d2 - 1; cur >= 0; cur--) {
		ans += cur;
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