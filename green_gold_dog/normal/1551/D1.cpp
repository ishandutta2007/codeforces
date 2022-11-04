#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n, m, k;
		cin >> n >> m >> k;
		if (m % 2 == 1) {
			cout << ((k % 2 == 0) && (n*(m/2) >= k) ? "YES" : "NO") << '\n';
		} else {
			if (n % 2 == 1) {
				cout << ((k - m/2 >= 0) && ((k - m/2) % 2 == 0) ? "YES" : "NO") << '\n';
			} else {
				cout << (k % 2 == 0 ? "YES" : "NO") << '\n';
			}
		}
	}
}