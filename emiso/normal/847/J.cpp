#include <bits/stdc++.h>

using namespace std;

const int MAXN = 11000;
const int INF = 1000000000;

struct edge {
	int a, b, cap, flow;
};

int n, m, s = MAXN - 2, t = MAXN - 1, d[MAXN], ptr[MAXN], q[MAXN], x[MAXN], y[MAXN];
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

void clean() {
    e.clear();
    for(int i=0; i<MAXN; i++) {
        g[i].clear();
    }
}

void build(int mid) {
    for(int i=1; i<=n; i++) {
        add_edge(i, t, mid);
    }

    for(int i=0; i<m; i++) {
        add_edge(s, i + 5050, 1);
        add_edge(i + 5050, x[i], 1);
        add_edge(i + 5050, y[i], 1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    int l = 0, r = 5050;
    while(l < r) {
        int mid = (l + r) / 2;
        clean();
        build(mid);

        if(dinic() >= m) r = mid;
        else l = mid + 1;
    }

    clean();
    build(l);
    dinic();

    printf("%d\n", l);
    for(edge ed : e) {
        //printf("%d %d %d %d\n", ed.a, ed.b, ed.cap, ed.flow);
        if(ed.a > 5000 && ed.a < 10500 && ed.flow == 1) {
            int i = ed.a - 5050;

            if(ed.b == x[i])
                printf("%d %d\n", x[i], y[i]);
            else
                printf("%d %d\n", y[i], x[i]);
        }
    }
    return 0;
}