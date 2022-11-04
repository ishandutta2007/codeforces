#include <bits/stdc++.h>
typedef __int128 ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	int t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		long long nc, ac, bc;
		bool f = false;
		cin >> nc >> ac >> bc;
		ll n = nc, a = ac, b = bc;
		if (a == 1) {
			if ((n-1) % b == 0) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			ll p = 1;
			while (p <= n) {
				if (((n - p) % b) == 0) {
					f = true;
					cout << "Yes\n";
					break;
				}
				p *= a;
			}
			if (!f) {
				cout << "No\n";
			}
		}
	}
}