#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <map>
#include <random>

using namespace std;

using ll = long long;

const int MAX_N = 500000;

const ll MOD = 998244353;

ll fact[MAX_N + 1];
ll inv_fact[MAX_N + 1];

ll BinPow(ll x, ll pow) {
	if (!pow) {
		return 1;
	}
	if (pow & 1) {
		return BinPow(x, pow - 1) * x % MOD;
	} else {
		return BinPow(x * x % MOD, pow / 2);
	}
}

ll Inv(ll x) {
	return BinPow(x, MOD - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		ll ones = 0;
		ll zeros = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] == 0) {
				++zeros;
			} else {
				++ones;
			}
		}
		ll bad_zeros = 0;
		for (int i = n - ones; i < n; ++i) {
			if (a[i] == 0) {
				++bad_zeros;
			}
		}
		vector<ll> dp(n + 1);
		dp[0] = 0;
		ll total = (n * (n - 1) / 2) % MOD;
		ll inv_total = Inv(total);
		for (ll i = 1; i <= n; ++i) {
			ll good = i * i % MOD;
			ll p = good * inv_total % MOD;
			dp[i] = (1 + dp[i - 1] * p) % MOD * Inv(p) % MOD;
		}
		cout << dp[bad_zeros] << '\n';
	}
	return 0;
}

/*
6
1 1 0 0 1 1
 */