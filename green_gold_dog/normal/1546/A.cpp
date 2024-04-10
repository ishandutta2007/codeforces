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
		vector<ll> a(n, 0), b(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (ll i = 0; i < n; i++) {
			cin >> b[i];
		}
		ll r = 0;
		for (ll i = 0; i < n; i++) {
			r += b[i]-a[i];
		}
		if (r != 0) {
			cout << -1 << '\n';
			continue;
		}
		vector<ll> first, second;
		for (ll i = 0; i < n; i++) {
			if (b[i] > a[i]) {
				first.push_back(i);
			} 
		        if (b[i] < a[i]) {
				second.push_back(i);
			}
		}
		vector<pair<ll, ll>> ans;
		while (!first.empty()) {
			ans.push_back({second.back(), first.back()});
			a[first.back()]++;
			a[second.back()]--;
			if (a[first.back()] == b[first.back()]) {
				first.pop_back();
			}
			if (a[second.back()] == b[second.back()]) {
				second.pop_back();
			}
		}
		cout << ans.size() << '\n';
		for (auto[l, r] : ans) {
			cout << l+1 << ' ' << r+1 << '\n';
		}
	}
}