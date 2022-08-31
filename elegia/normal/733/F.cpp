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

struct Data {
	int v, id;
	
	Data() {}
	
	Data(int v, int id) : v(v), id(id) {}
	
	bool operator<(const Data& rhs) const { return v < rhs.v; }
};

struct Node {
	int u, v, w, c, id;
	
	bool operator<(const Node& rhs) const { return w < rhs.w; }
};

struct Edge {
	int v, w, id;
	Edge* next;
};

const int N = 200010, LGN = 18;

int n, m, s;

int f[N], dep[N];
int prt[N][LGN];
Data mx[N][LGN];
bool vis[N], coll[N];
Node ed[N];
Edge* g[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void dfs(int u);
void adde(int u, int v, int w, int id);

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &ed[i].w);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &ed[i].c);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d", &ed[i].u, &ed[i].v);
	for (int i = 1; i <= m; ++i)
		ed[i].id = i;
	scanf("%d", &s); 
	sort(ed + 1, ed + m + 1);
	ll sum = 0;
	int cnt = n;
	for (int i = 1; i <= n; ++i)
		f[i] = i;
	for (int i = 1; i <= m; ++i) {
		int x = find(ed[i].u), y = find(ed[i].v);
		if (x != y) {
			coll[ed[i].id] = true;
			f[x] = y;
			sum += ed[i].w;
			adde(ed[i].u, ed[i].v, ed[i].w, ed[i].id);
			adde(ed[i].v, ed[i].u, ed[i].w, ed[i].id);
			--cnt;
		}
	}
	dfs(1);
	int chose, rep;
	ll ans = numeric_limits<ll>::max();
	for (int i = 1; i <= m; ++i) {
		if (ed[i].u == ed[i].v)
			continue;
		int u = ed[i].u, v = ed[i].v;
		Data cov = Data(0, 0);
		if (dep[u] > dep[v])
			swap(u, v);
		for (int k = 0; k < LGN; ++k)
			if (((dep[v] - dep[u]) >> k) & 1) {
				cov = max(cov, mx[v][k]);
				v = prt[v][k];
			}
		if (u != v) {
			for (int k = LGN - 1; k >= 0; --k)
				if (prt[u][k] != prt[v][k]) {
					cov = max(cov, max(mx[u][k], mx[v][k]));
					u = prt[u][k];
					v = prt[v][k];
				}
			cov = max(cov, max(mx[u][0], mx[v][0]));
		}
		ll val = sum - cov.v + ed[i].w;
		if (val - s / ed[i].c < ans) {
			ans = val - s / ed[i].c;
			chose = ed[i].id;
			rep = cov.id;
		}
	}
	printf("%lld\n", ans);
	coll[rep] = false;
	coll[chose] = true;
	for (int i = 1; i <= m; ++i)
		if (coll[ed[i].id])
			if (ed[i].id == chose)
				printf("%d %d\n", ed[i].id, ed[i].w - s / ed[i].c);
			else
				printf("%d %d\n", ed[i].id, ed[i].w);

	return 0;
}

void dfs(int u) {
	vis[u] = true;
	for (int i = 1; i < LGN; ++i) {
		prt[u][i] = prt[prt[u][i - 1]][i - 1];
		mx[u][i] = max(mx[u][i - 1], mx[prt[u][i - 1]][i - 1]);
	}
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v]) {
			dep[p->v] = dep[u] + 1;
			prt[p->v][0] = u;
			mx[p->v][0] = Data(p->w, p->id);
			dfs(p->v);
		}
}

void adde(int u, int v, int w, int id) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->w = w;
	p->id = id;
	p->next = g[u];
	g[u] = p;
	++p;
}