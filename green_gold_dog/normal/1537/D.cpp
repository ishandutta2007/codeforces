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
		ll n, nn;
		cin >> n;
		nn = n;
		ll count = 0;
		while (nn % 2 == 0) {
			count++;
			nn /= 2;
		}
		if ((nn == 1) && (count % 2 == 0) && (n != 1)) {
			cout << "Alice" << '\n';
		} else {
			if (nn == 1) {
				cout << "Bob" << '\n';
			} else {
				cout << ((n % 2 == 0) ? "Alice" : "Bob") << '\n';
			}
		}
	}
}