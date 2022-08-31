#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

typedef long long ll;

struct node {
	int u, a;
	
	bool operator<(const node& x) const {
		return a < x.a;
	}
};

struct edge {
	int v;
	edge* next;
};

const int N = 1 << 20;

int n;
int rk[N], k[N], sz[N], prt[N];
edge* g[N];
node ver[N];

void add_edge(int u, int v);
int find(int x);
void merge(int x, int y);
void reset_dsu();

int main() {
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ver[i].a);
		ver[i].u = i;
	}
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	sort(ver + 1, ver + n + 1);
	for (int i = 1; i <= n; ++i)
		k[ver[i].u] = i;
	reset_dsu();
	for (int i = 1; i <= n; ++i) {
		int u = ver[i].u;
		for (edge* p = g[u]; p; p = p->next)
			if (k[p->v] < k[u]) {
				ans += (ll)sz[find(u)] * sz[find(p->v)] * ver[i].a;
				merge(p->v, u);
			}
	}
	reset_dsu();
	for (int i = n; i; --i) {
		int u = ver[i].u;
		for (edge* p = g[u]; p; p = p->next)
			if (k[p->v] > k[u]) {
				ans -= (ll)sz[find(u)] * sz[find(p->v)] * ver[i].a;
				merge(p->v, u);
			}
	}
	printf("%lld\n", ans);
	return 0;
}

void reset_dsu() {
	memset(rk, 0, sizeof(rk));
	fill(sz + 1, sz + n + 1, 1);
	for (int i = 1; i <= n; ++i)
		prt[i] = i;
}

int find(int x) {
	if (prt[x] == x)
		return x;
	return prt[x] = find(prt[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (rk[x] < rk[y]) {
		prt[x] = y;
		sz[y] += sz[x];
	} else if (rk[x] > rk[y]) {
		prt[y] = x;
		sz[x] += sz[y];
	} else {
		prt[x] = y;
		++rk[x];
		sz[y] += sz[x];
	}
}

void add_edge(int u, int v) {
	static edge pool[N * 2];
	static edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}