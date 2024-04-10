#include <bits/stdc++.h>
using namespace std;

int n, m;
long long sum[60], N;

namespace MCMF {
	int head[60], to[100000], nxt[100000], W[100000], F[100000], TOT;
	int dist[60], inq[60], pth[60], edg[60];
	queue <int> q;
	void Init() {memset(head, -1, sizeof(head)), TOT = 0;}
	void AddEdge(int x, int y, int w, int f) {
		to[TOT] = y, W[TOT] = w, F[TOT] = f, nxt[TOT] = head[x], head[x] = TOT++;
		to[TOT] = x, W[TOT] = 0, F[TOT] = -f, nxt[TOT] = head[y], head[y] = TOT++;
	}
	bool spfa(int S, int T) {
		memset(dist, 0x3f, sizeof(dist)), dist[S] = 0, q.push(S), inq[S] = 1;
		while (!q.empty()) {
			int x = q.front(); q.pop(), inq[x] = 0;
			for (int e = head[x]; ~e; e = nxt[e]) {
				int v = to[e], w = W[e], f = F[e];
				if (w && dist[v] > dist[x] + f) {
					dist[v] = dist[x] + f, pth[v] = x, edg[v] = e;
					if (!inq[v]) inq[v] = 1, q.push(v);
				}
			}
		}
		return dist[T] != 0x3f3f3f3f;
	}
	void MinCostMaxFlow(int S, int T) {
		sum[0] = 0, N = 0;
		while (spfa(S, T)) {
			sum[N + 1] = sum[N] + dist[T], N++;
			int cur = T;
			while (cur != S) {
				W[edg[cur]]--, W[edg[cur] ^ 1]++;
				cur = pth[cur];
			}
		}
		assert(N <= n);
	}
}

int main() {
	MCMF :: Init();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		MCMF :: AddEdge(x, y, 1, w);
	}
	MCMF :: MinCostMaxFlow(1, n);
	int q; scanf("%d", &q);
	while (q--) {
		int x; scanf("%d", &x);
		double ans = 1e18;
		for (int i = 1; i <= N; i++) {
			ans = min(ans, (double)(x + sum[i]) / i);
		}
		printf("%.9f\n", ans);
	}
	return 0;
}