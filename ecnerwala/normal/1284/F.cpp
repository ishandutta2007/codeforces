#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int N;
vector<int> adj[MAXN];
int par[MAXN][20];
int depth[MAXN];

void dfs(int cur, int prv) {
	depth[cur] = depth[prv] + 1;
	par[cur][0] = prv;
	for (int i = 0; par[cur][i]; i++) {
		par[cur][i+1] = par[par[cur][i]][i];
	}
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs(nxt, cur);
	}
}

int compressed[MAXN];
int getCompressed(int cur) {
	return compressed[cur] ? (compressed[cur] = getCompressed(compressed[cur])) : cur;
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a,b);
	for (int i = 0; depth[b] > depth[a]; i++) {
		if ((1<<i) & (depth[b] - depth[a])) {
			b = par[b][i];
		}
	}
	if (a == b) return a;
	int i = 0;
	while (par[a][i] != par[b][i]) i++;
	while (i > 0) {
		--i;
		if (par[a][i] != par[b][i]) {
			a = par[a][i], b = par[b][i];
		}
	}
	return par[a][0];
}

pair<int, int> get_edge(int st, int en) {
	int r = lca(st, en);
	st = getCompressed(st);
	if (depth[st] > depth[r]) {
		compressed[st] = par[st][0];
		return {st, par[st][0]};
	}

	// there must be at least one edge
	assert(depth[getCompressed(en)] > depth[r]);
	int i = 0;
	while (par[en][i] && depth[getCompressed(par[en][i])] > depth[r]) {
		i++;
	}
	while (i > 0) {
		i--;
		if (par[en][i] && depth[getCompressed(par[en][i])] > depth[r]) {
			en = par[en][i];
		}
	}
	compressed[en] = par[en][0];
	return {par[en][0], en};
}

vector<int> adj2[MAXN];

void dfs2(int cur, int prv) {
	for (int nxt : adj2[cur]) {
		if (nxt == prv) continue;
		dfs2(nxt, cur);

		pair<int, int> e = get_edge(nxt, cur);
		cout << e.first << ' ' << e.second << ' ' << nxt << ' ' << cur << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v;
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}

	dfs(1,0);

	cout << N-1 << '\n';
	dfs2(1,0);

	return 0;
}