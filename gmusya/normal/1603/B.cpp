#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		if (x == y) {
			cout << x << '\n';
			continue;
		}
		if (x > y) {
			cout << x + y << '\n';
			continue;
		}
		if (y % x == 0) {
			cout << x << '\n';
			continue;
		}
		if (2 * x >= y) {
			cout << (x + y) / 2 << '\n';
			continue;
		}
		ll res = y - (x + y % x) / 2;
		cout << res << '\n';
	}
	return 0;
}