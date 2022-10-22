#include <bits/stdc++.h>
using namespace std;

int dep[100010];
vector <int> from[100010];

void dfs(int x, int last) {
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dep[v] = dep[x] + 1, dfs(v, x);
	}
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, a, b, da, db; scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
		for (int i = 1; i <= n; i++) {
			from[i].clear();
		}
		for (int i = 1; i < n; i++) {
			int x, y; scanf("%d%d", &x, &y);
			from[x].push_back(y);
			from[y].push_back(x);
		}
		if (da >= db) {
			printf("Alice\n");
			continue;
		}
		dep[a] = 0, dfs(a, a);
		int len = dep[b];
		if (len <= da) {
			printf("Alice\n");
			continue;
		}
		if (db - da <= da) {
			printf("Alice\n");
			continue;
		}
		int rt = -1;
		for (int i = 1; i <= n; i++) {
			if (rt == -1 || dep[i] > dep[rt]) rt = i;
		}
		dep[rt] = 0, dfs(rt, rt);
		int maxj = 0;
		for (int i = 1; i <= n; i++) {
			maxj = max(maxj, dep[i]);
		}
		len = da;
		if (len + da < maxj) {
			printf("Bob\n");
			continue;
		}
		printf("Alice\n");
	}
	return 0;
}