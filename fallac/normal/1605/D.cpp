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

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

vector<ll> adj[MAX];
ll P[MAX];
ll odd;
ll depth[MAX];
ll chk[MAX];
ll pptr;
vector<ll> rem;

void dfs(ll x, ll p = 0, ll d = 0) {
	depth[x] = d;
	if (d % 2) odd++;
	for (auto v : adj[x]) {
		if (v == p) continue;
		dfs(v, x, d + 1);
	}
}

void dfs2(ll x, ll p = 0) {
	if (!P[x]) P[x] = rem[pptr++];
	for (auto v : adj[x]) {
		if (v == p) continue;
		dfs2(v, x);
	}
}

void solve() {
	ll N;
	cin >> N;
	ll i;
	ll a, b;
	odd = 0;
	for (i = 1; i <= N; i++) P[i] = 0, adj[i].clear(), chk[i] = 0;
	rem.clear();
	pptr = 0;
	for (i = 1; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	if (odd <= N / 2) {
		ll x = odd;
		vector<ll> v;
		ll k = 1;
		while (x) {
			if (x & 1) {
				for (i = k; i < 2 * k; i++) v.push_back(i), chk[i] = 1;
			}
			x /= 2;
			k *= 2;
		}
		ll ptr = 0;
		for (i = 1; i <= N; i++) if (depth[i] % 2) P[i] = v[ptr++];
	}
	else {
		ll x = N - odd;
		vector<ll> v;
		ll k = 1;
		while (x) {
			if (x & 1) {
				for (i = k; i < 2 * k; i++) v.push_back(i), chk[i] = 1;
			}
			x /= 2;
			k *= 2;
		}
		ll ptr = 0;
		for (i = 1; i <= N; i++) if (depth[i] % 2 == 0) P[i] = v[ptr++];
	}
	for (i = 1; i <= N; i++) if (!chk[i]) rem.push_back(i);
	dfs2(1);
	for (i = 1; i <= N; i++) cout << P[i] << bb;
	cout << ln;
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