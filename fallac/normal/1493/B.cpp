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
#define MOD 100000009

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second

//var
ll h, m;
ll trans[10] = { 0, 1, 5, -1, -1, 2, -1, -1, 8, -1 };
//

pair<ll, ll> next(pair<ll, ll> p) {
	if (p.ss + 1 == m) {
		if (p.ff + 1 == h) return { 0, 0 };
		else return { p.ff + 1, 0 };
	}
	else return { p.ff, p.ss + 1 };
}

bool operator==(pair<ll, ll> p1, pair<ll, ll> p2) {
	return p1.ff == p2.ff && p1.ss == p2.ss;
}

bool operator!=(pair<ll, ll> p1, pair<ll, ll> p2) {
	return !(p1 == p2);
}

ll f(ll x) {
	if (x >= 10) {
		ll d1, d2;
		d1 = x / 10;
		d2 = x % 10;
		if (trans[d1] < 0 || trans[d2] < 0) return -1;
		return trans[d1] + trans[d2] * 10;
	}
	else {
		if (trans[x] < 0) return -1;
		return trans[x] * 10;
	}
}

bool check(pair<ll, ll> time) {
	if (f(time.first) < 0 || f(time.second) < 0) return false;
	return f(time.first) < m && f(time.second) < h;
}

void solve() {
	cin >> h >> m;
	ll hh, mm;
	scanf("%lld:%lld", &hh, &mm);
	pair<ll, ll> time;
	time.first = hh;
	time.second = mm;
	if (check(time)) {
		printf("%02lld:%02lld\n", time.first, time.second);
		return;
	}
	bool c = true;
	while (c || time != make_pair(hh, mm)) {
		time = next(time);
		if (check(time)) break;
		c = false;
	}
	printf("%02lld:%02lld\n", time.first, time.second);
}

void init() {

}

signed main() {
	//ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}