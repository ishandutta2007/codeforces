#include <iostream>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll x, n;
		cin >> x >> n;
		if (x % 2 == 0) {
			if (n % 4 == 1) {
				x -= n;
			} else if (n % 4 == 2) {
				++x;
			} else if (n % 4 == 3) {
				x += n + 1;
			}
		} else {
			if (n % 4 == 1) {
				x += n;
			} else if (n % 4 == 2) {
				--x;
			} else if (n % 4 == 3) {
				x -= n + 1;
			}
		}
		cout << x << '\n';
	}
	return 0;
}