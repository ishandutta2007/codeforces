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
	ll n;
	int k;
	cin >> n >> k;
	vector<pair<ll, int>> factorization;
	for (ll d = 2; d * d <= n; d++) {
		int cnt = 0;
		while (n % d == 0) {
			cnt++;
			n /= d;
		}
		if (cnt) {
			factorization.emplace_back(d, cnt);
		}
	}
	if (n) {
		factorization.emplace_back(n, 1);
	}
	auto solve = [&k](ll pr, int deg) {
		pr %= MOD;
		vector<vector<int>> dp(k + 1, vector<int>(deg + 1));
		vector<int> invs(deg + 2);
		for (int i = 1; i <= deg + 1; i++) {
			invs[i] = inv(i, MOD);
		}
		dp[0][deg] = 1;
		for (int turns = 1; turns <= k; turns++) {
			for (int d = 0; d <= deg; d++) {
				for (int prev = d; prev <= deg; prev++) {
					dp[turns][d] = add(dp[turns][d], mul(dp[turns - 1][prev], invs[prev + 1], MOD), MOD);
				}
			}
		}
		int pwr = 1; 
		int res = 0;
		for (int d = 0; d <= deg; d++) {
			res = add(res, mul(dp[k][d], pwr, MOD), MOD);
			pwr = mul(pwr, pr, MOD);
		}
		return res;
	};
	int ans = 1;
	for (auto[pr, deg] : factorization) {
		ans = mul(ans, solve(pr, deg), MOD);
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