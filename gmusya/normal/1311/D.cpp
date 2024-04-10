#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

const ll MAX = 10000;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll a, b, c;
		cin >> a >> b >> c;
		ll ans_a = 1, ans_b = 1, ans_c = 1;
		ll s = a + b + c - 3;
		for (ll x = 1; x <= 10000; x++)
			for (ll y = x; y <= 20000; y += x) {
				ll z1, z2;
				z1 = c / y * y;
				if (z1 == 0)
					z1 = y;
				z2 = c / y * y + y;
				if (abs(a - x) + abs(b - y) + min(abs(c - z1), abs(c - z2)) < s) {
					s = abs(a - x) + abs(b - y) + min(abs(c - z1), abs(c - z2));
					ans_a = x;
					ans_b = y;
					if (abs(c - z1) < abs(c - z2))
						ans_c = z1;
					else
						ans_c = z2;
				}
			}
		cout << s << endl;
		cout << ans_a << " " << ans_b << " " << ans_c << endl;
	}
	return 0;
}