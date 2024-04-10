#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll INF = 1e18;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		ll k;
		cin >> n >> k;
		ll l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		ll x = min(r1, r2) - max(l1, l2);
		if (x < 0) x = 0;
		k -= x * n;
		if (k <= 0) {
			cout << 0 << '\n';
			continue;
		}
		ll cost = max(l2 - r1, l1 - r2);
		if (cost < 0) cost = 0;
		ll ans = INF;
		ll len = max(r2, r1) - min(l1, l2) - x;
		for (ll i = 1; i <= n; i++) {
			ll sum = 0;
			sum += cost * i;
			ll tmpk = k;
			tmpk -= i * len;
			sum += i * len;
			if (tmpk <= 0) {
				sum += tmpk;
				ans = min(sum, ans);
				continue;
			}
			sum += 2 * tmpk;
			ans = min(sum, ans);
		}
		cout << ans << '\n';
	}
	return 0;
}