#include <bits/stdc++.h>
#include <cassert>

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
#define MOD 100000009

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

void NO() {
	cout << no << ln;
	exit(0);
}

void solve() {
	ll N, L, R;
	cin >> N >> L >> R;
	ll i;
	vector<ll> l, r;
	l.resize(N + 1);
	r.resize(N + 1);
	ll a;
	for (i = 1; i <= L; i++) cin >> a, l[a]++;
	for (i = 1; i <= R; i++) cin >> a, r[a]++;

	for (i = 1; i <= N; i++) a = min(l[i], r[i]), l[i] -= a, r[i] -= a;
	ll ans = 0;
	ll lp, rp;
	lp = rp = 0;
	for (i = 1; i <= N; i++) lp += l[i] / 2;
	for (i = 1; i <= N; i++) rp += r[i] / 2;
	ll lcnt, rcnt;
	lcnt = rcnt = 0;
	for (i = 1; i <= N; i++) lcnt += l[i];
	for (i = 1; i <= N; i++) rcnt += r[i];
	if (lcnt == rcnt) {
		ans += lcnt;
		cout << ans << ln;
		return;
	}
	if (lcnt > rcnt) {
		swap(lcnt, rcnt), swap(lp, rp);
	}
	ll sub = rcnt - lcnt;
	sub /= 2;
	sub = min(sub, rp);
	ans += sub;
	rcnt -= sub * 2;
	rp -= sub;
	ans += rcnt;
	cout << ans << ln;
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