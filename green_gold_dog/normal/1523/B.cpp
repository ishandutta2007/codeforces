#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 0; iii < t; iii++) {
		ll n;
		cin >> n;
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << n*3 << '\n';
		for (ll i = 0; i < n; i += 2) {
			for (ll j = 0; j < 3; j++) {
				cout << 2 << ' ' << i+1 << ' ' << i+2 << '\n';
				cout << 1 << ' ' << i+1 << ' ' << i+2 << '\n';
			}
		}
	}
}