#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

struct DSU {
	int n;
	vector<int> p, r;
	int nsets;

	DSU(int n): n(n), p(n), r(n), nsets(n) {
		iota(all(p), 0);
	}

	int get(int v) {
		return p[v] == v ? v : p[v] = get(p[v]);
	}

	bool merge(int u, int v) {
		u = get(u), v = get(v);
		if (u == v) return false;
		if (r[u] == r[v]) ++r[u];
		if (r[u] < r[v]) swap(u, v);
		p[v] = u;
		--nsets;
		return true;
	}

};

const int N = 1e5 + 30;
const int LOG = 20;

vector<pair<int, ll>> graph[N];
vector<pair<pair<int, int>, ll>> extra;

int up[N][LOG], tin[N], tout[N], timer;
ll toroot[N];

void dfs_prepare(int u = 0, int p = 0) {
	up[u][0] = p;
	for (int steps = 1; steps < LOG; ++steps) {
		up[u][steps] = up[up[u][steps - 1]][steps - 1];
	}
	tin[u] = timer++;
	for (auto [v, w]: graph[u]) {
		if (v != p) {
			toroot[v] = toroot[u] + w;
			dfs_prepare(v, u);
		}
	}
	tout[u] = timer++;
}

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (is_ancestor(u, v)) return u;
	if (is_ancestor(v, u)) return v;
 	for (int steps = LOG - 1; steps >= 0; --steps) {
		if (!is_ancestor(up[u][steps], v)) u = up[u][steps];
	}
	return up[u][0];
}

ll dist(int x, int y) {
	return toroot[x] + toroot[y] - 2 * toroot[lca(x, y)];
}

vector<int> extravs;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n, m; 
	cin >> n >> m;
	DSU dsu(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		if (dsu.merge(u, v)) {
			graph[u].emplace_back(v, w);
			graph[v].emplace_back(u, w);
		} else {
			extra.emplace_back(make_pair(u, v), w);
			extravs.push_back(u);
			extravs.push_back(v);
		}
	}	
	dfs_prepare();
	sort(all(extravs));
	extravs.resize(unique(all(extravs)) - extravs.begin());
	int nextra = szof(extravs);
	vector<vector<ll>> extra_cost(nextra, vector<ll>(nextra));
	for (int i = 0; i < nextra; ++i) {
		for (int j = 0; j < nextra; ++j) {
			extra_cost[i][j] = dist(extravs[i], extravs[j]);
		}
	}
	for (auto[p, w]: extra) {
		int u, v;
		tie(u, v) = p;
		u = lower_bound(all(extravs), u) - extravs.begin();
		v = lower_bound(all(extravs), v) - extravs.begin();
		extra_cost[v][u] = min(extra_cost[v][u], w);
		extra_cost[u][v] = min(extra_cost[u][v], w);
	}
	for (int k = 0; k < nextra; ++k) {
		for (int i = 0; i < nextra; ++i) {
			for (int j = 0; j < nextra; ++j) {
				extra_cost[i][j] = min(extra_cost[i][j], extra_cost[i][k] + extra_cost[k][j]);
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		ll res = dist(u, v);
		vector<ll> du(nextra), dv(nextra);
		for (int i = 0; i < nextra; ++i) {
			du[i] = dist(u, extravs[i]);
			dv[i] = dist(v, extravs[i]);
		}
		for (int a = 0; a < nextra; ++a) {
			for (int b = 0; b < nextra; ++b) {
				res = min(res, du[a] + extra_cost[a][b] + dv[b]);
			}
		}
		cout << res << "\n";
	}
	return 0;
}