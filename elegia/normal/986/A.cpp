#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
	int v;
	Edge* next;
};

const int N = 100010;

int n, m, k, s;
int dis[N][110];
bool vis[N];
Edge* g[N];

vector<int> cit[110];

void adde(int u, int v);

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		cit[a].push_back(i);
	}
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v);
		adde(v, u);
	}
	for (int i = 1; i <= k; ++i) {
		memset(vis, 0, sizeof(vis));
		queue<int> q;
		for (int u : cit[i]) {
			vis[u] = true;
			q.push(u);
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (Edge* p = g[u]; p; p = p->next)
				if (!vis[p->v]) {
					dis[p->v][i] = dis[u][i] + 1;
					vis[p->v] = true;
					q.push(p->v);
				}
		}
	}
	for (int i = 1; i <= n; ++i) {
		nth_element(dis[i] + 1, dis[i] + s, dis[i] + k + 1);
		printf("%d ", accumulate(dis[i] + 1, dis[i] + s + 1, 0));
	}
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