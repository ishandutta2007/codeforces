#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll check(vector<pair<ll, ll>>& arr, ll n) {
	vector<ll> now;
	for (auto[l, r] : arr) {
		now.push_back(l+r*n);
	}
	sort(now.begin(), now.end());
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ans += now[i];
	}
	return ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, s;
	cin >> n >> s;
	vector<pair<ll, ll>> arr(n, {0, 0});
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i+1;
	}
	ll l = 0, r = n+1;
	while (r - l > 1) {
		ll mid = (l+r)/2;
		if (check(arr, mid) <= s) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << ' ' << check(arr, l);
}