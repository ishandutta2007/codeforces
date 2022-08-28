#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Edge {
	int v, w;
	Edge* next;
};

const int N = 100010, V = 45, LGN = 18;

int n, m, cnt;
int eu[V], ev[V], ew[V], uu[V];
ll mg[V][V];
bool vis[N], relax[V];
int f[N], dep[N];
int prt[N][LGN];
ll dis[N];
ll pre[N][V];
Edge* g[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void dfs(int u);
void adde(int u, int v, int w);
ll dist(int u, int v);

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &m);
	iota(f + 1, f + n + 1, 1);
	while (m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if (find(u) != find(v)) {
			f[f[u]] = f[v];
			adde(u, v, w);
			adde(v, u, w);
		} else {
			++cnt;
			eu[cnt] = u;
			ev[cnt] = v;
			ew[cnt] = w;
			uu[cnt * 2 - 1] = u;
			uu[cnt * 2] = v;
		}
	}
	dfs(1);
	for (int i = 1; i <= cnt * 2; ++i)
		for (int j = i; j <= cnt * 2; ++j)
			mg[i][j] = mg[j][i] = dist(uu[i], uu[j]);
	for (int i = 1; i <= cnt; ++i)
		mg[i * 2 - 1][i * 2] = mg[i * 2][i * 2 - 1] = min(mg[i * 2 - 1][i * 2], (ll)ew[i]);
	for (int u = 1; u <= n; ++u) {
		memset(relax, 0, sizeof(relax));
		for (int i = 1; i <= cnt * 2; ++i)
			pre[u][i] = dist(u, uu[i]);
		for (int rep = 0; rep < cnt * 2; ++rep) {
			int chose = 0;
			for (int i = 1; i <= cnt * 2; ++i)
				if (!relax[i] && (chose == 0 || pre[u][chose] > pre[u][i]))
					chose = i;
			relax[chose] = true;
			for (int j = 1; j <= cnt * 2; ++j)
				pre[u][j] = min(pre[u][j], pre[u][chose] + mg[chose][j]);
		}
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		ll ans = dist(u, v);
		for (int i = 1; i <= cnt * 2; ++i)
			ans = min(ans, pre[u][i] + pre[v][i]);
		printf("%lld\n", ans);
	}
#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

ll dist(int u, int v) {
	ll ret = dis[u] + dis[v];
	if (dep[u] > dep[v])
		swap(u, v);
	for (int k = 0; k < LGN; ++k)
		if (((dep[v] - dep[u]) >> k) & 1)
			v = prt[v][k];
	if (u == v)
		return ret - dis[u] * 2;
	for (int k = LGN - 1; k >= 0; --k)
		if (prt[u][k] != prt[v][k]) {
			u = prt[u][k];
			v = prt[v][k];
		}
	return ret - dis[prt[u][0]] * 2;
}

void adde(int u, int v, int w) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->w = w;
	p->next = g[u];
	g[u] = p;
	++p;
}

void dfs(int u) {
	vis[u] = true;
	for (int i = 1; i < LGN; ++i)
		prt[u][i] = prt[prt[u][i - 1]][i - 1];
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v]) {
			dep[p->v] = dep[u] + 1;
			dis[p->v] = dis[u] + p->w;
			prt[p->v][0] = u;
			dfs(p->v);
		}
}