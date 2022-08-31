#include <cstdio>

#include <queue>

using namespace std;

typedef long long ll;

struct node {
	int u;
	ll step;

	node() {}

	node(int u, ll step) : u(u), step(step) {}

	bool operator>(const node& x) const {
		return step > x.step;
	}
};

struct edge {
	int u, v, w;
	edge* next;
};

const int N = 100010;

int lst[N];
ll dis[N];
edge* g[N];

void add_edge(int u, int v, int w);

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	priority_queue<node, vector<node>, greater<node> > q;
	lst[n] = n;
	q.push(node(n, 0));
	while (!q.empty()) {
		node tmp = q.top();
		q.pop();
		int u = tmp.u;
		ll step = tmp.step;
		if (dis[u] < step)
			continue;
		if (u == 1)
			break;
		for (edge* p = g[u]; p; p = p->next)
			if (lst[p->v] == 0 || dis[p->v] > step + p->w) {
				dis[p->v] = step + p->w;
				lst[p->v] = u;
				q.push(node(p->v, dis[p->v]));
			}
	}
	if (lst[1] == 0) {
		puts("-1");
		return 0;
	}
	int u = 1;
	while (u != n) {
		printf("%d ", u);
		u = lst[u];
	}
	printf("%d\n", n);
	return 0;
}

void add_edge(int u, int v, int w) {
	static edge pool[N * 2];
	static edge* p = pool;
	p->v = v;
	p->w = w;
	p->next = g[u];
	g[u] = p;
	++p;
}