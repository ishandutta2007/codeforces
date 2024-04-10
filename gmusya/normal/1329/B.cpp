#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll d, m;
		cin >> d >> m;
		ll x = 1, delta = 1, ans = 1;
		while (x <= d) {
			if (x == d) {
				cout << ans % m << endl;
				break;
			}
			ll newx = x * 2 - 1;
			if (newx >= d) {
				cout << ((ans + (d - x) * delta) % m + m) % m << endl;
				break;
			}
			ans = ((ans + (newx - x) * delta) % m + m) % m;
			x = newx + 1;
			delta = (ans + 1) % m;
			ans = (2 * ans + 1) % m;
		}
	}
	return 0;
}