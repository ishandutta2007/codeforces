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
	vector<ll> v;
	v.resize(N);
	ll i;
	for (i = 0; i < N; i++) cin >> v[i];
	ll ans = 0;
	ans += N;
	ans += N - 1;
	for (i = 0; i < N - 2; i++) {
		ll a, b, c;
		a = v[i];
		b = v[i + 1];
		c = v[i + 2];
		if (a == c) {
			if (b != c) ans++;
		}
		else {
			if (!(min(a, c) <= b && b <= max(a, c))) ans++;
		}
	}
	for (i = 0; i < N - 3; i++) {
		ll a, b, c, d;
		a = v[i];
		b = v[i + 1];
		c = v[i + 2];
		d = v[i + 3];
		if (min(b, c) < min(a, d) && max(a, d) < max(b, c)) ans++;
	}
	cout << ans << Ln;
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