#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--){
		ll n, k;
		cin >> n >> k;
		vector <ll> a(n);
		bool tf = true;
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		for (ll it = 0; it < 64; it++) {
			ll cnt = 0;
			for (ll i = 0; i < n; i++) {
				cnt += (a[i] % k);
				a[i] /= k;
			}
			if (cnt >= 2)
				tf = false;
		}
		if (tf) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}