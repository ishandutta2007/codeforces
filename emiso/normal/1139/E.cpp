#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20100;
const int INF = 10000000;

struct edge {
	int a, b, cap, flow;
};

int n, m, s = MAXN - 2, t = MAXN - 1, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}

bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, sizeof d);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, sizeof ptr);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}

	return flow;
}

int p[5050], c[5050], ds, k[5050], ans[5050], lft[5050];

void put(int id) {
    add_edge(c[id], 10001 + p[id], 1);
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &p[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &c[i]);
    }

    scanf("%d", &ds);

    for(int i = 0; i < ds; i++) {
        scanf("%lld", &k[i]);
        lft[k[i]] = 1;
    }

    for(int i = 1; i <= m; i++) {
        add_edge(s, i, 1);
    }

    for(int i = 1; i <= n; i++)
        if(!lft[i])
            put(i);

    int last = -1, lflow = 0;
    add_edge(10001 + 0, t, 1);

    for(int D = ds-1; D >= 0; D--) {
        while(1) {
            int x = lflow + dinic();
            lflow = x;
            if(x < last + 2) break;
            last++;
            add_edge(10001 + last + 1, t, 1);
        }
        ans[D] = last + 1;
        put(k[D]);
    }

    for(int i = 0; i < ds; i++) printf("%d\n", ans[i]);
    return 0;
}