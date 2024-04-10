#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> ppp;

struct Dinic {
	int head[20010], cur[20010], S, T, tot;
	int nxt[300010], to[300010], w[300010];
	int q[20010], l, r, dep[20010];
	void clear() {
		memset(head, -1, sizeof(head)), tot = 0;
	}
	void add(int x, int y, int W) {
		to[tot] = y, nxt[tot] = head[x], w[tot] = W, head[x] = tot++;
		to[tot] = x, nxt[tot] = head[y], w[tot] = 0, head[y] = tot++;
	}
	bool bfs() {
		memset(dep, -1, sizeof(dep));
		l = r = 0, q[r++] = S, dep[S] = 0;
		while (l < r) {
			int x = q[l++];
			for (int i = head[x]; ~i; i = nxt[i]) {
				int v = to[i];
				if (!w[i] || ~dep[v]) continue;
				dep[v] = dep[x] + 1;
				q[r++] = v;
			}
		}
		return dep[T] != -1;
	}
	int dfs(int x, int flow) {
		if (!flow || x == T) return flow;
		int res = 0;
		for (int &i = cur[x]; ~i; i = nxt[i]) {
			int v = to[i];
			if (!w[i] || dep[v] != dep[x] + 1) continue;
			int tmp = dfs(v, min(flow, w[i]));
			if (!tmp) continue;
			flow -= tmp, res += tmp;
			w[i] -= tmp, w[i ^ 1] += tmp;
			if (!flow) break;
		}
		return res;
	}
	int max_flow() {
		int flow = 0;
		while (bfs()) {
			memcpy(cur, head, sizeof(head));
			flow += dfs(S, 0x3f3f3f3f);
		}
		return flow;
	}
}dinic;

vector <ppp> edge;

int main () {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		x--, y--;
		edge.push_back(mp(w, mp(x, y)));
	}
	sort(edge.begin(), edge.end());
	int l = n - 1, r = m;
	while (l < r) {
		int mid = l + r >> 1;
		dinic.clear(), dinic.S = 20005, dinic.T = 20006;
		for (int i = 0; i <= mid; i++) {
			dinic.add(edge[i].se.fi, edge[i].se.se + n, 1);
		}
		for (int i = 0; i < n; i++) {
			dinic.add(dinic.S, i, 1);
			dinic.add(i + n, dinic.T, 1);
		}
		if (dinic.max_flow() == n) r = mid;
		else l = mid + 1;
	}
	if (l == m) printf("-1\n");
	else printf("%d\n", edge[l].fi);
	return 0;
}