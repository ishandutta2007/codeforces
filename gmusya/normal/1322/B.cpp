#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll ans = 0;
	for (ll M = 2; M < 4e7; M *= 2) {
		vector <ll> b(n);
		for (ll i = 0; i < n; i++)
			b[i] = a[i] % M;
		ll cnt = 0;
		sort(b.begin(), b.end());
		for (ll i = 1; i < n; i++) {
			cnt += upper_bound(b.begin(), b.begin() + i, M - 1 - b[i]) - lower_bound(b.begin(), b.begin() + i, M / 2 - b[i]);
			cnt += upper_bound(b.begin(), b.begin() + i, 2 * M - 1 - b[i]) - lower_bound(b.begin(), b.begin() + i, M + M / 2 - b[i]);
		}
		ans += (M / 2) * (cnt % 2);
	}
	cout << ans;
	return 0;
}