#include <bits/stdc++.h>
using namespace std;

vector <int> from[200010], g[200010];
int id[200010], low[200010], TOT, ALL;
vector <int> S;
int col[200010], vis[200010], TOTOT = 233;
int val[200010];
int fa[200010][18], dep[200010];

bool check(int x, int c = 1) {
	col[x] = c;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (vis[v] != TOTOT) continue;
		if (col[v] == -1) {
			if (check(v, c ^ 1)) return 1;
		} else if (col[v] != (c ^ 1)) return 1;
	}
	return 0;
}

void solve(vector <int> node) {
	int now = ALL++; TOTOT++;
	for (int i = 0; i < node.size(); i++) {
		g[now].push_back(node[i]);
		g[node[i]].push_back(now);
		col[node[i]] = -1, vis[node[i]] = TOTOT;
	}
	if (check(node[0])) val[now] = 1;
}

void dfs(int x) {
	id[x] = low[x] = ++TOT;
	S.push_back(x);
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (!id[v]) {
			dfs(v), low[x] = min(low[x], low[v]);
			if (low[v] >= id[x]) {
				vector <int> node;
				while (1) {
					int tmp = S.back(); S.pop_back();
					node.push_back(tmp);
					if (tmp == v) break;
				}
				node.push_back(x);
				solve(node);
			}
		} else low[x] = min(low[x], id[v]);
	}
}

void dfsg(int x, int last) {
	fa[x][0] = last, vis[x] = 1;
	for (int i = 0; i < g[x].size(); i++) {
		int v = g[x][i];
		if (v == last) continue;
		dep[v] = dep[x] + 1, val[v] += val[x], dfsg(v, x);
	}
}

int get_lca(int x, int y, int fa[][18], int dep[]) {
	if (dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y], cnt = 0;
	while (tmp) {
		if (tmp & 1) x = fa[x][cnt];
		tmp >>= 1, cnt++;
	}
	if (x == y) return x;
	for (int i = 17; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	if (fa[x][0] != fa[y][0]) return -1;
	return fa[x][0];
}

int f[200010][18], ddd[200010];

void dfsccc(int x, int last) {
	f[x][0] = last, vis[x] = 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (vis[v]) continue;
		ddd[v] = ddd[x] + 1, dfsccc(v, x);
	}
}

int main () {
	int n, m; scanf("%d%d", &n, &m);
	ALL = n + 1;
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!id[i]) S.clear(), dfs(i);
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfsg(i, i);
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfsccc(i, i);
	}
	for (int j = 1; j < 18; j++) {
		for (int i = 1; i <= n; i++) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	int q; scanf("%d", &q);
	while (q--) {
		int x, y; scanf("%d%d", &x, &y);
		int lca = get_lca(x, y, fa, dep);
		if (lca == -1) printf("No\n");
		else if (val[x] + val[y] - val[lca] - (fa[lca][0] == lca ? 0 : val[fa[lca][0]]) > 0) {
			printf("Yes\n");
		} else if (ddd[x] + ddd[y] - 2 * ddd[get_lca(x, y, f, ddd)] & 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}