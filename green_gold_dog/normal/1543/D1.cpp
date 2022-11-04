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
		ll n, k, uk = 0;
		cin >> n >> k;
		for (ll i = 0; i < n; i++) {
			cout << (i^uk) << endl;
			ll ans;
			cin >> ans;
			if (ans) {
				break;
			}
			uk = uk^(i^uk);
		}
	}
}