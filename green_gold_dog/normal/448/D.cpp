#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll calc(ll mid, ll n, ll m) {
	ll ans = 0;
	for (ll i = 1; i <= m; i++) {
		ans += min(n, mid/i);
	}
	return ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	ll l = 0, r = n*m;
	while (r - l > 1) {
		ll mid = (l+r)/2;
		if (calc(mid, n, m) >= k) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r;
}