#include <cstdio>

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;

struct Edge {
	int v, w;
	Edge* next;
};

const int N = 400010;

int n, q;
ll sub[N], lk[N], spec[N], asum[N], wsum[N];
int a[N], f[N], prt[N], prtw[N], qu[N], qv[N], lca[N], ord[N];
Edge* g[N];
vector<pair<int, int> > qry[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void adde(int u, int v, int w);
void tarjan(int u);
void dfs(int u);

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int rep = 1; rep < n; ++rep) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adde(u, v, w);
		adde(v, u, w);
	}
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &qu[i], &qv[i]);
		qry[qu[i]].emplace_back(qv[i], i);
		qry[qv[i]].emplace_back(qu[i], i);
	}
	tarjan(1);
	dfs(1);
	for (int i = 2; i <= n; ++i) {
		int u = ord[i];
		spec[u] = max(0LL, spec[prt[u]] + a[prt[u]] - 2 * prtw[u] + sub[prt[u]] - lk[u]);
	}
	copy(a + 1, a + n + 1, asum + 1);
	copy(prtw + 1, prtw + n + 1, wsum + 1);
	for (int i = 2; i <= n; ++i) {
		int u = ord[i];
		sub[u] += sub[prt[u]];
		lk[u] += lk[prt[u]];
		asum[u] += asum[prt[u]];
		wsum[u] += wsum[prt[u]];
	}
	for (int i = 1; i <= q; ++i) {
		int u = qu[i], v = qv[i], l = lca[i];
		printf("%lld\n", sub[u] - sub[prt[l]] + sub[v] - sub[l] - (lk[u] + lk[v] - 2 * lk[l]) + spec[l] + 
		                (asum[u] - asum[prt[l]] + asum[v] - asum[l]) - (wsum[u] + wsum[v] - 2 * wsum[l]));
	}
	return 0;
}

void dfs(int u) {
	static int t;
	ord[++t] = u;
	for (Edge* p = g[u]; p; p = p->next)
		if (prt[p->v] == u) {
			dfs(p->v);
			lk[p->v] = max(0LL, sub[p->v] + a[p->v] - 2 * p->w);
			sub[u] += lk[p->v];
		}
}

void tarjan(int u) {
	f[u] = u;
	for (Edge* p = g[u]; p; p = p->next)
		if (!f[p->v]) {
			prt[p->v] = u;
			prtw[p->v] = p->w;
			tarjan(p->v);
			f[p->v] = u;
		}
	for (auto q : qry[u])
		if (f[q.first])
			lca[q.second] = find(q.first);
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