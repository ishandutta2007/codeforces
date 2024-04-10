#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll modpow(ll a, ll b, ll m = MOD) {
	a %= m;
	ll r = 1;
	while(b) {
		if(b & 1) r *= a, r %= m;
		a *= a, a %= m;
		b >>= 1;
	}
	return r % m;
}

ll go(ll p, ll k) {
	if(k == 0) {
		// k = 0: condition is f(0) = 0
		// (p)^(p-1)
		return modpow(p, p-1);
	} else if(k == 1) {
		return modpow(p, p);
	} else {
		// f(0) = 0
		// the rest are partititoned into cycles
		ll deg = 1;
		ll tmp = k;
		while(tmp != 1) deg++, tmp *= k, tmp %= p;
		assert((p - 1) % deg == 0);
		return modpow(p, (p - 1) / deg);
	}
}

int main() {
	ll p, k;
	cin >> p >> k;
	cout << go(p, k) % MOD << '\n';
	return 0;
}