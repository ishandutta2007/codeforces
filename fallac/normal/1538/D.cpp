/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long ll;

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

ll f(ll a) {
	if (a == 1) return 0;
	ll i;
	ll cnt = 0;
	for (i = 2; i * i <= a; i++) {
		while ((a % i) == 0) {
			cnt++;
			a /= i;
		}
	}
	if (a != 1) return cnt + 1;
	else return cnt;
}

void solve() {
	ll a, b, k;
	cin >> a >> b >> k;
	if (k == 1) {
		if (a > b) swap(a, b);
		if ((a == b) || (b % a)) {
			cout << no << ln;
		}
		else {
			cout << yes << ln;
		}
		return;
	}
	else {
		ll res = f(a) + f(b);
		if (res >= k) cout << yes << ln;
		else {
			cout << no << ln;
		}
	}
	return;
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