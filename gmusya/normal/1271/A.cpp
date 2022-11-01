#include <iostream>
#include <algorithm>

#define ll long long 
using namespace std;

int main() {
	ll a, b, c, d, e, f, cnt = 0;
	cin >> a >> b >> c >> d >> e >> f;
	if (f > e) {
		ll x = min(min(b, c), d);
		cnt += x * f;
		b -= x;
		c -= x;
		d -= x;
		cnt += min(a, d) * e;
	}
	else {
		ll x = min(a, d);
		cnt += x * e;
		a -= x;
		d -= x;
		cnt += min(min(b, c), d) * f;
	}
	cout << cnt << endl;
	return 0;
}