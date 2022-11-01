#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int MAXN = 200005;
int n, m, par[MAXN];
LL a[MAXN];
struct Edge { int u, v; LL w; } ed[MAXN << 1];
int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	int e = 0, mn = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		par[i] = i;
		if (!mn || a[mn] > a[i]) mn = i;
	}
	for (int i = 1; i <= n; i++) if (i != mn) {
		ed[++e] = Edge { mn, i, a[i] + a[mn] };
	}
	for (int i = 1; i <= m; i++) {
		int u, v; LL w; scanf("%d%d%lld", &u, &v, &w);
		ed[++e] = Edge { u, v, w };
	}
	sort(ed + 1, ed + 1 + e, [&](const Edge &a, const Edge &b) { return a.w < b.w; });
	LL ans = 0;
	for (int i = 1; i <= e; i++) {
		if (find(ed[i].u) == find(ed[i].v)) continue;
		par[find(ed[i].u)] = find(ed[i].v);
		ans += ed[i].w;
	}
	printf("%lld\n", ans);
	return 0;
}