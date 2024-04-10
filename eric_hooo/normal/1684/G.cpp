#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

namespace Dinic {
	int head[1010], nxt[2000010], to[2000010], W[2000010], TOT;
	int dep[1010], cur[1010];
	void Init() {memset(head, -1, sizeof(head)), TOT = 0;}
	int AddEdge(int x, int y, int w) {
		to[TOT] = y, W[TOT] = w, nxt[TOT] = head[x], head[x] = TOT++;
		to[TOT] = x, W[TOT] = 0, nxt[TOT] = head[y], head[y] = TOT++;
		return TOT - 1;
	}
	bool bfs(int S, int T) {
		static queue <int> q;
		memset(dep, -1, sizeof(dep)), dep[S] = 0, q.push(S);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int e = head[x]; ~e; e = nxt[e]) {
				int v = to[e], w = W[e];
				if (!w || dep[v] != -1) continue;
				dep[v] = dep[x] + 1, q.push(v);
			}
		}
		return dep[T] != -1;
	}
	int dfs(int x, int T, int flow) {
		if (x == T) return flow;
		int res = 0;
		for (int &e = cur[x]; ~e; e = nxt[e]) {
			int v = to[e], w = W[e];
			if (!w || dep[v] != dep[x] + 1) continue;
			int tmp = dfs(v, T, min(flow, w));
			W[e] -= tmp, W[e ^ 1] += tmp;
			flow -= tmp, res += tmp;
			if (!flow) break;
		}
		return res;
	}
	int MaxFlow(int S, int T) {
		int ans = 0;
		while (bfs(S, T)) {
			memcpy(cur, head, sizeof(cur));
			ans += dfs(S, T, 0x3f3f3f3f);
		}
		return ans;
	}
}

int n, m;
int a[1010];
int id[1010][1010];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] * 2 + 1 > m) {
			printf("-1\n");
			return 0;
		}
	}
	int S = 0, T = n + 1;
	Dinic :: Init();
	for (int i = 1; i <= n; i++) {
		if (a[i] * 3 <= m) Dinic :: AddEdge(S, i, 1);
		else Dinic :: AddEdge(i, T, 1);
	}
	for (int i = 1; i <= n; i++) if (a[i] * 3 <= m) {
		for (int j = 1; j <= n; j++) if (a[j] * 3 > m) {
			if (a[j] % a[i] == 0 && a[j] * 2 + a[i] <= m) id[i][j] = Dinic :: AddEdge(i, j, 1);
		}
	}
	int tot = Dinic :: MaxFlow(S, T);
	for (int i = 1; i <= n; i++) {
		if (a[i] * 3 > m) tot--;
	}
	if (tot < 0) {
		printf("-1\n");
		return 0;
	}
	vector <pii> ans;
	static int vis[1010];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (id[i][j] && Dinic :: W[id[i][j]]) {
				vis[i] = 1, vis[j] = 1, ans.push_back(mp(a[j] + a[i], a[j] * 2 + a[i]));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			ans.push_back(mp(a[i] * 2, a[i] * 3));
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto it : ans) {
		printf("%d %d\n", it.fi, it.se);
	}
	return 0;
}