#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return gcd(max(a, b)%min(a, b), min(a, b));
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 0; iii < t; iii++) {
		ll n;
		cin >> n;
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			for (ll j = i+1; j < n; j++) {
				if (gcd(arr[i], arr[j]) != 1) {
					ans++;
				} else {
					if ((arr[j] % 2 == 0) || (arr[i] % 2 == 0)) {
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}