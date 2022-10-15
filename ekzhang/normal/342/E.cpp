#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
#define MAXLG 18
int N, M;
vector<int> adj[MAXN];
int sz[MAXN];
int cpar[MAXN];
int cdist[MAXN];
bool vis[MAXN];

int L[MAXLG][MAXN];
int depth[MAXN];

void dfs(int n, int p) {
	depth[n] = depth[p] + 1;
	L[0][n] = p;
	for (int i = 0; i < MAXLG - 1; i++)
		L[i + 1][n] = L[i][L[i][n]];
	for (int v : adj[n]) if (v != p) {
		dfs(v, n);
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	for (int i = MAXLG - 1; i >= 0; i--) {
		if (depth[u] - (1<<i) >= depth[v])
			u = L[i][u];
	}
	for (int i = MAXLG - 1; i >= 0; i--) {
		if (L[i][u] != L[i][v])
			u = L[i][u], v = L[i][v];
	}
	return u == v ? u : L[0][u];
}

int dist(int u, int v) {
	return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

void dfs_sz(int n, int p=-1) {
	sz[n] = 1;
	for (int v : adj[n]) if (v != p && !vis[v]) {
		dfs_sz(v, n);
		sz[n] += sz[v];
	}
}

int centroid(int n) {
	dfs_sz(n);
	int num = sz[n];
	int p = -1;
	do {
		int nxt = -1;
		for (int v : adj[n]) if (!vis[v] && v != p) {
			if (2 * sz[v] > num)
				nxt = v;
		}
		p = n, n = nxt;
	} while (~n);
	return p;
}

void centroid_decomp(int n, int p=-1) {
	int c = centroid(n);
	vis[c] = true;
	cpar[c] = p;
	for (int v : adj[c]) if (!vis[v]) {
		centroid_decomp(v, c);
	}
}

int main() {
	// Finally solving the CORRECT way: centroid decomp XD
	// O(n lg^2 n) instead of O(n sqrt(n lg n))
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, 0);
	centroid_decomp(0);

	for (int i = 0; i < N; i++)
		cdist[i] = dist(0, i);

	while (M--) {
		int t, v;
		cin >> t >> v;
		--v;
		if (t == 1) {
			for (int n = v; ~n; n = cpar[n])
				cdist[n] = min(cdist[n], dist(n, v));
		}
		else {
			int ans = cdist[v];
			for (int n = v; ~n; n = cpar[n])
				ans = min(ans, cdist[n] + dist(n, v));
			cout << ans << '\n';
		}
	}

	cout.flush();
	return 0;
}