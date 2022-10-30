/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef int ll;
typedef pair<ll, ll> pll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 501010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

map<pll, ll> echk;
vector<ll> adj[MAX];

bool calc(ll x) {
	ll ans = 0;
	while (x) {
		ans += x & 1;
		x >>= 1;
	}
	return ans & 1;
}

ll dfsn[MAX];
ll cnt;
stack<ll> S;
ll finished[MAX];
vector<vector<ll>> SCC;
ll SN;
ll sn[MAX];

ll DFS(ll curr) {
	dfsn[curr] = ++cnt; // dfsn 
	S.push(curr); //   push

	//  dfsn,   dfsn     result 
	ll result = dfsn[curr];
	for (ll next : adj[curr]) {
		//    
		if (dfsn[next] == 0) result = min(result, DFS(next));
		//    SCC   
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	// ,          SCC 
	if (result == dfsn[curr]) {
		vector<ll> currSCC;
		//     pop
		while (1) {
			ll t = S.top();
			S.pop();
			currSCC.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if (t == curr) break;
		}
		//    
		sort(currSCC.begin(), currSCC.end());
		// SCC 
		SCC.push_back(currSCC);
		SN++;
	}
	return result;
}

ll res[MAX];
pll pp[MAX];
ll prt[MAX];
vector<ll> tree[MAX];

void dfs(ll x, ll p = 0) {
	prt[x] = p;
	for (auto v : tree[x]) {
		if (v == p) continue;
		dfs(v, x);
	}
}

void solve() {
	ll N, M;
	cin >> N >> M;
	ll i;
	ll a, b, v;
	for (i = 0; i <= N; i++) tree[i].clear();
	SCC.clear();
	for (i = 0; i <= N * 2; i++) dfsn[i] = finished[i] = sn[i] = 0, adj[i].clear();
	cnt = 0;
	SN = 0;
	echk.clear();
	while (S.size()) S.pop();
	for (i = 0; i < N - 1; i++) {
		cin >> a >> b >> v;
		tree[a].push_back(b);
		tree[b].push_back(a);
		echk[{a, b}] = v;
		if (v == -1) continue;
		else {
			ll res = calc(v);
			if (res) adj[a + N].push_back(b), adj[b + N].push_back(a), adj[a].push_back(b + N), adj[b].push_back(a + N);
			else adj[a].push_back(b), adj[b].push_back(a), adj[a + N].push_back(b + N), adj[b + N].push_back(a + N);
		}
	}
	dfs(1);
	for (i = 0; i < M; i++) {
		cin >> a >> b >> v;
		ll res = v;
		if (res) adj[a + N].push_back(b), adj[b + N].push_back(a), adj[a].push_back(b + N), adj[b].push_back(a + N);
		else adj[a].push_back(b), adj[b].push_back(a), adj[a + N].push_back(b + N), adj[b + N].push_back(a + N);
	}
	for (i = 1; i <= 2 * N; i++) {
		if (!dfsn[i]) DFS(i);
	}
	sort(SCC.begin(), SCC.end());
	ll ss = sn[1];
	ll c = 1;
	for (i = 1; i <= N; i++) {
		if (sn[i] == sn[i + N]) {
			c = 0;
			break;
		}
	}
	if (!c) {
		cout << no << ln;
		return;
	}
	else {
		for (i = 1; i <= 2 * N; i++) pp[i] = pll(sn[i], i), res[i] = -1;
		sort(pp + 1, pp + 2 * N + 1);
		for (i = 2 * N; i >= 1; i--) {
			ll v = pp[i].second;
			ll x = v > N ? v - N : v;
			if (res[x] == -1) {
				if (v > N) res[x] = 0;
				else res[x] = 1;
			}
		}
		cout << yes << ln;
		for (i = 2; i <= N; i++) {
			ll u, v;
			u = i, v = prt[i];
			if (echk.find({ u, v }) == echk.end()) swap(u, v);
			cout << u << bb << v << bb;
			if (echk[{u, v}] != -1) cout << echk[{u, v}] << ln;
			else {
				if (res[i] != res[prt[i]]) cout << 1 << ln;
				else cout << 0 << ln;
			}
		}
	}
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