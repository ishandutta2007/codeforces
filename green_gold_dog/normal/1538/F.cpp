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
		ll r, l;
		cin >> l >> r;
		ll ans = 0;
		while (r > 0) {
			ans += r-l;
			r /= 10;
			l /= 10;
		}
		cout << ans << '\n';
	}
}