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
		set<ll> all;
		vector<pair<ll, ll>> arr(k, {0, 0});
		for (ll i = 0; i < k; i++) {
			cin >> arr[i].first >> arr[i].second;
			arr[i].first--;
			arr[i].second--;
			all.insert(arr[i].first);
			all.insert(arr[i].second);
		}
		for (ll i = 0; i < (n*2); i++) {
			if (all.find(i) == all.end()) {
				ll ost = n-k, now = i;
				while (ost > 0) {
					now = (now+1)%(n*2);
					if (all.find(now) == all.end()) {
						ost--;
					}
				}
				arr.push_back({i, now});
			}
		}
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				if (i != j) {
					if (((arr[i].first > arr[j].first)+(arr[i].first > arr[j].second)+(arr[i].second > arr[j].first)+(arr[i].second > arr[j].second)) == 3) {
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}