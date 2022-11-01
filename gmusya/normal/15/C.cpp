#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	ll x = 0;
	vector <ll> p2(63);
	p2[0] = 1;
	for (ll i = 1; i < 63; i++)
		p2[i] = 2 * p2[i - 1];
	ll n;
	cin >> n;
	vector <pair <ll, ll>> a(n);
	for (ll i = 0; i < n; i++) {
    ll x, m;
    cin >> x >> m;
		a[i] = {x, x + m - 1};
  }
	vector <ll> b(63);
	for (ll i = 0; i < n; i++) {
		ll l = a[i].first - 1;
		ll r = a[i].second;
		ll k = 0;
		if (l % 4 == 1 || l % 4 == 2)
			x ^= 1;
		if (l > 0) {
			for (ll j = 2; j < 63; j++) {
				ll z = l % p2[j];
				if (z < p2[j - 1])
					continue;
				z -= p2[j - 1] - 1;
				if (z % 2)
					x ^= p2[j - 1];
			}
		}
		if (r % 4 == 1 || r % 4 == 2)
			x ^= 1;
		for (ll j = 2; j < 63; j++) {
			ll z = r % p2[j];
			if (z < p2[j - 1])
				continue;
			z -= p2[j - 1] - 1;
			if (z % 2)
				x ^= p2[j - 1];
		}
	}
	if (x == 0)
		cout << "bolik";
  else
	  cout << "tolik";
	return 0;
}