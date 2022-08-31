#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

struct Edge {
	int v;
	Edge* next;
};

const int N = 200010;

int n, cnt;
Edge* g[N];
int deg[N], ans[N],c1[N], c2[N];
bool dp[N];
bool vis[N];

void dfs(int u);
void addEdge(int u, int v);
void dfs2(int u);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		if (p != 0) {
			addEdge(i, p);
			addEdge(p, i);
		}
	}
	dfs(1);
	if (!dp[1]) {
		puts("NO");
		return 0;
	}
	puts("YES");
	memset(vis, 0, sizeof(vis));
	dfs2(1);
	for (int i = 1; i < cnt; ++i)
		printf("%d ", ans[i]);
	printf("%d\n", ans[n]);
	return 0;
}

void dfs2(int u) {
	vis[u] = true;
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v] && !dp[p->v])
			dfs2(p->v);
	ans[++cnt] = u;
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v])
			dfs2(p->v);
}

void dfs(int u) {
	vis[u] = true;
	int d = deg[u] - (u != 1);
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v]) {
			dfs(p->v);
			if (dp[p->v])
				++c1[u];
			else
				++c2[u];
		}
	if (d % 2 == 0) {
		dp[u] = c2[u] % 2 == 0;
	} else {
		dp[u] = c2[u] % 2 == 1;
	}
}

void addEdge(int u, int v) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++deg[u];
	++p;
}