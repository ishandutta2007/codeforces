#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n;
		cin >> n;
		ll c = 0;
		for (ll i = 0; i < n*2; i++) {
			ll x;
			cin >> x;
			if (x % 2 == 0) {
				c++;
			}
		}
		cout << ((n == c) ? "Yes" : "No") << '\n';
	}
}