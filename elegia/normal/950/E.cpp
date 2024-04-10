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

int n, m, h;
bool ins[N];
int x[N], scc[N], cnt[N], deg[N], dfn[N], low[N];
vector<int> ele[N];
Edge* g[N];

void adde(int u, int v);
void dfs(int u);

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d%d", &n, &m, &h);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &x[i]);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		if ((x[u] + 1) % h == x[v])
			adde(u, v);
		if ((x[v] + 1) % h == x[u])
			adde(v, u);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i])
			dfs(i);
	for (int i = 1; i <= n; ++i) {
		++cnt[scc[i]];
		for (Edge* p = g[i]; p; p = p->next)
			if (scc[i] != scc[p->v])
				deg[scc[i]] = true;
	}
	int ans = -1;
	for (int i = 1; i <= n; ++i)
		if (scc[i] == i && !deg[i]) {
			if (ans == -1 || cnt[ans] > cnt[i])
				ans = i;
		}
	printf("%d\n", cnt[ans]);
	for (int u : ele[ans])
		printf("%d ", u);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

void dfs(int u) {
	static int t;
	static stack<int> stk;
	dfn[u] = low[u] = ++t;
	ins[u] = true;
	stk.push(u);
	for (Edge* p = g[u]; p; p = p->next) {
		if (!dfn[p->v])
			dfs(p->v);
		if (ins[p->v])
			low[u] = min(low[u], low[p->v]);
	}
	if (low[u] == dfn[u]) {
		int v;
		do {
			v = stk.top();
			stk.pop();
			ins[v] = false;
			scc[v] = u;
			ele[u].push_back(v);
		} while (v != u);
	}
}

void adde(int u, int v) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}