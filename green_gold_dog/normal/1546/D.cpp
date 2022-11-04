#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll bin_pow(ll a, ll p, const ll m) {
	if (p == 0) {
		return 1;
	}
	if (p % 2 == 1) {
		return bin_pow(a, p-1, m)*a%m;
	}
	ll now = bin_pow(a, p/2, m);
	return now*now%m;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll mod = 998244353;
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n, nold;
		cin >> n;
		nold = n;
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		string s;
		cin >> s;
		ll col = 0, co = 0;
		ll ans = 1;
		for (ll i = 0; i < n;) {
			if (s[i] == '1' && (i+1 != n ? s[i+1] : '0') == '1') {
				col++;
				i++;
			} else {
				if (s[i] == '1') {
					co++;
				}
			}
			i++;
		}
		n -= co+col*2;
		for (ll i = 0; i < col; i++) {
			ans = (ans*(n+1));
			n++;
			ans = ans%mod;
		}
		for (ll i = 1; i <= col; i++) {
			ans = ans*bin_pow(i, mod-2, mod)%mod;
		}
		cout << ans << '\n';
	}
}