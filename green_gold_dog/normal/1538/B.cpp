#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 0; iii < t; iii++) {
		ll n, sum = 0;
		cin >> n;
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		if (sum % n != 0) {
			cout << -1 << '\n';
		} else {
			ll b = sum/n;
			ll ans = 0;
			for (auto i : arr) {
				if (i > b) {
					ans++;
				}
			}
			cout << ans << '\n';
		}
	}
}