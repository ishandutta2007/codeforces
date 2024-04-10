#include <bits/stdc++.h>

const int maxn = 2005;

int n,idx,dfn[maxn],low[maxn],in[maxn],G[maxn][maxn],sccno;
std::stack<int>stk;

void tarjan(int u) {
	stk.push(u);
	dfn[u] = low[u] = ++idx;
	for (int v = 1; v <= n; ++ v) {
		if (!G[u][v]) continue;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u],low[v]);
		} else if (!in[v]) low[u] = std::min(low[u],dfn[v]);
	}
	if (dfn[u] == low[u]) {
		sccno ++;
		while (stk.top() != u) {
			if (!in[stk.top()]) in[stk.top()] = sccno;
			stk.pop();
		} in[u] = sccno;
	}
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j <= n; ++ j)
		scanf("%d",&G[i][j]);
	tarjan(1);
	for (int i = 1; i <= n; ++ i) if (in[i] != in[1]) { puts("NO"); return 0; }
	puts("YES");
	return 0;
}