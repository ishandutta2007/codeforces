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
	ll N, H;
	cin >> N >> H;
	ll i;
	vector<ll> v(N);
	for (i = 0; i < N; i++) cin >> v[i];
	ll x, y;
	y = x = 0;
	for (i = 0; i < N; i++) {
		if (v[i] >= x) y = x, x = v[i];
		else if (v[i] >= y) y = v[i];
	}
	ll a, b;
	if (H % (x + y)) a = 2 * (H / (x + y)) + 2;
	else a = (H / (x + y)) * 2;
	H -= x;
	if (H <= 0) {
		cout << 1 << ln;
		return;
	}
	if (H % (x + y)) b = 2 * (H / (x + y)) + 2;
	else b = (H / (x + y)) * 2;
	cout << min(a, b + 1) << ln;
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