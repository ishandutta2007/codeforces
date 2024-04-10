#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

int a[3010];

struct Min_cost {
	int head[6010], dist[6010], path[6010], edge[6010], H[6010];
	int nxt[100010], to[100010], w[100010], f[100010];
	int tot;
	priority_queue <pii, vector <pii>, greater <pii> > q;
	void init() {tot = 0, memset(head, -1, sizeof(head));}
	void add(int x, int y, int W, int F) {
		to[tot] = y, w[tot] = W, f[tot] = F, nxt[tot] = head[x], head[x] = tot++;
		to[tot] = x, w[tot] = 0, f[tot] = -F, nxt[tot] = head[y], head[y] = tot++;
	}
	bool Dij(int S, int T) {
		memset(dist, INF, sizeof(dist));
		memset(path, -1, sizeof(path));
		dist[S] = -H[S], q.push(mp(dist[S], S));
		while (!q.empty()) {
			pii t = q.top(); q.pop();
			int x = t.se;
			if (dist[x] != t.fi) continue;
			for (int i = head[x]; ~i; i = nxt[i]) {
				int v = to[i];
				if (!w[i]) continue;
				if (dist[v] > dist[x] + f[i] + H[x] - H[v]) {
					dist[v] = dist[x] + f[i] + H[x] - H[v];
					path[v] = x, edge[v] = i;
					q.push(mp(dist[v], v));
				}
			}
		}
		return ~path[T];
	}
	int min_cost(int S, int T) {
		int res = 0;
		for (int it = 0; it < 4; it++) {
			Dij(S, T);
			res += dist[T] + H[T];
			int now = T;
			while (now != S) {
				int e = edge[now];
				w[e]--, w[e ^ 1]++;
				now = path[now];
			}
			for (int i = 0; i <= T; i++) {
				H[i] += dist[i];
			}
		}
		return res;
	}
}min_cost;

vector <int> np[7], nnp[7];
vector <int> nq[100010], nnq[100010];

int get_pos(const vector <int> &v, int x) {
	return upper_bound(v.begin(), v.end(), x) - v.begin();
}

void add_edge(const vector <int> &v, int x) {
	int pos;
	for (int i = pos = get_pos(v, x); i < pos + 4 && i < v.size(); i++) {
		min_cost.add(2 * x, 2 * v[i] - 1, 1, 0);
	}
}

int main () {
	int n; scanf("%d", &n);
	min_cost.init();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		np[a[i] % 7].push_back(i);
		nq[a[i]].push_back(i);
	}
	int S = 0, T = 2 * n + 1;
	for (int i = 1; i <= n; i++) {
		min_cost.add(S, 2 * i - 1, 1, 0);
		min_cost.add(2 * i - 1, 2 * i, 1, -1);
		min_cost.add(2 * i, T, 1, 0);
		add_edge(np[a[i] % 7], i), add_edge(nq[a[i] + 1], i), add_edge(nq[a[i] - 1], i);
	}
	printf("%d\n", -min_cost.min_cost(S, T));
	return 0;
}