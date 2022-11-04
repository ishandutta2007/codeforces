#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll ans = 0, n;
	cin >> n;
	vector<pair<ll, ll>> arr(n, {0, 0});
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr.begin(), arr.end());
	ll now = 0;
	for (ll i = 0; i < n; i++) {
		while ((i < n) && (now < arr[i].first)) {
			if (arr.back().second + now < arr[i].first) {
				ans += arr.back().second*2;
				now += arr.back().second;
				arr.pop_back();
				n--;
			} else {
				ans += (arr[i].first-now)*2;
				arr.back().second -= (arr[i].first-now);
				now = arr[i].first;
			}
		}
		if (i < n) {
			ans += arr[i].second;
			now += arr[i].second;
		}
	}
	cout << ans;
}