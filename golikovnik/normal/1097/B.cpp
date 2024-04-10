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
	for (int mask = 0; mask < (1 << n); mask++) {
		int s = 0;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				s += a[i];
			} else {
				s -= a[i];
			}
			if (s < 0) {
				s += 360;
			}
			if (s >= 360) {
				s -= 360;
			}
		}
		if (s == 0) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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