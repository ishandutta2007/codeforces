#include <cstdio>

using namespace std;

struct Edge {
	int v;
	Edge* next;
};

const int N = 100010;

int n, m;
int rc[N], from[N][2];
Edge *g[N], *gT[N];
bool dp[N][2];
bool vis[N], out[N];

void addEdge(Edge** g, int u, int v);
void dfs1(int u, bool f);
bool dfs2(int u);

int main() {
	scanf("%d%d", &n, &m);
	for (int u = 1; u <= n; ++u) {
		int c;
		scanf("%d", &c);
		for (int rep = 0; rep < c; ++rep) {
			int v;
			scanf("%d", &v);
			addEdge(g, u, v);
			addEdge(gT, v, u);
			++rc[u];
		}
	}
	for (int u = 1; u <= n; ++u)
		if (rc[u] == 0)
			dfs1(u, false);
	int s;
	scanf("%d", &s);
	if (dp[s][1]) {
		puts("Win");
		bool f = true;
		while (s) {
			printf("%d ", s);
			s = from[s][f];
			f = !f;
		}
		return 0;
	}
	if (dfs2(s))
		puts("Draw");
	else
		puts("Lose");
	return 0;
}

bool dfs2(int u) {
	vis[u] = true;
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v]) {
			if (dfs2(p->v))
				return true;
		} else if (!out[p->v])
			return true;
	out[u] = true;
	return false;
}

void dfs1(int u, bool f) {
	dp[u][f] = true;
	for (Edge* p = gT[u]; p; p = p->next)
		if (!dp[p->v][!f]) {
			from[p->v][!f] = u;
			dfs1(p->v, !f);
		}
}

void addEdge(Edge** g, int u, int v) {
	static Edge pool[N * 4];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}