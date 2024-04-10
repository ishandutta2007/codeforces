#include <cstdio>
#include <cstring>

#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

typedef long long ll;

struct Edge {
	int v, w;
	bool f;
	Edge* next;
};

struct Node {
	int u;
	ll dis;
	
	Node() {}
	
	Node(int u, ll dis) : u(u), dis(dis) {}
	
	bool operator>(const Node& rhs) const { return dis > rhs.dis; }
};

const int N = 100010, M = 600010, K = 100010;

int n, m, k;

priority_queue<Node, vector<Node>, greater<Node> > q;

ll dis[N];
Edge* g[N];

void adde(int u, int v, int w, bool f);

int main() {
	scanf("%d%d%d", &n, &m, &k);
	while (m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adde(u, v, w, false);
		adde(v, u, w, false);
	}
	while (k--) {
		int v, w;
		scanf("%d%d", &v, &w);
		adde(1, v, w, true);
		adde(v, 1, w, true);
	}
	memset(dis, -1, sizeof(dis));
	q.push(Node(1, dis[1] = 0));
	while (!q.empty()) {
		Node tmp = q.top();
		q.pop();
		if (tmp.dis != dis[tmp.u])
			continue;
		for (Edge* p = g[tmp.u]; p; p = p->next)
			if (dis[p->v] == -1 || dis[p->v] > tmp.dis + p->w)
				q.push(Node(p->v, dis[p->v] = tmp.dis + p->w));
	}
	int ans = 0;
	for (int i = 2; i <= n; ++i) {
		int call = 0, cblk = 0;
		for (Edge* p = g[i]; p; p = p->next)
			if (dis[i] == dis[p->v] + p->w) {
				++call;
				cblk += p->f;
			} else
				ans += p->f;
		if (call == 0)
			continue;
		if (call == cblk)
			ans += cblk - 1;
		else
			ans += cblk;
	}
	printf("%d\n", ans);
	return 0;
}

void adde(int u, int v, int w, bool f) {
	static Edge pool[M * 2];
	static Edge* p = pool;
	p->v = v;
	p->w = w;
	p->f = f;
	p->next = g[u];
	g[u] = p;
	++p;
}