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

int add(int x, int y, int mod = MOD998) {
	return x + y >= mod ? x + y - mod : x + y;
}

int sub(int x, int y, int mod = MOD998) {
	return x - y < 0 ? x - y + mod : x - y;
}

int mul(int x, int y, int mod = MOD998) {
	return 1LL * x * y % mod;
}

int pw(int a, int n, int mod = MOD998) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = mul(res, a, mod);
		}
		a = mul(a, a, mod);
		n >>= 1;
	}
	return res;
}

int inv(int x, int mod = MOD998) {
	return pw(x, mod - 2, mod);
}

void run() {
	int n;
	cin >> n;	
	vector<int> fact(n + 1);
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = mul(i, fact[i - 1]);
	}
	int ans = fact[n];
	int x = 1;
	for (int i = 1; i < n; i++) {
		x = mul(x, n - (i - 1));
		ans = add(ans, sub(fact[n], x));
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