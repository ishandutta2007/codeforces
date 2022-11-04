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
		if (n % 2 == 0) {
			cout << 2 << ' ' << n/2 << '\n';
		} else {
			cout << 2 << ' ' << n-1 << '\n';
		}
	}
}