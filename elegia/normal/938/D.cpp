#include <cstdio>

#include <functional>
#include <queue>

using namespace std;

typedef long long ll;

struct Edge {
	int v;
	ll w;
	Edge* next;
};

struct Node {
	int u;
	ll dis;

	Node() {}

	Node(int u, ll dis) : u(u), dis(dis) {}

	bool operator>(const Node& rhs) const {
		return dis > rhs.dis;
	}
};

const int N = 200010;

int n, m;
ll dis[N];
Edge* g[N];

priority_queue<Node, vector<Node>, greater<Node> > q;

void addEdge(int u, int v, ll w);

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		w *= 2;
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &dis[i]);
		q.push(Node(i, dis[i]));
	}
	while (!q.empty()) {
		Node tmp = q.top();
		q.pop();
		if (tmp.dis != dis[tmp.u])
			continue;
		for (Edge* p = g[tmp.u]; p; p = p->next)
			if (dis[p->v] > tmp.dis + p->w)
				q.push(Node(p->v, dis[p->v] = tmp.dis + p->w));
	}
	for (int i = 1; i <= n; ++i)
		printf("%lld ", dis[i]);
	return 0;
}

void addEdge(int u, int v, ll w) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->w = w;
	p->next = g[u];
	g[u] = p;
	++p;
}