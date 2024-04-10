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
#define pll pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

vector<ll> adj[MAX];
ll chk[MAX];
ll isleaf[MAX];

ll ans = 0;

void dfs(ll x, ll p = 0) {
	ll a = 0, b = 0;
	ll cnt = 0;
	for (auto v : adj[x]) {
		if (chk[v]) continue;
		if (p == v) continue;
		b = 1;
		dfs(v, x);
		if (x == 1) continue;
		if (!chk[v]) {
			chk[v] = 1;
			cnt++, a = 1;
		}
	}
	if (!b) isleaf[x] = 1;
	if (a) chk[x] = 1, ans += cnt - 1;
}

void solve() {
	ans = 0;
	ll N;
	cin >> N;
	ll i;
	ll a, b;
	for (i = 1; i <= N; i++) adj[i].clear(), chk[i] = 0, isleaf[i] = 0;
	for (i = 1; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for (i = 1; i <= N; i++) isleaf[i] = 0;
	dfs(1);
	ll cnt = 0;
	for (i = 1; i <= N; i++) cnt += isleaf[i];
	cout << ans + cnt << ln;
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