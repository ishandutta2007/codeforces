#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

namespace dsu {
	int par[N];
	void init() {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		} 
	}
	
	int anc(int u) {
		if (par[u] == u) {
			return u;
		} else {
			return par[u] = anc(par[u]);
		}
	}
	
	bool join(int u,int v) {
		u = anc(u), v = anc(v);
		if (u == v) {
			return false;
		} else {
			par[v] = u;
			return true;
		}
	}
};

struct edge {
	int from, to, cost, id;
	
	int other(int u) {
		return from ^ to ^ u;
	}
	
	void out() {
		printf("%d <-> %d : %d\n", from, to, cost);
	}
};

bool cmp_cost(const edge &a,const edge &b) {
	return a.cost < b.cost;
}

bool cmp_id(const edge &a, const edge &b) {
	return a.id < b.id;
}

int n, m;
vector<edge> edges;
vector<int> g[N];
bool used[N];
int dep[N];
int par[18][N];
int par_id[N];
int mx[18][N];
int mn[18][N];
int ans[N];
vector<int> tour;

void dfs(int u) {
	for (int i = 1; i < 18; ++i) {
		par[i][u] = par[i - 1][par[i - 1][u]];
		mx[i][u] = max(mx[i - 1][u], mx[i - 1][par[i - 1][u]]);
	}
	for (int id : g[u]) {
		int v = edges[id].other(u);
		if (v == par[0][u]) {
			continue;
		}
		dep[v] = dep[u] + 1;
		par[0][v] = u;
		par_id[v] = id;
		mx[0][v] = edges[id].cost;
		dfs(v);
	}
	tour.push_back(u);
}

int lca(int u,int v) {
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	for (int i = 17; i >= 0; --i) {
		if (dep[par[i][v]] >= dep[u]) {
			v = par[i][v];
		}
	}
	
	if (u == v) {
		return u;
	}
	
	for (int i = 17; i >= 0; --i) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	
	return par[0][u];
}

int getMx(int u,int v) {
	int a = lca(u, v);
	int ans = 0;
	for (int t : {u, v}) {
		int dif = dep[t] - dep[a];
		for (int i = 17; i >= 0; --i) {
			if (dif & (1 << i)) {
				ans = max(ans, mx[i][t]);
				t = par[i][t];
			}
		}
	}
	return ans;
}

void updMn(int u,int v,int w) {
	int a = lca(u, v);
	for (int t : {u, v}) {
		int dif = dep[t] - dep[a];
		for (int i = 17; i >= 0; --i) {
			if (dif & (1 << i)) {
				mn[i][t] = min(mn[i][t], w);
				t = par[i][t];
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges.push_back({u, v, w, i});
	}
	sort(edges.begin(), edges.end(), cmp_cost);
	dsu::init();
	for (auto e : edges) {
		if (dsu::join(e.from, e.to)) {
			g[e.from].push_back(e.id);
			g[e.to].push_back(e.id);
			used[e.id] = true;
		}
	}
	sort(edges.begin(), edges.end(), cmp_id);
	par[0][1] = 1;
	dfs(1);
	memset(mn, 69, sizeof mn);
	
	for (auto e : edges) {
		if (!used[e.id]) {
			ans[e.id] = getMx(e.from, e.to);
			updMn(e.from, e.to, e.cost);
		}
	} 
	
	for (int u : tour) {
		for (int i = 17; i > 0; --i) {
			mn[i - 1][u] = min(mn[i - 1][u], mn[i][u]);
			mn[i - 1][par[i - 1][u]] = min(mn[i - 1][par[i - 1][u]], mn[i][u]);
		}
		if (u > 1) {
			ans[par_id[u]] = mn[0][u];
			if (ans[par_id[u]] > 1e9) {
				ans[par_id[u]] = 0;
			}
		}
	}
	
	for (int i = 0; i < m; ++i) {
		printf("%d ", ans[i] - 1);
	}
}