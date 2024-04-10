#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <ll> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		ll ans = 0, mi = INF;
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				ll val = min(a[0], b[i]);
				ans += a[0] - val;
				mi = min(mi, val);
			}
			else {
				ll val = min(a[i + 1], b[i]);
				ans += a[i + 1] - val;
				mi = min(mi, val);
			}
		}
		cout << ans + mi << '\n';
	}
	return 0;
}