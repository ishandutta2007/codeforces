/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'

#define MAX 101010
#define MOD 1000000007

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var
ll notprime[MAX];
//

ll fact(ll x) {
	ll ans = 1;
	ll i;
	for (i = 1; i <= x; i++) {
		ans *= i;
		ans %= MOD;
	}
	return ans;
}

void solve() {
	ll N, X, pos;
	cin >> N >> X >> pos;
	ll l, r;
	l = 0, r = N;
	ll mid;
	ll cnt1, cnt2;
	cnt1 = cnt2 = 0;
	while (l < r) {
		mid = (l + r) / 2;
		if (mid <= pos) cnt1++, l = mid + 1;
		else cnt2++, r = mid;
	}
	cnt1--;
	ll big, small;
	big = N - X;
	small = X - 1;
	ll ans = 1;
	if (big < cnt2 || small < cnt1) ans = 0;
	ll rr = N - 1 - cnt1 - cnt2;
	ans = fact(rr);
	ll i;
	for (i = big; i >= big - cnt2 + 1; i--) {
		ans *= i;
		ans %= MOD;
	}
	for (i = small; i >= small - cnt1 + 1; i--) {
		ans *= i;
		ans %= MOD;
	}
	cout << ans << ln;
}

void init() {
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}