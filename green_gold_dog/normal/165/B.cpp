#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool check (ll n, ll k, ll x) {
	ll ans = 0, d = 1;
	while (n / d >= 1) {
		ans += n/d;
		d *= k;
	}
	return ans >= x;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll l = 0, r = n+1;
	while (r - l > 1) {
		ll mid = (l+r)/2;
		if (check(mid, k, n)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r;
}