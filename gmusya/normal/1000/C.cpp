#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <pair <ll, ll>> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	vector <pair <ll, ll>> b;
	for (ll i = 0; i < n; i++) {
		b.push_back({ a[i].first, -1 });
		b.push_back({ a[i].second + 1, 1 });
	}
	sort(b.begin(), b.end());

	ll bal = 0;
	vector <ll> ans(n + 1);
	for (ll i = 0; i < 2 * n; i++) {
		if (bal > 0)
			ans[bal] += b[i].first - b[i - 1].first;
		bal -= (b[i].second);
	}
	for (ll i = 1; i <= n; i++)
		cout << ans[i] << " ";
	return 0;
}