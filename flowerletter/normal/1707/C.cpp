#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 5, M = 18;
int n, m, fa[N], a[N], c[N];
int ok[N];
vector<int> G[N], T[N];
inline int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int jump[N][M], dep[N];
void dfs(int u, int p) {
	for(int i = 1; i < M; i ++) jump[u][i] = jump[jump[u][i - 1]][i - 1] ;
	for(auto v : T[u]) if(v != p) {
		dep[v] = dep[u] + 1;
		jump[v][0] = u;
		dfs(v, u);
	}
}
void dfs2(int u, int p) {
	for(auto v : T[u]) if(v != p) {
		c[v] += c[u];
		dfs2(v, u);
	}
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	iota(fa + 1, fa + n + 1, 1);
	vector<pair<int, int>> edge;
	for(int i = 1; i <= m; i ++) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
		int x = find(u), y = find(v);
		if(x != y) {
			fa[x] = y;
			T[u].emplace_back(v);
			T[v].emplace_back(u);
		}
		else {
			edge.emplace_back(u, v);
		}
	}
	iota(fa + 1, fa + n + 1, 1);
	dfs(1, 0);
	auto lca = [&] (int u, int v) {
		if(dep[u] < dep[v]) swap(u, v);
		int d = dep[u] - dep[v];
		for(int i = 0; i < M; i ++) if(d >> i & 1) u = jump[u][i];
		if(u == v) return u;
		for(int i = M - 1; i >= 0; i --) if(jump[u][i] != jump[v][i]) u = jump[u][i], v = jump[v][i];
		return jump[u][0];
	};
	auto get = [&] (int u, int k) {
		for(int i = 0; i < M; i ++) if(k >> i & 1) u = jump[u][i];
		return u;
	};
	int cnt = 0;
	for(auto [u, v] : edge) {
		int w = lca(u, v);
		if(dep[u] > dep[v]) swap(u, v);
		if(w == u) {
			c[v] ++;
			c[get(v, dep[v] - dep[u] - 1)] --;
		}
		else {
			c[u] ++, c[v] ++;
			cnt ++;
		}
	}
	dfs2(1, 0);
	for(int i = 1; i <= n; i ++) {
		if(c[i] + a[i] == cnt) cout << '1';
		else cout << '0';
	}
	return 0;
}