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
		ll n;
		cin >> n;
		if (n % 3 == 0) {
			cout << n/3 << ' ' << n/3 << '\n';
		}
		if (n % 3 == 1) {
			cout << n/3+1 << ' ' << n/3 << '\n';
		}
		if (n % 3 == 2) {
			cout << n/3 << ' ' << n/3+1 << '\n';
		}
	}
}