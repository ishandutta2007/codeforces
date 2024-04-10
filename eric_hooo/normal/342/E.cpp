#include <bits/stdc++.h>
using namespace std;

const int block = 100;

vector <int> v;
int n;
int fa[100010][17];
int deep[100010];
int isred[100010];
int dist[100010];
vector <int> from[100010];

void dfs(int x, int last) {
	fa[x][0] = last;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		deep[v] = deep[x] + 1, dfs(v, x);
	}
}

void calc_f() {
	for (int j = 1; j < 17; j++) {
		for (int i = 1; i <= n; i++) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
}

int lca(int x, int y) {
	if (deep[x] < deep[y]) swap(x, y);
	int t = deep[x] - deep[y], cnt = 0;
	while (t) {
		if (t & 1) x = fa[x][cnt];
		t >>= 1, cnt++;
	}
	if (x == y) return x;
	for (int i = 16; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

int q[100010], tot;

void rebuild() {
	v.clear();
	tot = 0;
	memset(dist, 0x3f, sizeof(dist));
	for (int i = 1; i <= n; i++) {
		if (isred[i]) dist[i] = 0, q[tot++] = i;
	}
	for (int it = 0; it < tot; it++) {
		int x = q[it];
		for (int i = 0; i < from[x].size(); i++) {
			int v = from[x][i];
			if (dist[v] != 0x3f3f3f3f) continue;
			dist[v] = dist[x] + 1; q[tot++] = v;
		}
	}
}

int main () {
	int m; scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	dfs(1, 1), calc_f();
	memset(dist, 0x3f, sizeof(dist));
	v.push_back(1), isred[1] = 1;
	while (m--) {
		int t, x; scanf("%d%d", &t, &x);
		if (t == 1) {
			v.push_back(x), isred[x] = 1;
			if (v.size() == block) rebuild();
		} else {
			int ans = dist[x];
			for (int i = 0; i < v.size(); i++) {
				int y = v[i];
				ans = min(ans, deep[x] + deep[y] - 2 * deep[lca(x, y)]);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}