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

#define MAX 301010
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

ll tree[MAX];
char mode[MAX];
ll l[MAX];
ll r[MAX];
ll N;

void prop(ll x) {
	if (mode[x] == '1') tree[x] = tree[x * 2];
	else if (mode[x] == '0') tree[x] = tree[x * 2 + 1];
	else tree[x] = tree[x * 2] + tree[x * 2 + 1];
}

void init(ll x = 1) {
	if (x >= N / 2) return;
	init(x * 2);
	init(x * 2 + 1);
	prop(x);
}

void upd(ll x) {
	while (x) {
		prop(x);
		x /= 2;
	}
}

void solve() {
	ll k, Q;
	cin >> k;
	N = 1 << k;
	string s;
	cin >> s;
	cin >> Q;
	ll i;
	for (i = 1; i < N; i++) mode[i] = s[N - i - 1];
	for (i = 1; i <= N; i++) if (i >= N / 2) tree[i] = (mode[i] == '?' ? 2 : 1);
	init();
	while (Q--) {
		char b;
		ll a;
		cin >> a >> b;
		a = N - a;
		if (a >= N / 2) {
			if (b == '?') tree[a] = 2;
			else tree[a] = 1;
			upd(a / 2);
		}
		else {
			mode[a] = b;
			upd(a);
		}
		cout << tree[1] << ln;
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		solve();
	}
}