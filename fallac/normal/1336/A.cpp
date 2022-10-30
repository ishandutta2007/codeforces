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

#define pll pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

vector<ll> adj[MAX];
ll prt[MAX], depth[MAX], num[MAX];
ll cnt[MAX];
vector<ll> lv;

void dfs(ll x, ll p = 0, ll d = 1) {
	prt[x] = p;
	num[x] = 1;
	depth[x] = d;
	for (auto v : adj[x]) {
		if (v == p) continue;
		dfs(v, x, d + 1);
		num[x] += num[v];
	}
	if (x != 1 && adj[x].size() == 1) lv.push_back(x);
}

void solve() {
	ll N, K;
	cin >> N >> K;
	ll i;
	ll a, b;
	for (i = 1; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	priority_queue<pll> pq;
	for (auto x : lv) pq.emplace(depth[x] - 1, x);
	ll ans = 0;
	for (i = 1; i <= K; i++) {
		pll t = pq.top();
		pq.pop();
		ll v, val;
		v = t.second;
		val = t.first;
		ans += val;
		cnt[prt[v]]++;
		if (prt[v] == 1) {
			if (cnt[prt[v]] == adj[prt[v]].size()) {
				pq.emplace(depth[prt[v]] - 1 - (num[prt[v]] - 1), prt[v]);
			}
		}
		else {
			if (cnt[prt[v]] == adj[prt[v]].size() - 1) {
				pq.emplace(depth[prt[v]] - 1 - (num[prt[v]] - 1), prt[v]);
			}
		}
	}
	cout << ans << ln;
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