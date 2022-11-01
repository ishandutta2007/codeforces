#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

template<typename T> struct Dinic {
	static const int MAXN = 3005, MAXM = 1000005;
	struct Edge { int to, next; T cap; } edge[MAXM];
	int head[MAXN], tot;
	void clear() { memset(head, -1, sizeof(head)); tot = 0; }
	Dinic() { clear(); }
	void add(int u, int v, T c) {
		edge[tot] = (Edge) { v, head[u], c };
		head[u] = tot++;
		edge[tot] = (Edge) { u, head[v], (T)0 };
		head[v] = tot++;
	}
	int dis[MAXN], que[MAXN], id[MAXN];
	bool bfs(int s, int t) {
		memset(dis, -1, sizeof(dis));
		memcpy(id, head, sizeof(id));
		int he = 0, ta = 0;
		dis[que[ta++] = s] = 0;
		while (he < ta) {
			int u = que[he++];
			for (int i = head[u]; ~i; i = edge[i].next) {
				int v = edge[i].to;
				if (dis[v] < 0 && edge[i].cap) {
					dis[que[ta++] = v] = dis[u] + 1;
					if (v == t) return true;
				}
			}
		}
		return false;
	}
	T dfs(int u, int t, T f) {
		if (u == t) return f;
		T flow = 0;
		for (int &i = id[u]; ~i; i = edge[i].next) {
			int v = edge[i].to;
			if (dis[v] > dis[u] && edge[i].cap) {
				int d = dfs(v, t, min(f, edge[i].cap));
				if (!d) continue;
				edge[i].cap -= d, edge[i ^ 1].cap += d;
				flow += d, f -= d;
				if (f == 0) return flow;
			}
		}
		dis[u] = -1; return flow;
	}
	T dinic(int s, int t, T inf = 1E9) {
		T flow = 0;
		while (bfs(s, t))
			flow += dfs(s, t, inf);
		return flow;
	}
};
Dinic<int> din;

const int MAXN = 3005;
int n, a[MAXN], b[MAXN], lst[105];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		for (int j = 1; j <= 100; j++)
			if (a[i] % j == 0 && lst[j]) din.add(i, lst[j], 1e9);
		lst[a[i]] = i;
	}
	int s = n + 1, t = n + 2, ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
		if (b[i] >= 0) din.add(s, i, b[i]), ans += b[i];
		else din.add(i, t, -b[i]);
	}
	printf("%d\n", ans - din.dinic(s, t));
	return 0;
}