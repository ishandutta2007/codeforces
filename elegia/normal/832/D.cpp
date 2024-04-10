#include <cstdio>

#include <algorithm>
#include <vector>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

struct Edge {
	int v;
	Edge* next;
};

const int N = 100010;

int n, q;
int dep[N];
int qa[N], qb[N], qc[N];
int f[N], rk[N], ver[N];
int lca[N * 3];
Edge* g[N];
vector<pair<int, int> > qry[N];

void adde(int u, int v);

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void merge(int x, int y);
void dfs(int u);

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; ++i) {
		int pt;
		scanf("%d", &pt);
		adde(pt, i);
	}
	for (int i = 1; i <= q; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		qa[i] = a;
		qb[i] = b;
		qc[i] = c;
		qry[a].push_back(make_pair(b, i * 3 - 2));
		qry[b].push_back(make_pair(a, i * 3 - 2));
		qry[a].push_back(make_pair(c, i * 3 - 1));
		qry[c].push_back(make_pair(a, i * 3 - 1));
		qry[b].push_back(make_pair(c, i * 3));
		qry[c].push_back(make_pair(b, i * 3));
	}
	dfs(1);
	for (int i = 1; i <= q; ++i) {
		int a = qa[i], b = qb[i], c = qc[i],
		    lab = lca[i * 3 - 2], lac = lca[i * 3 - 1], lbc = lca[i * 3];
		int ans = 0;
		ans = max(ans, min(dep[a] - dep[lab], dep[a] - dep[lac]));
		if (lab == lac)
			ans = max(ans, dep[a] - dep[lab] * 2 + dep[lbc]);
		ans = max(ans, min(dep[b] - dep[lab], dep[b] - dep[lbc]));
		if (lab == lbc)
			ans = max(ans, dep[b] - dep[lab] * 2 + dep[lac]);
		ans = max(ans, min(dep[c] - dep[lac], dep[c] - dep[lbc]));
		if (lac == lbc)
			ans = max(ans, dep[c] - dep[lac] * 2 + dep[lab]);
		++ans;
		printf("%d\n", ans);
	}
	return 0;
}

void dfs(int u) {
	f[u] = u;
	ver[u] = u;
	for (Edge* p = g[u]; p; p = p->next) {
		dep[p->v] = dep[u] + 1;
		dfs(p->v);
		merge(u, p->v);
		ver[find(u)] = u;
	}
	for (vector<pair<int, int> >::iterator it = qry[u].begin(); it != qry[u].end(); ++it)
		if (f[it->first])
			lca[it->second] = ver[find(it->first)];
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (rk[x] < rk[y]) {
		f[x] = y;
	} else if (rk[x] > rk[y])
		f[y] = x;
	else {
		++rk[x];
		f[y] = x;
	}
}

void adde(int u, int v) {
	static Edge pool[N];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}