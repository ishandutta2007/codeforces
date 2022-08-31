#include <cstdio>
#include <cstring>

#include <algorithm>
#include <limits>

using namespace std;

typedef long long ll;

struct Edge {
	int v;
	Edge* next;
};

const int N = 300010;

int n, cnt;
ll ans;
bool vis[N];
int a[N];
Edge* g[N];

void adde(int u, int v);
ll dfs1(int u);
ll dfs2(int u);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v);
		adde(v, u);
	}
	ans = numeric_limits<ll>::min();
	dfs1(1);
	memset(vis, 0, sizeof(vis));
	dfs2(1);
	printf("%lld %d\n", ans * cnt, cnt);
	return 0;
}

ll dfs1(int u) {
	vis[u] = true;
	ll ret = a[u];
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v])
			ret += dfs1(p->v);
	ans = max(ans, ret);
	return max(ret, 0LL);
}

ll dfs2(int u) {
	vis[u] = true;
	ll ret = a[u];
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v])
			ret += dfs2(p->v);
	if (ret == ans) {
		++cnt;
		return 0;
	}
	return max(ret, 0LL);
}

void adde(int u, int v) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}