#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll n, k1, k2, k;
	cin >> n >> k1 >> k2;
	k = k1 + k2;
	vector <ll> a(n), b(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++)
		cin >> b[i];
	vector <ll> c(n);
	for (ll i = 0; i < n; i++)
		c[i] = abs(a[i] - b[i]);
	ll sum = 0;
	for (ll i = 0; i < n; i++)
		sum += c[i];
	if (sum <= k) {
		if ((k - sum) % 2)
			cout << "1";
		else
			cout << "0";
		return 0;
	}
	while (k > 0) {
		ll ma_id = 0;
		for (ll i = 0; i < n; i++) {
			if (c[i] > c[ma_id])
				ma_id = i;
		}
		c[ma_id]--;
		k--;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		ans += c[i] * c[i];
	cout << ans;
	return 0;
}