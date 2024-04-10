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

ll arr[1000000];

ll g(ll x) {
	if (x == 0) return 0;
	if (x == 1) return 2;
	if (x == 2) return 3;
	if (x == 3) return 1;
}

ll f(ll loc, ll a) {
	if (a == 0) {
		return 0;
	}
	else {
		ll i;
		ll x = 1;
		for (i = 1; i <= a; i++) x *= 4;
		ll sz = x;
		sz /= 4;
		return g(loc / sz) * sz + f(loc % sz, a - 1);
	}
}

void solve() {
	/*
	ll N = 100;
	ll i;
	for (i = 1; i <= N; i++) {
		ll a, b, c;
		a = 1;
		while (arr[a]) a++;
		b = a + 1;
		while (arr[b] || (b >= (a ^ b)) || arr[a ^ b]) b++;
		cout << a << bb << b << bb << (a ^ b) << ln;
		arr[a] = arr[b] = arr[a ^ b] = 1;
	}
	*/
	ll N;
	cin >> N;
	if (N <= 3) {
		cout << N << Ln;
		return;
	}
	ll M = (N + 2) / 3;
	ll i;
	ll a = 0;
	ll x = 1;
	for (i = 0; i <= 100; i++) {
		a += x;
		x *= 4;
		if (a >= M) break;
	}
	x /= 4;
	a -= x;
	ll p, q, r;
	p = x + (M - a - 1);
	q = 2 * x + f(M - a - 1, i);
	r = p ^ q;
	if (N % 3 == 1) cout << p << ln;
	if (N % 3 == 2) cout << q << ln;
	if (N % 3 == 0) cout << r << ln;
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