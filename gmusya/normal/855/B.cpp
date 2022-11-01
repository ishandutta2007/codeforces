#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
	ll n, p, q, r;
	cin >> n >> p >> q >> r;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector <ll> b(n);
	b[0] = p * a[0];
	for (ll i = 1; i < n; i++)
		b[i] = max(b[i - 1], a[i] * p);
	vector <ll> c(n);
	c[0] = (p + q) * a[0];
	for (ll i = 1; i < n; i++)
		c[i] = max(c[i - 1], a[i] * q + b[i]);
	vector <ll> d(n);
	d[0] = (p + q + r) * a[0];
	for (ll i = 1; i < n; i++)
		d[i] = max(d[i - 1], a[i] * r + c[i]);
	cout << d[n - 1];
	return 0;
}