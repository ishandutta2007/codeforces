#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
ll check(vector<ll>& arr, ll k) {
	ll ans = 0;
	for (ll i = 1; i < arr.size(); i++) {
		ans = max(ans, abs((arr[i] == -1 ? k : arr[i]) - (arr[i-1] == -1 ? k : arr[i-1])));
	}
	return ans;
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
		ll l = 0, r = 1000000000;
		for (ll i = 0; i < 100; i++) {
			ll m1 = l+(r-l)/3, m2 = l+(r-l)/3*2;
			if (check(arr, m1) >= check(arr, m2)) {
				l = m1;
			} else {
				r = m2;
			}
		}
		pair<ll, ll> ans = {100000000000, 100000000000};
		for (ll i = l; i <= r; i++) {
			ans = min(ans, {check(arr, i), i});
		}
		cout << ans.first << ' ' << ans.second << endl;
	}
}