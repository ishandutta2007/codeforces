#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;
	vector <ll> a(n), b(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll ans = 1e12;
	for (ll i = 0; i < n; i++) {
		bool tf = true;
		ll x = (b[0] - a[i] + m) % m;
		for (ll j = 0; j < n; j++)
			if ((b[j] - a[(j + i) % n] + m) % m != x)
				tf = false;
		if (tf)
			ans = min(ans, x);
	}
	cout << ans;
	return 0;
}