#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
	if (a == 0 || b == 0)
		return max(a, b);
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}
int main() {
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll ma = a[0];
	for (ll i = 0; i < n; i++)
		ma = max(ma, a[i]);
	vector <ll> b(n);
	for (ll i = 0; i < n; i++)
		b[i] = ma - a[i];
	vector <ll> c(n);
	c[0] = b[0];
	ll cnt = 0;
	for (ll i = 1; i < n; i++)
		c[i] = gcd(b[i], c[i - 1]);
	for (ll i = 0; i < n; i++)
		cnt += b[i] / c[n - 1];
	cout << cnt << " " << c[n - 1];
	return 0;
}