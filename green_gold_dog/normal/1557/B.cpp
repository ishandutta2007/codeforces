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
		ll n, k;
		cin >> n >> k;
		vector<pair<ll, ll>> arr(n, {0, 0});
		for (ll i = 0; i < n; i++) {
			cin >> arr[i].first;
			arr[i].second = i;
		}
		ll cnt = 1;
		sort(arr.begin(), arr.end());
		for (ll i = 1; i < n; i++) {
			if (arr[i].second-1 != arr[i-1].second) {
				cnt++;
			}
		}
		cout << (k >= cnt ? "Yes" : "No") << '\n';
	}
}