#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}
		vector<ll> x(n), y(n);
		ll bal = 0;
		for (int i = 0; i < n; ++i) {
			bal += a[i] - b[i];
		}
		for (int i = 0; i < n; ++i) {
			ll right = min(m, b[i]);
			ll left = m - right;
			bal += right - left;
		}
		for (int i = 0; i < n; ++i) {
			ll right = min(m, b[i]);
			ll left = m - right;
			if (bal > 0) {
				ll to_add = min({right, bal / 2, a[i] - left});
				bal -= 2 * to_add;
				y[i] = right - to_add;
				x[i] = m - y[i];
			} else {
				y[i] = right;
				x[i] = m - y[i];
			}
		}
		cout << abs(bal) << '\n';
		for (int i = 0; i < n; ++i) {
			cout << x[i] << ' ' << y[i] << '\n';
		}
	}
	return 0;
}