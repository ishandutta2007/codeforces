#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector <ll> diff(n - 1);
	for (ll i = 0; i < n - 1; i++)
		diff[i] = abs(a[i] - a[i + 1]);
	vector <ll> p(n - 1), m(n - 1);
	for (ll i = 0; i < n - 1; i++) {
		if (i % 2 == 0)
			p[i] = diff[i];
		else
			p[i] = -diff[i];
	}
	for (ll i = 0; i < n - 1; i++)
		m[i] = -p[i];
	ll ans = 0;
	ll cur = 0;
	for (ll i = 0; i < n - 1; i++) {
		cur += p[i];
		ans = max(ans, cur);
		if (cur < 0)
			cur = 0;
	}
	cur = 0;
	for (ll i = 0; i < n - 1; i++) {
		cur += m[i];
		ans = max(ans, cur);
		if (cur < 0)
			cur = 0;
	}
	cout << ans;
	return 0;
}