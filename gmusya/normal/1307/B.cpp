#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, x;
		cin >> n >> x;
		vector <ll> a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		ll ans = 0;
		for (ll i = 0; i < n; i++)
			if (a[i] == x)
				ans = 1;
		if (ans == 1) {
			cout << 1 << endl;
			continue;
		}
		cout << max((ll) 2, (x + a[n - 1] - 1) / a[n - 1]) << endl;
	}
	return 0;
}