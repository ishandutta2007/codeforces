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
		sort(arr.begin(), arr.end());
		ll ac = 0;
		vector<pair<ll, vector<ll>>> col(1, {0, vector<ll>(0, 0)});
		for (auto[i, num] : arr) {
			if (i != col.back().first) {
				ac += min((ll)col.back().second.size(), k);
				col.push_back({i, vector<ll>(1, num)});
			} else {
				col.back().second.push_back(num);
			}
		}
		ac += min((ll)col.back().second.size(), k);
		ll last = 0;
		vector<pair<ll, ll>> ans;
		for (auto&[_, c] : col) {
			for (ll i = 0; i < min((ll)(c.size()), k); i++) {
				if (ac >= k-last) {
					ans.push_back({c[i], last+1});
				} else {
					ans.push_back({c[i], 0});
				}
				last++;
				ac--;
				last = last%k;
			}
			for (ll i = k; i < c.size(); i++) {
				ans.push_back({c[i], 0});
			}
		}
		sort(ans.begin(), ans.end());
		for (auto[_, i] : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}