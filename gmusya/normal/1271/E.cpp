#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	vector <ll> p2(64);
	p2[0] = 1;
	for (ll i = 1; i < 64; i++)
		p2[i] = min((ll)1e18+1, (p2[i - 1] << 1));
	ll n, k;
	cin >> n >> k;
	ll l = 1, r = n / 2;
	bool tf1 = (l <= r);
	while (tf1) {
		ll m = (l + r) / 2;
		ll x = 2 * m;
		ll cnt = 0;
		ll p = 1;
		bool tf2 = true;
		while (tf2) {
			if (x > n) break;
			ll g = min(n, x + p2[p] - 1);
			p++;
			cnt += g - x + 1;
			x *= 2;
		}
		if (l == r) tf1 = false;
		if (cnt >= k) l = m + 1;
		else r = m;
	}
	l--;
	ll ans1 = 2 * l;
	l = 0;
	r = n / 2;
	if (n % 2 == 0) r--;
	tf1 = true;
	while (tf1) {
		ll m = (l + r) / 2;
		ll x = 2 * m + 1;
		ll cnt = 1;
		ll p = 1;
		bool tf2 = true;
		while (tf2) {
			x *= 2;
			if (x > n) break;
			ll g = min(n, x + p2[p] - 1);
			p++;
			cnt += g - x + 1;
		}
		if (l == r) tf1 = false;
		if (cnt >= k) l = m + 1;
		else r = m;
	}
	l--;
	ll ans2 = 2 * l + 1;
	cout << max(ans1, ans2);
	return 0;
}