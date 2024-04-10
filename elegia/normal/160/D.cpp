#include <cstdio>

#include <algorithm>
#include <stack>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

struct Edge {
	int u, v, w, id;
	
	bool operator<(const Edge& rhs) const { return w < rhs.w; }
};

struct Ed {
	int u, v;
	bool f;
	Ed *next, *rev;
};

const int N = 100010;

int n, m;

int f[N];
int ans[N];
Edge g[N];
int low[N], dfn[N];
Ed* gg[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

Ed* adde(int u, int v);
void link(int u, int v);
void dfs(int u);

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &g[i].u, &g[i].v, &g[i].w);
		g[i].id = i;
	}
	sort(g + 1, g + m + 1);
	g[m + 1].w = -1;
	for (int i = 1; i <= n; ++i)
		f[i] = i;
	for (int l = 1, r; l <= m; l = r + 1) {
		for (r = l; g[r].w == g[l].w; ++r);
		--r;
		for (int i = l; i <= r; ++i)
			if (find(g[i].u) == find(g[i].v))
				ans[g[i].id] = -1;
			else
				link(find(g[i].u), find(g[i].v));
		for (int i = l; i <= r; ++i)
			if (!dfn[find(g[i].u)])
				dfs(find(g[i].u));
		for (int i = l; i <= r; ++i) {
			if (low[find(g[i].u)] != low[find(g[i].v)])
				ans[g[i].id] = 1;
		}
		for (int i = l; i <= r; ++i) {
			dfn[find(g[i].u)] = 0;
			dfn[find(g[i].v)] = 0;
			gg[find(g[i].u)] = NULL;
			gg[find(g[i].v)] = NULL;
		}
		for (int i = l; i <= r; ++i)
			f[find(g[i].u)] = find(g[i].v);
	}
	for (int i = 1; i <= m; ++i) {
		if (ans[i] == -1)
			puts("none");
		else if (ans[i] == 1)
			puts("any");
		else
			puts("at least one");
	}
	return 0;
}

Ed* adde(int u, int v) {
	static Ed pool[N * 2];
	static Ed* p = pool;
	p->v = v;
	p->next = gg[u];
	gg[u] = p;
	return p++;
}

void link(int u, int v) {
	Ed *p = adde(u, v),
	   *q = adde(v, u);
	p->rev = q;
	q->rev = p;
}

void dfs(int u) {
	static int t;
	static bool instk[N];
	static stack<int> stk;
	dfn[u] = low[u] = ++t;
	stk.push(u);
	instk[u] = true;
	for (Ed* p = gg[u]; p; p = p->next) {
		if (p->f)
			continue;
		p->rev->f = true;
		if (!dfn[p->v]) {
			dfs(p->v);
			if (instk[p->v])
				low[u] = min(low[u], low[p->v]);
		} else {
			if (instk[p->v])
				low[u] = min(low[u], low[p->v]);
		}
	}
	if (low[u] != dfn[u])
		return;
	int v;
	do {
		v = stk.top();
		stk.pop();
		low[v] = dfn[u];
		instk[v] = false;
	} while (u != v);
}