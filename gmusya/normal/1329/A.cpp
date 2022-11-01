#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	vector <pair <ll, ll>> a(m);
	vector <ll> c(n);
	for (ll i = 0; i < m; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	ll sum = 0;
	for (ll i = 0; i < m; i++) sum += a[i].first;
	if (sum < n) {
		cout << -1;
		return 0;
	}
	vector <ll> ans(m);
	ll cur_pos = 0;
	for (ll i = 0; i < m; i++) {
		if (cur_pos + a[i].first > n) {
			cout << -1;
			return 0;
		}
		ll pos = max(n - sum + 1, cur_pos + 1);
		ans[a[i].second] = pos;
		sum -= a[i].first;
		cur_pos = pos;
	}
	for (ll i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}