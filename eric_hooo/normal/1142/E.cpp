#include <bits/stdc++.h>
using namespace std;

int dfn[100010], low[100010], ins[100010], scc[100010], deg[100010], TOT, N;
vector <int> node[100010];
vector <int> S;
vector <int> from[100010], G[100010];
vector <int> all;

void Tarjan(int x) {
	dfn[x] = low[x] = ++TOT, ins[x] = 1, S.push_back(x);
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (!dfn[v]) Tarjan(v), low[x] = min(low[x], low[v]);
		else if (ins[v]) low[x] = min(low[x], dfn[v]);
	}
	if (low[x] != dfn[x]) return ;
	while (1) {
		int v = S.back(); S.pop_back(), ins[v] = 0;
		scc[v] = N, node[N].push_back(v);
		if (v == x) break;
	}
	N++;
}

void Calc(int x) {
	if (node[x].size()) all.push_back(node[x].back()), node[x].pop_back();
	else {
		for (int i = 0; i < G[x].size(); i++) {
			int v = G[x][i];
			deg[v]--;
			if (deg[v] == 0) all.push_back(node[v].back()), node[v].pop_back();
		}
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) Tarjan(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < from[i].size(); j++) {
			int v = from[i][j];
			if (scc[i] != scc[v]) G[scc[i]].push_back(scc[v]), deg[scc[v]]++;
		}
	}
	for (int i = 0; i < N; i++) {
		if (!deg[i]) all.push_back(node[i].back());
	}
	int rt = all.back(); all.pop_back();
	while (all.size()) {
		int x = all.back(); all.pop_back();
		printf("? %d %d\n", rt, x), fflush(stdout);
		int tmp; scanf("%d", &tmp);
		if (tmp == 1) Calc(scc[x]);
		else Calc(scc[rt]), rt = x;
	}
	printf("! %d\n", rt), fflush(stdout);
	return 0;
}