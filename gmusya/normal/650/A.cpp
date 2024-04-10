#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define ll long long

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <pair <ll, ll>> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());
	vector <pair <pair <ll, ll>, ll>> b;
	pair <ll, ll> cur = a[0];
	ll cnt = 1;
	for (ll i = 1; i < n; i++) {
		if (a[i] != cur) {
			b.push_back({ cur, cnt });
			cur = a[i];
			cnt = 0;
		}
		cnt++;
	}
	b.push_back({ cur, cnt });
	unordered_map <ll, ll> x, y;
	ll ans = 0;
	for (ll i = 0; i < b.size(); i++) {
		ans += x[b[i].first.first] * b[i].second;
		ans += y[b[i].first.second] * b[i].second;
		ans += b[i].second * (b[i].second - 1) / 2;
		x[b[i].first.first] += b[i].second;
		y[b[i].first.second] += b[i].second;
	}
	cout << ans;
	return 0;
}