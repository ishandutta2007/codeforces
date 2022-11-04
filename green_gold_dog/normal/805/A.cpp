#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll power(ll a, ll p, ll m) {
	if (p == 1) {
		return a % m;
	}
	if (p % 2 == 0) {
		ll ans = power(a, p/2, m);
		return ans*ans%m;
	} else {
		return power(a, p-1, m)*a%m;
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll l, r;
	cin >> l >> r;
	if (r - l >= 2) {
		cout << 2;
		return 0;
	} else {
		for (ll i = 2; i*i < l; i++) {
			if (l % i == 0) {
				cout << i;
				return 0;
			}
		}
		cout << l;
	}
}