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
typedef pair<int, int> pii;

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

int U[MAX];
int V[MAX];
vector<pii> adj[MAX];

int chk[MAX];
int vis[MAX];
vector<int> backe;
int prt[MAX];
int dep[MAX];

void dfs(int x, int p = 0, int pv = 0, int d = 0) {
	dep[x] = d;
	prt[x] = pv;
	vis[x] = 1;
	for (auto& [v, c] : adj[x]) {
		if (v == p) continue;
		if (vis[v]) {
			backe.push_back(c);
			continue;
		}
		dfs(v, x, c, d + 1);
	}
}

void solve() {
	int N, M;
	cin >> N >> M;
	int i;
	int a, b;
	for (i = 1; i <= N; i++) adj[i].clear();
	backe.clear();
	for (i = 1; i <= N; i++) vis[i] = 0, prt[i] = 0, chk[i] = 0;
	for (i = 1; i <= M; i++) {
		cin >> a >> b;
		adj[a].emplace_back(b, i);
		adj[b].emplace_back(a, i);
		U[i] = a;
		V[i] = b;
	}
	if (M == N - 2) {
		cout << string(M, '1') << ln;
		return;
	}
	dfs(1);
	for (i = 1; i <= M; i++) chk[i] = 1;
	for (auto e : backe) chk[e] = 0;
	if (backe.size() <= 2) {
		for (i = 1; i <= M; i++) cout << chk[i];
		cout << ln;
		return;
	}
	set<int> cs;
	for (auto e : backe) cs.insert(U[e]), cs.insert(V[e]);
	if (cs.size() == 3) {
		int e = backe[0];
		int vv = 0;
		if (dep[U[e]] < dep[V[e]]) vv = V[e];
		else vv = U[e];
		chk[e] = 1;
		chk[prt[vv]] = 0;
		for (i = 1; i <= M; i++) cout << chk[i];
		cout << ln;
	}
	else {
		for (i = 1; i <= M; i++) cout << chk[i];
		cout << ln;
		return;
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