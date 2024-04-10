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

const int N = 500010;

int n;
ll ans;
int a[N];
bool vis[N];
Edge* g[N];

void adde(int u, int v);
void dfs(int u);

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v);
		adde(v, u);
	}
	dfs(min_element(a + 1, a + n + 1) - a);
	printf("%lld\n", ans);
	
#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

void dfs(int u) {
	static int stk[N];
	static int t;
	stk[++t] = u;
	vis[u] = true;
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v])
			dfs(p->v);
	if (t != 1) {
		ans += a[u];
		ll myn = numeric_limits<ll>::max();
		for (int l = 0; l < 20; ++l) {
			int v = stk[max(t - (1 << l), 1)];
			myn = min(myn, (l + 1) * (ll)a[v]);
		}
		ans += myn;
	}
	--t;
}

void adde(int u, int v) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}