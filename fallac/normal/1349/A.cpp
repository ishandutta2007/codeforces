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

#define MAX 301010
#define MOD 100000009
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

ll chk[MAX];
ll asdf[MAX];
vector<ll> p;

void solve() {
	ll N;
	cin >> N;
	vector<ll> v;
	v.resize(N);
	ll i;
	for (i = 0; i < N; i++) cin >> v[i];
	ll ans = 1;
	ll j;
	for (i = 0; i < N; i++) {
		ll a = v[i];
		for (j = 2; j * j <= a; j++) {
			if (a % j == 0)
				chk[j]++;
			while (a % j == 0) {
				a /= j;
			}
		}
		if (a != 1) chk[a]++;
	}
	for (i = 1; i <= 200000; i++) if (chk[i] >= N - 1) p.push_back(i);
	for (i = 0; i < p.size(); i++) {
		ll x, y;
		x = y = INF;
		for (j = 0; j < N; j++) {
			ll a = v[j];
			ll cnt = 0;
			while (a % p[i] == 0) {
				a /= p[i];
				cnt++;
			}
			if (cnt < x) y = x, x = cnt;
			else if (cnt < y) y = cnt;
		}
		for (j = 0; j < y; j++) ans *= p[i];
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