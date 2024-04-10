#include <cassert>
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
	int v;
	Edge* next;
};

const int N = 100010;

int n, k;
bool vis[N];
int dis[N], prt[N], deg[N];
Edge* g[N];

void adde(int u, int v);
void dfs(int u);
void pred(int u, int r);

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &k);
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v);
		adde(v, u);
	}
	dfs(1);
	int u = max_element(dis + 1, dis + n + 1) - dis;
	memset(vis, 0, sizeof(vis));
	dis[u] = 0;
	prt[u] = 0;
	dfs(u);
	int m = max_element(dis + 1, dis + n + 1) - dis;
	if (dis[m] != k * 2) {
		puts("No");
		return 0;
	}
	int cnt = k;
	while (cnt--)
		m = prt[m];
	memset(vis, 0, sizeof(vis));
	pred(m, k);
	puts("YES");

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

void pred(int u, int r) {
	vis[u] = true;
	if (r == 0) {
		if (deg[u]) {
			puts("NO");
			exit(0);
		}
		return;
	}
	if (deg[u] < 3) {
		puts("NO");
		exit(0);
	}
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v]) {
			--deg[p->v];
			pred(p->v, r - 1);
		}
}

void dfs(int u) {
	vis[u] = true;
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v]) {
			prt[p->v] = u;
			dis[p->v] = dis[u] + 1;
			dfs(p->v);
		}
}

void adde(int u, int v) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	++deg[u];
	g[u] = p;
	++p;
}