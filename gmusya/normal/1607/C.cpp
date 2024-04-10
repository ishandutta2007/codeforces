#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		if (n == 1) {
			cout << a[0] << '\n';
			continue;
		}
		sort(a.begin(), a.end());
		ll ans = a[0];
		ll val = 0;
		for (int i = 0; i + 1 < n; ++i) {
			val += a[i] - val;
			ans = max(ans, a[i + 1] - val);
		}
		cout << ans << '\n';
	}
	return 0;
}