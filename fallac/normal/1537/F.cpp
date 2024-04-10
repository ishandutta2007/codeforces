/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'

#define MAX 303030
#define MOD 100000009
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

vector<ll> v, t, d, col, vis;

vector<ll> adj[MAX];

void dfs(ll x, ll c = 1) {
	if (vis[x] == 1) return;
	vis[x] = 1;
	col[x] = c;
	for (auto v : adj[x]) {
		if (vis[v]) continue;
		dfs(v, 3 - c);
	}
}

void solve() {
	ll N, M;
	cin >> N >> M;
	ll i;
	for (i = 1; i <= N; i++) adj[i].clear();
	v.resize(N + 1);
	t.resize(N + 1);
	d.resize(N + 1);
	col.resize(N + 1);
	vis.resize(N + 1);
	for (i = 1; i <= N; i++) cin >> v[i];
	for (i = 1; i <= N; i++) cin >> t[i];
	for (i = 1; i <= N; i++) d[i] = t[i] - v[i];
	ll sum = 0;
	for (i = 1; i <= N; i++) sum += d[i];
	ll a, b;
	for (i = 1; i <= M; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	bool c = 0;
	for (i = 1; i <= N; i++) {
		for (auto x : adj[i]) {
			if (col[i] == col[x]) {
				c = true;
			}
		}
	}
	if (c) {
		if (sum % 2) {
			cout << no << ln;
		}
		else {
			cout << yes << ln;
		}
	}
	else {
		ll suma, sumb;
		suma = sumb = 0;
		for (i = 1; i <= N; i++) {
			if (col[i] == 1) suma += d[i];
			else sumb += d[i];
		}
		if (suma == sumb) {
			cout << yes << ln;
		}
		else {
			cout << no << ln;
		}
	}
}

void init() {
	v.clear();
	t.clear();
	d.clear();
	col.clear();
	vis.clear();
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