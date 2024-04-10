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
		ll n, l, r;
		cin >> n >> l >> r;
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			ll n1 = lower_bound(arr.begin(), arr.end(), l-arr[i])-arr.begin(), n2 = upper_bound(arr.begin(), arr.end(), r-arr[i])-arr.begin();
			ans += n2 - n1;
			if ((i >= n1) && (i < n2)) {
				ans--;
			}
		}
		cout << ans/2 << '\n';
	}
}