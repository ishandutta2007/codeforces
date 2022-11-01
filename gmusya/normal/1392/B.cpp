#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		k %= 2;
		k += 2;
		vector <ll> a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		while (k--) {
			ll mx = -1e9 - 1;
			for (ll i = 0; i < n; i++)
				if (mx < a[i])
					mx = a[i];
			for (ll i = 0; i < n; i++)
				a[i] = mx - a[i];
		}
		for (auto &now : a)
			cout << now << ' ';
		cout << '\n';
	}
	return 0;
}