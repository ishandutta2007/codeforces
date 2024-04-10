#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const ll MOD = 998244353;
ll fact[500001];

ll binp(ll a, ll p) {
	if (p == 0) return 1;
	if (p % 2) return binp(a, p - 1) * a % MOD;
	ll x = binp(a, p / 2);
	return x * x % MOD;
}

ll cnk(ll n, ll k) {
	if (k > n) return 0;
	ll res = 1;
	res *= fact[n];
	res %= MOD;
	res *= binp(fact[k], MOD - 2);
	res %= MOD;
	res *= binp(fact[n - k], MOD - 2);
	res %= MOD;
	return res;
}

int main() {
	fact[0] = 1;
	for (ll i = 1; i <= 500000; i++)
		fact[i] = (fact[i - 1] * i) % MOD;
	ll ans = 0;
	ll n, k;
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		ll _n = n / i - 1;
		ll _k = k - 1;
		ans += cnk(_n, _k);
		ans %= MOD;
	}
	cout << ans;
	return 0;
}