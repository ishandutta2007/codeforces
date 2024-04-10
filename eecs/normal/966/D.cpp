#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, m, tot, id[maxn], sz[maxn], dist[maxn], col[maxn], pre[maxn], tag[maxn];
vector<int> G[maxn];
queue<int> Q;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	auto bfs = [&](int v) {
		memset(dist, -1, sizeof(dist));
		pre[v] = dist[v] = 0, Q.push(v);
		while (!Q.empty()) {
			int v = Q.front(); Q.pop();
			for (int u : G[v]) if (col[u] && !~dist[u]) {
				dist[u] = dist[v] + 1;
				pre[u] = v, Q.push(u);
			}
		}
	};
	function<void(int)> dfs = [&](int v) {
		id[v] = tot, sz[tot]++;
		for (int u : G[v]) if (tag[u] && !id[u]) dfs(u);
	};
	fill(col + 1, col + n + 1, 1), bfs(1);
	if (~dist[n] && dist[n] <= 4) {
		printf("%d\n", dist[n]);
		vector<int> ans;
		for (int i = n; i; i = pre[i]) ans.push_back(i);
		reverse(ans.begin(), ans.end());
		for (int x : ans) printf("%d ", x);
		exit(0);
	}
	for (int i : G[1]) tag[i] = 1;
	for (int i : G[1]) for (int j : G[i]) if (j ^ 1 && !tag[j]) {
		puts("4");
		printf("1 %d %d 1 %d\n", i, j, n), exit(0);
	}
	for (int i : G[1]) {
		if (!id[i]) tot++, dfs(i);
		int s = 0;
		for (int j : G[i]) s += (id[i] == id[j]);
		if (s >= sz[id[i]] - 1) continue;
		for (int j = 1; j <= n; j++) col[j] = id[i] == id[j];
		bfs(i);
		for (int j = 1; j <= n; j++) if (dist[j] == 2) {
			puts("5");
			printf("1 %d %d %d %d %d\n", i, pre[j], j, i, n);
			exit(0);
		}
	}
	puts("-1");
	return 0;
}