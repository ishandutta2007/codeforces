#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll n, p, w, d;
	cin >> n >> p >> w >> d;
	for (ll y = 0; y < w; y++) {
		ll s = p - y * d;
		if (s % w) continue;
		if (s < 0) continue;
		ll x = s / w;
		ll z = n - (x + y);
		if (z >= 0) {
			cout << x << " " << y << " " << z;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}