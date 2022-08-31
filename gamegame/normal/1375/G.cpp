#include <bits/stdc++.h>
int n, x, y, cnt[2];
std::vector<int> g[200020];
void dfs(int v, int p, int l) {
	cnt[l&1]++;
	for(int u : g[v]) if (u!=p)
		dfs(u, v, l+1);
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<n; i++) scanf("%d%d", &x, &y),
		g[x].push_back(y), g[y].push_back(x);
	dfs(1,0,0);
	printf("%d\n", std::min(cnt[0],cnt[1])-1);
}