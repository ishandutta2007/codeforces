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
	vector<ll> v(N);
	ll i;
	for (i = 0; i < N; i++) cin >> v[i];
	if (N == 1) {
		cout << 0 << ln;
		return;
	}
	ll mx = v[0];
	ll c = 0;
	for (i = 1; i < N; i++) {
		c = max(c, mx - v[i]);
		mx = max(mx, v[i]);
	}
	if (c == 0) {
		cout << 0 << ln;
		return;
	}
	for (i = 1; i <= 100; i++) {
		if ((1 << (i)) - 1 >= c) {
			cout << i << ln;
			return;
		}
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