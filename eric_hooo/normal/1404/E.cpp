#include <bits/stdc++.h>
using namespace std;

char a[210][210];
int vis[410][410], ID[410][410];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int head[160010], to[1280000], nxt[1280000], w[1280000], TOT, cur[160010], dep[160010];
int S, T;
queue <int> q;

void add_edge(int x, int y, int W) {
	to[TOT] = y, nxt[TOT] = head[x], w[TOT] = W, head[x] = TOT++;
	to[TOT] = x, nxt[TOT] = head[y], w[TOT] = 0, head[y] = TOT++;
}

bool bfs() {
	memset(dep, -1, sizeof(dep));
	q.push(S), dep[S] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; ~i; i = nxt[i]) {
			int v = to[i];
			if (!w[i]) continue;
			if (dep[v] == -1) {
				dep[v] = dep[x] + 1;
				q.push(v);
			}
		}
	}
	return ~dep[T];
}

int dfs(int x, int flow) {
	if (!flow || x == T) return flow;
	int res = 0;
	for (int &i = cur[x]; ~i; i = nxt[i]) {
		int v = to[i];
		if (!w[i] || dep[v] != dep[x] + 1) continue;
		int tmp = dfs(v, min(flow, w[i]));
		if (!tmp) continue;
		flow -= tmp, w[i] -= tmp;
		res += tmp, w[i ^ 1] += tmp;
		if (!flow) break;
	}
	return res;
}

int max_flow() {
	int res = 0;
	while (bfs()) {
		memcpy(cur, head, sizeof(head));
		res += dfs(S, 0x3f3f3f3f);
	}
	return res;
}

int main () {
	memset(head, -1, sizeof(head));
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != '#') continue;
			sum++;
			for (int k = 0; k < 4; k++) {
				int x = i + dir[k][0], y = j + dir[k][1];
				if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] != '#') continue;
				vis[i + x][j + y] = 1;
			}
		}
	}
	int tot = 0;
	for (int i = 0; i < n + n; i++) {
		for (int j = 0; j < m + m; j++) {
			if (vis[i][j]) ID[i][j] = tot, tot += vis[i][j];
		}
	}
	S = tot++, T = tot++;
	for (int i = 0; i < n + n; i++) {
		for (int j = 0; j < m + m; j++) {
			if (!vis[i][j] || (i & 1)) {
				if (vis[i][j]) add_edge(ID[i][j], T, 1);
				continue;
			}
			add_edge(S, ID[i][j], 1);
			for (int dx = -1; dx <= 1; dx += 2) {
				for (int dy = -1; dy <= 1; dy += 2) {
					int x = i + dx, y = j + dy;
					if (x < 0 || y < 0 || !vis[x][y]) continue;
					add_edge(ID[i][j], ID[x][y], 1);
				}
			}
		}
	}
	printf("%d\n", sum - (tot - 2 - max_flow()));
	return 0;
}