#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

struct edge {
	int v;
	edge* next;
};

const int N = 300010;

int n, m;
char chk;
char s[N];
edge* g[N];
int dp[N];
bool vis[N], ot[N];

void add_edge(int u, int v);
void dfs1(int u);
int dfs2(int u);

int main() {
	scanf("%d%d%s", &n, &m, s + 1);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
	}
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			dfs1(i);
	int ans = 0;
	for (chk = 'a'; chk <= 'z'; ++chk) {
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; ++i)
			ans = max(ans, dfs2(i));
	}
	printf("%d\n", ans);
	return 0;
}

int dfs2(int u) {
	if (vis[u])
		return dp[u];
	vis[u] = true;
	int mex = 0;
	for (edge* p = g[u]; p; p = p->next)
		mex = max(mex, dfs2(p->v));
	return dp[u] = (s[u] == chk) + mex;
}

void dfs1(int u) {
	if (vis[u] && !ot[u]) {
		puts("-1");
		exit(0);
	}
	if (vis[u])
		return;
	vis[u] = true;
	for (edge* p = g[u]; p; p = p->next)
		dfs1(p->v);
	ot[u] = true;
}

void add_edge(int u, int v) {
	static edge pool[N * 2];
	static edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}