#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> from[300010];
int vis[300010], X[300010], Y[300010], cnt[300010], fa[300010], dep[300010];

void dfs(int x, int last) {
	fa[x] = last, vis[x] = 1;
	for (auto v : from[x]) if (!vis[v]) {
		dep[v] = dep[x] + 1, dfs(v, x);
	}
}

vector <int> qwq;

int GetLca(int x, int y) {
	while (x != y) {
		if (dep[x] < dep[y]) swap(x, y);
		x = fa[x];
	}
	return x;
}

void GetPath(int x, int y) {
	int lca = GetLca(x, y);
	printf("%d\n", dep[x] + dep[y] - 2 * dep[lca] + 1);
	while (x != lca) printf("%d ", x), x = fa[x];
	printf("%d ", lca);
	qwq.clear();
	while (y != lca) qwq.push_back(y), y = fa[y];
	reverse(qwq.begin(), qwq.end());
	for (auto it : qwq) {
		printf("%d ", it);
	}
	printf("\n");
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	dfs(1, 1);
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &X[i], &Y[i]);
		cnt[X[i]] ^= 1, cnt[Y[i]] ^= 1;
	}
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		tot += cnt[i];
	}
	if (tot) {
		printf("NO\n");
		printf("%d\n", tot / 2);
		return 0;
	}
	printf("YES\n");
	for (int i = 0; i < q; i++) {
		GetPath(X[i], Y[i]);
	}
	return 0;
}