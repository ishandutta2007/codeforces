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
#define Ln '\n'

#define MAX 101010
#define MOD 998244353
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

void solve() {
	ll N;
	cin >> N;
	vector<ll> v(N);
	ll i;
	ll mx = 0;
	for (i = 0; i < N; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	ll cnt = 0;
	ll mmx = -1;
	for (i = 0; i < N; i++) {
		if (v[i] == mx) cnt++;
		else mmx = max(mmx, v[i]);
	}
	ll ans = 1;
	ll ccnt = 0;
	for (i = 0; i < N; i++) {
		if (mmx == v[i]) ccnt++;
	}
	if (cnt >= 2) {
		for (i = 1; i <= N; i++) {
			ans *= i;
			ans %= MOD;
		}
		cout << ans << ln;
	}
	else {
		if (mx - mmx >= 2) {
			cout << 0 << ln;
			return;
		}
		for (i = 1; i <= N; i++) {
			ans *= i;
			ans %= MOD;
		}
		ans %= MOD;
		ll aa = ans;
		while (aa % (ccnt + 1)) aa += MOD;
		aa /= (ccnt + 1);
		ans -= aa;
		if (ans < 0) ans += MOD;
		cout << ans << ln;
	}
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}