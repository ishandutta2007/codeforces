/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 601010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000000009

#define yes "YES"
#define no "NO"

ll inv[MAX];
ll p[MAX];
ll num[MAX];
ll arr[MAX];

ll find(ll x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

ll uni(ll a, ll b) {
	a = find(a);
	b = find(b);
	if (a == b) return a;
	if (num[a] > num[b]) swap(a, b);
	num[b] = num[a] + num[b];
	p[a] = b;
	return b;
}

void solve() {
	ll Q;
	cin >> Q;
	ll i;
	ll cnt = 0;
	ll t, a, b;
	for (i = 1; i <= Q; i++) {
		cin >> t >> a;
		if (t == 2) cin >> b;
		if (t == 1) {
			cnt++;
			p[cnt] = cnt;
			num[cnt] = 1;
			if (inv[a]) {
				p[cnt] = inv[a];
				num[inv[a]]++;
			}
			else {
				arr[cnt] = a;
				inv[a] = cnt;
			}
		}
		else {
			if (a == b) continue;
			if (inv[a] == 0) continue;
			if (inv[b]) {
				ll x = inv[a];
				ll y = inv[b];
				ll u = uni(x, y);
				inv[a] = 0;
				inv[b] = u;
				arr[u] = b;
			}
			else {
				ll x = inv[a];
				arr[x] = b;
				inv[a] = 0;
				inv[b] = x;
			}
		}
	}
	for (i = 1; i <= cnt; i++) {
		ll x = find(i);
		cout << arr[x] << bb;
	}
	cout << ln;
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