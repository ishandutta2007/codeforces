#include <bits/stdc++.h>
const int N = 1e4 + 5;
int n, m, s[N], a[N], b[N], ok[N], vis[N];
struct edge { int u, v; } e[N];
std::vector<int> G[N];
void change(int i) {
	if (!ok[i])
		b[e[i].u] -= 2, b[e[i].v] += 2;
	else
		b[e[i].u] += 2, b[e[i].v] -= 2;
	ok[i] ^= 1;
}
bool dfs(int u, int fix, int tag) {
	for (int i : G[u]) {
		if (vis[i]) continue;
		vis[i] = 1;
		if (e[i].u == u) {
			if (!(ok[i] ^ tag)) continue;
			int v = e[i].v;
			change(i);
			if (!s[v] || v > fix || dfs(v, fix, tag)) return true;
			change(i);
		} else {
			if (ok[i] ^ tag) continue;
			int v = e[i].u;
			change(i);
			if (!s[v] || v > fix || dfs(v, fix, tag)) return true;
			change(i);
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &s[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		b[u]++, b[v]--; e[i] = {u, v};
		G[u].push_back(i), G[v].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		if (s[i] && (b[i] - a[i]) % 2 != 0) { puts("NO"); return 0; }
	for (int i = 1; i <= n; i++)
		if (s[i]) {
			std::fill(vis + 1, vis + m + 1, 0);
			while (b[i] != a[i])
				if (!dfs(i, i, b[i] > a[i])) { puts("NO"); return 0; }
		}
	puts("YES");
	for (int i = 1; i <= m; i++) {
		if (ok[i]) printf("%d %d\n", e[i].u, e[i].v);
		else printf("%d %d\n", e[i].v, e[i].u);
	}
	return 0;
}