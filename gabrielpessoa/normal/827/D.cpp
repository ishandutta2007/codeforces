#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+5;
const int inf = 0x3f3f3f3f;

int n, m;

vector<pair<int, int>> g[ms];
pair<pair<int, int>, pair<int, int>> edges[ms];
int ans[ms];
int ds[ms];

int sz[ms], par[ms], h[ms];
int t, in[ms], out[ms], rin[ms], nxt[ms], ed[ms], w[ms];
int segQ[2*ms], segU[2*ms];
int pertence[ms];

void build() {
	for(int i = 0; i < n; i++) {
		segQ[in[i]+n] = w[i];
		segU[i+n] = inf;
	}
	for(int i = n - 1; i > 0; i--) {
		segQ[i] = max(segQ[i<<1], segQ[i<<1|1]);
		segU[i] = min(segU[i<<1], segU[i<<1|1]);
	}
}

int query(int l, int r) {
	int res = 0;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if(l&1) res = max(res, segQ[l++]);
		if(r&1) res = max(res, segQ[--r]);
	}
	return res;
}

void update(int v, int l, int r) {
	//cout << v << ' ' << l << ' ' << r << endl;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if(l&1) {segU[l] = min(segU[l], v); l++;}
		if(r&1) {--r; segU[r] = min(segU[r], v);}
	}
}

void push() {
	for(int i = 1; i < n; i++) {
		segU[i<<1] = min(segU[i], segU[i<<1]);
		segU[i<<1|1] = min(segU[i], segU[i<<1|1]);
		segU[i] = 0;
	}
}

void dfs_sz(int v = 0, int p = -1) {
	sz[v] = 1;
	for(int i = 0; i < g[v].size(); i++) {
		auto &u = g[v][i];
		if(u.first == p) continue;
		h[u.first] = h[v]+1, par[u.first] = v, ed[u.first] = edges[u.second].first.second, w[u.first] = edges[u.second].first.first;
		dfs_sz(u.first, v);
		sz[v] += sz[u.first];
		if(g[v][0].first == p || sz[u.first] > sz[g[v][0].first]) {
			swap(u, g[v][0]);
		}
	}
}

void dfs_hld(int v = 0, int p = -1) {
	in[v] = t++;
	rin[in[v]] = v;
	for(int i = 0; i < g[v].size(); i++) {
		auto &u = g[v][i];
		if(u.first == p) continue;
		nxt[u.first] = u == g[v][0] ? nxt[v] : u.first;
		dfs_hld(u.first, v);
	}
	out[v] = t;
}

int up(int v) {
	return (nxt[v] != v) ? nxt[v] : (~par[v] ? par[v] : v);
}

int getLCA(int a, int b) {
	while(nxt[a] != nxt[b]) {
		if(h[a] == 0 || h[up(a)] < h[up(b)]) swap(a, b);
		a = up(a);
	}
	return h[a] < h[b] ? a : b;
}

int queryUp(int a, int p = 0){
	int ans = 0;
	while(nxt[a] != nxt[p]){
		ans =  max(ans, query(in[nxt[a]], in[a]));
		a = par[nxt[a]];
	}
	ans =  max(query(in[p]+1, in[a]), ans);
	return ans;
}

int queryPath(int u, int v) {
	int lca = getLCA(u, v);
	return max(queryUp(u, lca), queryUp(v, lca));
}

void updateUp(int v, int a, int p = 0) {
	while(nxt[a] != nxt[p]) {
		update(v, in[nxt[a]], in[a]);
		//cout << "Tamanho do update = " << in[a] - in[nxt[a]] + 1 << endl;
		a = par[nxt[a]];
	}
	update(v, in[p]+1, in[a]);
	//cout << "Tamanho do update = " << in[a] - in[p] << endl;
}

void updatePath(int val, int u, int v) {
	int lca = getLCA(u, v);
	updateUp(val, u, lca); updateUp(val, v, lca);
}

int dsFind(int u) {
	if(u != ds[u]) ds[u] = dsFind(ds[u]);
	return ds[u];
}

int dsUnion(int u, int v) {
	u = dsFind(u); v = dsFind(v);
	ds[u] = v;
	return u != v;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		ds[i] = i;
	}
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = {{w, i}, {u-1, v-1}};
	}
	sort(edges, edges+m);
	for(int i = 0; i < m; i++) {
		int idx = edges[i].first.second;
		int u = edges[i].second.first, v = edges[i].second.second;
		if(dsUnion(u, v)) {
			pertence[i] = true;
			g[u].push_back({v, i});
			g[v].push_back({u, i});
		}
	}
	dfs_sz();
	dfs_hld();
	build();
	for(int i = 0; i < m; i++) {
		if(!pertence[i]) {
			ans[edges[i].first.second] = queryPath(edges[i].second.first, edges[i].second.second) - 1;
			updatePath(edges[i].first.first, edges[i].second.first, edges[i].second.second);
		}
	}
	push();
	for(int i = 1; i < n; i++) {
		ans[ed[i]] = segU[in[i]+n] == inf ? -1 : segU[in[i]+n] - 1;
	}
	for(int i = 0; i < m; i++) {
		cout << ans[i] << ' ';
	}
	cout << "\n";
}