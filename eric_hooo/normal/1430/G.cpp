#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

struct Min_cost_max_flow {
	int head[110], to[100000], nxt[100000];
	int w[100000];
	int f[100000], TOT, n;
	int cur[110], dist[110], path[110], edge[110], inq[110];
	queue <int> q;
	void init(int N) {n = N, TOT = 0; for (int i = 0; i < n; i++) head[i] = -1;}
	void add_edge(int x, int y, int W, int F) {
		to[TOT] = y, w[TOT] = W, f[TOT] = F, nxt[TOT] = head[x], head[x] = TOT++;
		to[TOT] = x, w[TOT] = 0, f[TOT] = -F, nxt[TOT] = head[y], head[y] = TOT++;
	}
	bool spfa(int S, int T) {
		for (int i = 0; i < n; i++) dist[i] = 0x3f3f3f3f;
		dist[S] = 0, q.push(S), inq[S] = 1;
		while (!q.empty()) {
			int x = q.front(); q.pop(), inq[x] = 0;
			for (int i = head[x]; ~i; i = nxt[i]) {
				if (!w[i]) continue;
				int v = to[i];
				if (dist[v] > dist[x] + f[i]) {
					dist[v] = dist[x] + f[i], path[v] = x, edge[v] = i;
					if (!inq[v]) q.push(v), inq[v] = 1;
				}
			}
		}
		return dist[T] != 0x3f3f3f3f;
	}
	void min_cost_max_flow(int S, int T) {
		while (spfa(S, T)) {
			int flow = INF; int cur = T;
			while (cur != S) flow = min(flow, w[edge[cur]]), cur = path[cur];
			cur = T;
			while (cur != S) w[edge[cur]] -= flow, w[edge[cur] ^ 1] += flow, cur = path[cur];
		}
	}
}mcmf;

int sum[110];
int dist[110][110];

int main() {
	memset(dist, 0x3f, sizeof(dist));
	int n, m; scanf("%d%d", &n, &m);
	int S = 0, T = n + 1; mcmf.init(T + 1);
	for (int i = 1; i <= n; i++) dist[i][i] = dist[i][0] = 0;
	for (int i = 1; i <= m; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		mcmf.add_edge(x, y, INF, -1), sum[x] += w, sum[y] -= w;
		dist[x][y] = -1;
	}
	for (int i = 1; i <= n; i++) {
		if (sum[i] > 0) mcmf.add_edge(S, i, sum[i], 0);
		else mcmf.add_edge(i, T, -sum[i], 0);
	}
	mcmf.min_cost_max_flow(S, T);
	for (int i = 1; i <= n; i++) {
		for (int j = mcmf.head[i]; ~j; j = mcmf.nxt[j]) {
			if (j % 2 == 0 && mcmf.w[j] != INF && mcmf.to[j] != T) {
				dist[mcmf.to[j]][i] = 1;
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", -dist[i][0]), printf("\n");
	return 0;
}