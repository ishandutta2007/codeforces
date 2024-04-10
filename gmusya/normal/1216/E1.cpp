#include <iostream>
#include <vector>

#define ll long long 
using namespace std;

ll num_of_digits(ll n) {
	if (n < 10)
		return 1;
	if (n < 100)
		return 2;
	if (n < 1000)
		return 3;
	if (n < 10000)
		return 4;
	if (n < 100000)
		return 5;
}

int main() {
	ll n = 17, r = 100000;
	vector <ll> a(n), b(n), c(r), sumx(r);
	c[0] = 1;
	for (ll i = 1; i < r; i++)
		c[i] = c[i - 1] + num_of_digits(i + 1);
	sumx[0] = c[0];
	for (ll i = 1; i < r; i++)
		sumx[i] = sumx[i - 1] + c[i];
	a[0] = 9;
	for (ll i = 1; i < n; i++)
		a[i] = 10 * a[i - 1] / i * (i + 1);
	ll cn = 1;
	for (ll i = 0; i < n; i++) {
		b[i] = 9 * cn;
		cn *= 10;
	}
	vector <ll> sum(n);
	sum[0] = b[0];
	for (ll i = 1; i < n; i++)
		sum[i] = sum[i - 1] + b[i];
	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;
		if (x == 1)
			cout << 1 << endl;
		else {
		ll l = 0;
		ll hm = r - 1;
		while (l != hm) {
			ll m = (l + hm) / 2;
			if (sumx[m] >= x)
				hm = m;
			else
				l = m + 1;
		}
		if (sumx[l] >= x)
			l--;
		x -= sumx[l];
		if (x >= 1 && x < 10) {
			cout << x << endl;
		}
		else {
			ll i = 0;
			while (x > a[i]) {
				x -= a[i];
				i++;
			}
			ll u = (x + i) / (i + 1) + sum[i - 1];
			ll pos = x % (i + 1);
			if (pos == 0)
				pos = (i + 1);
			pos = i + 1 - pos;
			while (pos > 0) {
				u /= 10;
				pos--;
			}
			cout << u % 10 << endl;
		}
		}
	}
	return 0;
}