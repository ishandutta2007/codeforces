#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, k, z;
		cin >> n >> k >> z;
		vector <ll> a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		ll ans = 0;
		for (ll le = 0; le <= z; le++) {
			ll sum = 0;
			ll last = (k - 2 * le);
			if (last < 0 || last >= n) continue;
			for (ll i = 0; i <= last; i++)
				sum += a[i];
			ll ma = 0;
			for (ll i = 0; i <= min(n - 2, last); i++)
				ma = max(ma, a[i] + a[i + 1]);
			sum += ma * le;
			ans = max(ans, sum);
		}
		cout << ans << '\n';
	}
	return 0;
}