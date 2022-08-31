#include <cstdio>

#include <algorithm>

#define LOG(FMT...) // fprintf(stderr, FMT)

using namespace std;

struct node {
	int id, w;
	
	bool operator<(const node& x) const
	{ return w < x.w; } 
};

struct edge {
	int v;
	bool pred;
	edge *next, *rev;
};

struct query {
	int qi, ei;
	
	bool operator<(const query& x) const;
};

const int N = 500010;

int n, m, q;
int eu[N], ev[N], ew[N], f[N], rk[N];
node e[N];
query qu[N];
bool ans[N], vis[N];
edge* g[N];

void link(int u, int v);
edge* add_edge(int u, int v);
int find(int x);
void merge(int x, int y);
bool dfs(int u);

int main() {
	int cnt = 0, k, l, r;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		e[i].id = i;
		scanf("%d%d%d", &eu[i], &ev[i], &e[i].w);
		ew[i] = e[i].w;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d", &k);
		while (k--) {
			++cnt;
			qu[cnt].qi = i;
			scanf("%d", &qu[cnt].ei);
		}
	}
	
	sort(e + 1, e + m + 1);
	stable_sort(qu + 1, qu + cnt + 1);
	l = 1;
	for (int i = 1; i <= n; ++i)
		f[i] = i;
	for (int i = 1; i <= m; ++i) {
		if (e[i].w != e[i - 1].w)
			while (ew[qu[l].ei] == e[i].w) {
				r = l;
				while (r <= cnt &&
				       ew[qu[r + 1].ei] == e[i].w &&
				       qu[r + 1].qi == qu[r].qi)
					++r;
				for (int j = l; j <= r; ++j)
					link(find(eu[qu[j].ei]), find(ev[qu[j].ei]));
				for (int j = l; j <= r; ++j)
					if (!vis[find(eu[qu[j].ei])])
						if (dfs(find(eu[qu[j].ei]))) {
							ans[qu[j].qi] = true;
							break;
						}
				for (int j = l; j <= r; ++j) {
					g[find(eu[qu[j].ei])] = NULL;
					g[find(ev[qu[j].ei])] = NULL;
					vis[find(eu[qu[j].ei])] = false;
					vis[find(ev[qu[j].ei])] = false;
				}
				LOG("%d %d\n", l, r);
				l = r + 1;
			}
		merge(eu[e[i].id], ev[e[i].id]);
	}
	
	for (int i = 1; i <= q; ++i)
		puts(ans[i] ? "NO" : "YES");
	return 0;
}

inline edge* add_edge(int u, int v) {
	static edge pool[N << 1];
	static edge* p = pool;
	++p;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	return p;
}

inline void link(int u, int v) {
	LOG("[INFO] LINKING %d %d\n", u, v);
	edge *p = add_edge(u, v), *q = add_edge(v, u);
	p->rev = q;
	q->rev = p;
}

int find(int x) {
	if (f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

inline void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (rk[x] < rk[y])
		f[x] = y;
	else if (rk[y] < rk[x])
		f[y] = x;
	else {
		++rk[y];
		f[x] = y;
	}
}

bool dfs(int u) {
	if (vis[u])
		return true;
	vis[u] = true;
	for (edge* p = g[u]; p; p = p->next)
		if(!p->pred) {
			p->rev->pred = true;
			if (dfs(p->v))
				return true;
		}
	return false;
}

bool query::operator<(const query& x) const
{ return ew[ei] < ew[x.ei]; }