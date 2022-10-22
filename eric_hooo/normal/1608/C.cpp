#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010], seq[100010];
vector <int> G[100010];
int dfn[100010], low[100010], TOT, ins[100010], ALL, scc[100010];
int in[100010];
vector <int> S;

void Tarjan(int x) {
	dfn[x] = low[x] = ++TOT, ins[x] = 1, S.push_back(x);
	for (auto v : G[x]) {
		if (!dfn[v]) Tarjan(v), low[x] = min(low[x], low[v]);
		else if (ins[v]) low[x] = min(low[x], dfn[v]);
	}
	if (dfn[x] != low[x]) return ;
	in[ALL] = 0;
	while (1) {
		int v = S.back(); S.pop_back(), ins[v] = 0;
		scc[v] = ALL;
		if (v == x) break;
	}
	ALL++;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		TOT = 0, ALL = 0;
		for (int i = 1; i <= n; i++) {
			G[i].clear(), dfn[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
		}
		for (int i = 1; i <= n; i++) {
			seq[i] = i;
		}
		sort(seq + 1, seq + n + 1, [&](int x, int y) {return a[x] < a[y];});
		for (int i = 1; i < n; i++) {
			G[seq[i + 1]].push_back(seq[i]);
		}
		sort(seq + 1, seq + n + 1, [&](int x, int y) {return b[x] < b[y];});
		for (int i = 1; i < n; i++) {
			G[seq[i + 1]].push_back(seq[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) Tarjan(i);
		}
		for (int i = 1; i <= n; i++) {
			for (auto j : G[i]) {
				if (scc[i] != scc[j]) in[scc[j]]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (in[scc[i]] == 0) printf("1");
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}