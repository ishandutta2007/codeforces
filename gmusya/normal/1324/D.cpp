#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <ll> a(n), b(n), c(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++)
		cin >> b[i];
	for (ll i = 0; i < n; i++)
		c[i] = (a[i] - b[i]);
	sort(c.begin(), c.end());
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		ans += upper_bound(c.begin(), c.begin() + i, 1e9 + 1) - lower_bound(c.begin(), c.begin() + i, 1 - c[i]);
	cout << ans;
	return 0;
}