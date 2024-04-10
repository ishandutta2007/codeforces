#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long 

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll a, b, c, rad;
		cin >> a >> b >> c >> rad;
		if (a > b)
			swap(a, b);
		ll l = max(c - rad, a);
		ll r = min(rad + c, b);
		if (l > b || r < a) {
			l = 0;
			r = 0;
		}
		cout << b - a - max((ll)0, r - l) << endl;
	}
	return 0;
}