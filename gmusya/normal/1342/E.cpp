#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll MOD = 998244353;

vector <ll> fact(200001);

ll binp(ll a, ll p) {
	if (p == 0) return 1;
	if (p % 2) return a * binp(a, p - 1) % MOD;
	ll x = binp(a, p / 2);
	return (x * x) % MOD;
}

ll cnk(ll n, ll k) {
	ll ans = 1;
	ans = ans * fact[n] % MOD;
	ans = ans * binp(fact[n - k], MOD - 2) % MOD;
	ans = ans * binp(fact[k], MOD - 2) % MOD;
	return ans;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i <= 200000; i++)
		fact[i] = i * fact[i - 1] % MOD;
	ll n, k;
	cin >> n >> k;
	if (k >= n) {
		cout << 0;
		return 0;
	}
	if (k == 0) {
		ll ans = 1;
		for (int i = 2; i <= n; i++)
			ans = ans * i % MOD;
		cout << ans;
		return 0;
	}
	ll c = n - k;
	ll ans = cnk(n, c);
	ll sum = 0;
	for (int i = 0; i <= c; i++) 
		sum = (sum + binp(-1, i) * cnk(c, i) % MOD * binp(c - i, n) % MOD) % MOD;
	ans = ans * sum % MOD * 2 % MOD;
	cout << (ans + MOD) % MOD;
	return 0;
}