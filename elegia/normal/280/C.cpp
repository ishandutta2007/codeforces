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
#include <iostream>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Edge {
	int v;
	Edge* next;
};

const int N = 100010;

int n;
int dep[N];
Edge* g[N];

void adde(int u, int v) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}

void dfs(int u) {
	for (Edge* p = g[u]; p; p = p->next)
		if (!dep[p->v]) {
			dep[p->v] = dep[u] + 1;
			dfs(p->v);
		}
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int n;
	scanf("%d", &n);
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v);
		adde(v, u);
	}
	dep[1] = 1;
	dfs(1);
	double ans = 0;
	for (int u = 1; u <= n; ++u)
		ans += 1. / dep[u];
	printf("%.6lf\n", ans);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}