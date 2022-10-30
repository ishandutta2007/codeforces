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

vector<ll> adj[MAX];
ll num[MAX];
ll sum[MAX];
ll c;
ll K;

void dfs(ll x, ll p = 0) {
	sum[x] = num[x];
	for (auto v : adj[x]) {
		if (v == p) continue;
		dfs(v, x);
		sum[x] ^= sum[v];
	}
}
ll aaa;
ll dfs2(ll x, ll p = 0) {
	ll asdf = 0;
	for (auto v : adj[x]) {
		if (v == p) continue;
		asdf += dfs2(v, x);
	}
	if (asdf >= 2) c = 1;
	else if (asdf && sum[x] == 0) c = 1;
	if (sum[x] == aaa) asdf = max(1LL, asdf);
	return asdf;
}

void solve() {
	ll N;
	cin >> N >> K;
	c = 0;
	ll i;
	for (i = 1; i <= N; i++) adj[i].clear();
	ll a, b;
	for (i = 1; i <= N; i++) cin >> num[i], sum[i] = 0;
	for (i = 1; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	if (sum[1] == 0) {
		cout << yes << Ln;
		return;
	}
	if (K == 2) {
		cout << no << ln;
		return;
	}
	aaa = sum[1];
	dfs2(1);
	if (c) cout << yes << ln;
	else cout << no << Ln;
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