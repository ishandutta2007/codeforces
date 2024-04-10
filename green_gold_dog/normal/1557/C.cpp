#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll binpow(ll n, ll s, ll mod) {
	if (s == 0) {
		return 1;
	}
	if (s % 2 == 1) {
		return binpow(n, s-1, mod)*n%mod;
	} else {
		ll ans = binpow(n, s/2, mod);
		return ans*ans%mod;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	const ll mod = 1'000'000'007;
	ll t;
	cin >> t;
	ll ma = 3'000'00;
	vector<ll> fact(ma, 1);
	for (ll i = 1; i < ma; i++) {
		fact[i] = fact[i-1]*i%mod;
	}
	for (ll _ = 0; _ < t; _++) {
		ll n, k;
		cin >> n >> k;
		ll sum = 0;
		for (ll i = 0; i <= n; i += 2) {
			sum += fact[n]*binpow(fact[n-i], mod-2, mod)%mod*binpow(fact[i], mod-2, mod)%mod;
			sum = sum%mod;
		}
		ll a = 0, ans = 1;
		if (n % 2 == 0) {
			for (ll i = 0; i < k; i++) {
				a += ans*binpow(2, n*(k-i-1), mod)%mod;
				ans *= sum-1;
				ans = ans%mod;
				a = a % mod;
			}
			a += binpow(sum-1, k, mod);
			a = a%mod;
		} else {
			a = binpow(sum+1, k, mod);
		}
		if (a == 0) {
			a = 1;
		}
		cout << a << '\n';
	}
}