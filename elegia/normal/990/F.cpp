#include <cstdio>

using namespace std;

struct Edge {
	int v, w;
	Edge* next;
};

const int N = 200010;

int n, m;
int flow[N], s[N];
bool vis[N];
Edge* g[N];

void dfs(int u);
void adde(int u, int v, int w);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &s[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v, i);
		adde(v, u, -i);
	}
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) {
			dfs(i);
			if (s[i]) {
				puts("Impossible");
				return 0;
			}
		}
	puts("Possible");
	for (int i = 1; i <= m; ++i)
		printf("%d\n", flow[i]);
	return 0;
} 

void adde(int u, int v, int w) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->w = w;
	p->next = g[u];
	g[u] = p;
	++p;
}

void dfs(int u) {
	vis[u] = true;
	for (Edge* p = g[u]; g[u] = p; p = p->next)
		if (!vis[p->v]) {
			dfs(p->v);
			if (p->w > 0)
				flow[p->w] += s[p->v];
			else
				flow[-p->w] -= s[p->v];
			s[u] += s[p->v];
			s[p->v] = 0;
		}
}