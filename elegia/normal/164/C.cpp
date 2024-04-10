#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

typedef long long ll;

struct Edge {
	int v, w, c, tag;
	Edge *next, *rev;
};

const int N = 1010, V = N * 2;

static Edge pool[V * 4];
static Edge* ptop = pool;

int n, k, S, T;
int uni[N * 2];
int s[N], t[N], c[N], f[N], dis[N];
bool ans[N];
Edge *g[V], *path[V];

Edge* addEdge(int u, int v, int w, int c);
Edge* link(int u, int v, int w, int c);
bool spfa();

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &s[i], &t[i], &c[i]);
		t[i] += s[i];
		uni[i * 2 - 1] = s[i];
		uni[i * 2] = s[i];
	}
	sort(uni + 1, uni + n * 2 + 1);
	int uniCnt = unique(uni + 1, uni + n * 2 + 1) - uni;
	for (int i = 1; i < uniCnt; ++i)
		link(i, i + 1, k, 0);
	for (int i = 1; i <= n; ++i)
		link(lower_bound(uni + 1, uni + uniCnt, s[i]) - uni,
		     lower_bound(uni + 1, uni + uniCnt, t[i]) - uni, 1, c[i])->tag = i;
	T = uniCnt;
	S = T + 1;
	link(S, 1, k, 0);
	int u, w, c, flow = 0, cost = 0;
	while (spfa()) {
		u = T;
		w = numeric_limits<int>::max();
		c = 0;
		while (f[u]) {
			w = min(w, path[u]->rev->w);
			c += path[u]->rev->c;
			u = f[u];
		}
		flow += w;
		cost += c * w;
		u = T;
		while (f[u]) {
			path[u]->w += w;
			path[u]->rev->w -= w;
			u = f[u];
		}
//		fprintf(stderr, "FLOW %d %d\n", w, c);
//		fprintf(stderr, "REST %d\n", g[S]->w);
	}
	for (Edge* p = pool; p != ptop; ++p)
		ans[p->tag] = !p->w;
//	printf("%d\n", cost);
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}

Edge* addEdge(int u, int v, int w, int c) {
	Edge* p = ptop++;
	p->v = v;
	p->w = w;
	p->c = c;
	p->next = g[u];
	g[u] = p;
	return p;
}

Edge* link(int u, int v, int w, int c) {
	Edge *p = addEdge(u, v, w, c),
	     *q = addEdge(v, u, 0, -c);
//	fprintf(stderr, "LINK %d %d %d\n", u, v, w);
	p->rev = q;
	q->rev = p;
	return p;
}

bool spfa() {
	static bool inq[N];
	int u;
	queue<int> q;
	memset(f, 0, sizeof(f));
	memset(dis, -1, sizeof(dis));
	q.push(S);
	inq[S] = true;
	dis[S] = 0;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		inq[u] = false;
		for (Edge* p = g[u]; p; p = p->next)
			if (p->w && 
			   (dis[p->v] < dis[u] + p->c)) {
				if (!inq[p->v]) {
					q.push(p->v);
					inq[p->v] = true;
				}
				f[p->v] = u;
				path[p->v] = p->rev;
				dis[p->v] = dis[u] + p->c;
			}
	}
	return dis[T] != -1;
}