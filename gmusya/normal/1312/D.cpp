#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll gcd(ll a, ll b, ll &x, ll &y) {
	if (a % b == 0) {
		x = 1;
		y = 1 - (a / b);
		return b;
	}
	ll x1, y1;
	ll g = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

const ll MOD = 998244353;
const ll MAXN = 200002;
vector <ll> fact(MAXN, 1), _fact(MAXN, 1);

ll cnk(ll N, ll K) {
	return (((fact[N] * _fact[N - K]) % MOD) * _fact[K]) % MOD;
}

int main() {
	for (ll i = 2; i < MAXN; i++)
		fact[i] = (fact[i - 1] * i) % MOD;
	ll k, l;
	ll g = gcd(fact[MAXN - 1], MOD, k, l);
	_fact[MAXN - 1] = (k % MOD + MOD) % MOD;
	for (ll i = MAXN - 2; i >= 0; i--)
		_fact[i] = (_fact[i + 1] * (i + 1)) % MOD;
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	vector <ll> p2(MAXN, 1);
	for (ll i = 1; i < MAXN; i++)
		p2[i] = (p2[i - 1] * 2) % MOD;
	if (n == 2) {
		cout << "0";
		return 0;
	}
	for (ll i = n - 1; i <= m; i++) {
		ll kek = cnk(i - 1, n - 2);
		kek = (kek * (n - 2)) % MOD;
		kek = (kek * (p2[n - 3])) % MOD;
		ans = (ans + kek) % MOD;
	}
	cout << ans;
	return 0;
}