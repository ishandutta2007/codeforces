#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int INF = 0x3f3f3f3f;

typedef pair <int, int> pii;

struct MCMF {
	int head[110], nxt[100000], to[100000], W[100000], F[100000], TOT;
	int inq[110], dist[110], lst[110], edg[110];
	queue <int> q;
	void clear() {memset(head, -1, sizeof(head)), TOT = 0;}
	void AddEdge(int x, int y, int w, int f) {
		to[TOT] = y, W[TOT] = w, F[TOT] = f, nxt[TOT] = head[x], head[x] = TOT++;
		to[TOT] = x, W[TOT] = 0, F[TOT] = -f, nxt[TOT] = head[y], head[y] = TOT++;
	}
	bool spfa(int S, int T) {
		memset(dist, 0x3f, sizeof(dist)), dist[S] = 0, inq[S] = 1, q.push(S);
		while (!q.empty()) {
			int x = q.front(); q.pop(), inq[x] = 0;
			for (int i = head[x]; ~i; i = nxt[i]) {
				int v = to[i], w = W[i], f = F[i];
				if (w && dist[v] > dist[x] + f) {
					dist[v] = dist[x] + f, lst[v] = x, edg[v] = i;
					if (!inq[v]) q.push(v), inq[v] = 1;
				}
			}
		}
		return dist[T] != INF;
	}
	pii MinCostMaxFlow(int S, int T) {
		pii ans(0, 0);
		while (spfa(S, T)) {
			int flow = INF, x = T;
			while (x != S) flow = min(flow, W[edg[x]]), x = lst[x];
			ans.fi += flow, ans.se += flow * dist[T], x = T;
			while (x != S) W[edg[x]] -= flow, W[edg[x] ^ 1] += flow, x = lst[x];
		}
		return ans;
	}
}mcmf;

int L[60], R[60];
int n, q;

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		L[i] = 1, R[i] = n;
	}
	while (q--) {
		int op, l, r, x; scanf("%d%d%d%d", &op, &l, &r, &x);
		if (op == 1) {
			for (int i = l; i <= r; i++) {
				L[i] = max(L[i], x);
			}
		} else {
			for (int i = l; i <= r; i++) {
				R[i] = min(R[i], x);
			}
		}
	}
	mcmf.clear();
	int S = 0, T = n + n + 1;
	for (int i = 1; i <= n; i++) {
		mcmf.AddEdge(S, i, 1, 0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (L[i] <= j && j <= R[i]) mcmf.AddEdge(i, n + j, 1, 0);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mcmf.AddEdge(n + i, T, 1, j * 2 - 1);
		}
	}
	pii tmp = mcmf.MinCostMaxFlow(S, T);
	if (tmp.fi < n) printf("-1\n");
	else printf("%d\n", tmp.se);
	return 0;
}