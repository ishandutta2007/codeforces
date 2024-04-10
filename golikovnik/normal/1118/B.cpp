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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
	}
	vector<int> suff(n + 2);
	suff[n - 1] = a[n - 1];
	if (n > 1) {
		suff[n - 2] = a[n - 2];
	}
	for (int i = n - 3; i >= 0; i--) {
		suff[i] = a[i] + suff[i + 2];
	}
	int ans = 0, odd = 0, even = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			if (odd + suff[i + 1] == even + suff[i + 2]) {
				ans++;
			}
			odd += a[i];
		} else {
			if (odd + suff[i + 2] == even + suff[i + 1]) {
				ans++;
			}
			even += a[i];
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