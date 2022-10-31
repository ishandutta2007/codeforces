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
#define MOD 100000009
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
	ll i;
	vector<ll> v(N + 1);
	ll sum = 0;
	for (i = 1; i <= N; i++) cin >> v[i], sum += v[i];
	sort(v.begin() + 1, v.end());
	ll M;
	cin >> M;
	for (i = 1; i <= M; i++) {
		ll x, y;
		cin >> x >> y;
		ll ans = 0;
		ll ind = lower_bound(v.begin(), v.end(), x) - v.begin();
		if (ind > N) ind = N;
		if (x > v[ind]) ans += x - v[ind];
		ans += max(0LL, y - (sum - v[ind]));
		ll ans2 = 0;
		ind--;
		if (ind >= 1) {
			if (ind > N) ind = N;
			if (x > v[ind]) ans2 += x - v[ind];
			ans2 += max(0LL, y - (sum - v[ind]));
			ans = min(ans, ans2);
		}
		cout << ans << ln;
	}
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