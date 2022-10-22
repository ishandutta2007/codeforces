#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

vector <int> from[100010], g[100010];
vector <int> node;
int id[100010], fa[100010], top[100010], son[100010], sz[100010], dep[100010], TOT;
int st[100010], tp;
int vis[100010], TOTOT;
vector <int> used;

void dfs1(int x, int last) {
	fa[x] = last, sz[x] = 1, son[x] = -1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dep[v] = dep[x] + 1, dfs1(v, x), sz[x] += sz[v];
		if (son[x] == -1 || sz[v] > sz[son[x]]) son[x] = v;
	}
}

void dfs2(int x, int t) {
	top[x] = t, id[x] = ++TOT;
	if (son[x] == -1) return ;
	dfs2(son[x], t);
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == fa[x] || v == son[x]) continue;
		dfs2(v, v);
	}
}

int get_lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

bool cmp(int x, int y) {
	return id[x] < id[y];
}

void get_tree() {
	tp = 0, st[tp++] = 1;
	for (int i = 1; i < node.size(); i++) {
		int x = node[i], t = get_lca(node[i - 1], node[i]);
		used.push_back(x), used.push_back(t);
		int lst = -1;
		while (dep[st[tp - 1]] > dep[t]) {
			tp--;
			if (lst != -1) g[st[tp]].push_back(lst);
			lst = st[tp];
		}
		if (dep[st[tp - 1]] < dep[t]) st[tp++] = t;
		if (lst != -1) g[st[tp - 1]].push_back(lst);
		st[tp++] = x;
	}
	while (tp > 1) g[st[tp - 2]].push_back(st[tp - 1]), tp--;
}

pii solve(int x) {
	pii res = vis[x] == TOTOT ? mp(INF, 0) : mp(0, INF);
	int sum = 0;
	for (int i = 0; i < g[x].size(); i++) {
		int v = g[x][i];
		pii tmp = solve(v);
		if (dep[v] != dep[x] + 1) tmp.fi = min(tmp.fi, tmp.se + 1);
		res.se = min(INF, min(res.se + tmp.fi, res.fi + tmp.se));
		res.fi = min(INF, res.fi + tmp.fi);
		sum = min(INF, sum + min(tmp.fi, tmp.se));
	}
	if (vis[x] != TOTOT) res.fi = min(res.fi, sum + 1);
	return res;
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	dfs1(1, 1), dfs2(1, 1);
	int q; scanf("%d", &q);
	while (q--) {
		int m; scanf("%d", &m);
		int has1 = 0; node.clear(), used.clear(), TOTOT++;
		while (m--) {
			int x; scanf("%d", &x);
			vis[x] = TOTOT;
			node.push_back(x);
			if (x == 1) has1 = 1;
		}
		if (!has1) node.push_back(1);
		sort(node.begin(), node.end(), cmp);
		get_tree();
		pii tmp = solve(1);
		printf("%d\n", min(tmp.fi, tmp.se) == INF ? -1 : min(tmp.fi, tmp.se));
		for (int i = 0; i < used.size(); i++) {
			g[used[i]].clear();
		}
	}
	return 0;
}