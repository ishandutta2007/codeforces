#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <random>
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

const int N = 200010;

int n;
int prt[N], ord[N], tt[N];
bool vis[N];
Edge* g[N];

void adde(int u, int v);
void dfs(int u);

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v);
		adde(v, u);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ord[i]);
		tt[ord[i]] = i;
	}
	int pre = 0;
	for (int i = 1; i <= n; ++i) {
		if (tt[prt[ord[i]]] < pre) {
			puts("No");
			return 0;
		}
		pre = tt[prt[ord[i]]];
	}
	puts("Yes");

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

void adde(int u, int v) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}

void dfs(int u) {
	vis[u] = true;
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v]) {
			prt[p->v] = u;
			dfs(p->v);
		}
}