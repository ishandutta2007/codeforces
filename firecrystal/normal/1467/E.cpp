#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int n, d[N], tot, a[N], f[N], c[N], g[N], cnt[N], md[N], c1[N];

int head[N], numE = 0;

struct E{
	int next, v;
} e[N << 1];

void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}

void dfs(int u, int fa) {
	int t = c[a[u]];
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == fa) continue;
		int o = c[a[u]];
		dfs(v, u);
		if ((c[a[u]] - o) > 0) md[u]++, c1[u] = v;
		f[u] += f[v];
	}
	if (t != c[a[u]]) f[u]++;
	c[a[u]]++;
	if (cnt[a[u]] - (c[a[u]] - t) > 0) g[u]++;
}

void dfs2(int u, int fa) {
	int s = 0;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == fa) continue;
		s += f[v];
	}
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == fa) continue;
		g[v] += g[u] + s - f[v];
		if (md[u] == 2) g[v]++;
		else if (md[u] == 1 && c1[u] != v) g[v]++;
		dfs2(v, u);
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), d[i] = a[i];
	sort(d + 1, d + 1 + n);
	tot = unique(d + 1, d + 1 + n) - d - 1;
	for (int i = 1; i <= n; i++) a[i] = lower_bound(d + 1, d + 1 + tot, a[i]) - d, cnt[a[i]]++;
	for (int i = 1, u, v; i < n; i++)
		scanf("%d%d", &u, &v), add(u, v), add(v, u);
	dfs(1, 0);
	dfs2(1, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (!f[i] && !g[i]) ans++;
	printf("%d\n", ans);
	return 0;
}