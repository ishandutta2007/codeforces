#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n;
vector <pii> from[100010];
int f[100010][17];
int edge[100010], deep[100010];
int cnt[100010];
int ans[100010];

void dfs(int x, int last) {
	f[x][0] = last;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi, id = from[x][i].se;
		if (v == last) continue;
		edge[v] = id, deep[v] = deep[x] + 1, dfs(v, x);
	}
}

void get_pre() {
	dfs(1, 1);
	for (int j = 1; j < 17; j++) {
		for (int i = 1; i <= n; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
}

int LCA(int x, int y) {
	if (deep[x] < deep[y]) swap(x, y);
	for (int i = 16; i >= 0; i--) {
		if (deep[f[x][i]] >= deep[y]) x = f[x][i];
	}
	if (x == y) return x;
	for (int i = 16; i >= 0; i--) {
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	}
	return f[x][0];
}

void get_ans(int x, int last) {
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi;
		if (v == last) continue; 
		get_ans(v, x), cnt[x] += cnt[v];
	}
	if (~edge[x]) ans[edge[x]] = cnt[x];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(mp(v, i)), from[v].push_back(mp(u, i));
	}
	int q; scanf("%d", &q);
	get_pre();
	while (q--) {
		int u, v; scanf("%d%d", &u, &v);
		int lca = LCA(u, v);
		cnt[u]++, cnt[v]++, cnt[lca] -= 2;
	}
	get_ans(1, 1);
	for (int i = 1; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}