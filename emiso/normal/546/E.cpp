#include <bits/stdc++.h>

using namespace std;

const int MAXN = 440;
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

int a[220], b[220], sum_ida, sum_volta, ans[220][220], x, y;

int main() {
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        sum_ida += a[i];
    }
    for(int i=1; i<=n; i++) {
        scanf("%d", &b[i]);
        sum_volta += b[i];
    }

    for(int i=1; i<=n; i++) {
        add_edge(s, i, a[i]);
        add_edge(i + 210, t, b[i]);
        add_edge(i, i + 210, INF);
    }

    for(int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);

        add_edge(x, y + 210, INF);
        add_edge(y, x + 210, INF);
    }

    if(dinic() == sum_ida && sum_ida == sum_volta) {
        printf("YES\n");
        for(edge ed : e) {
            if(ed.a < 200 && ed.b > 200 && ed.b < 400) {
                ans[ed.a][ed.b - 210] = ed.flow;
            }
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                printf("%d", ans[i][j]);
                if(j < n) printf(" ");
            } puts("");
        }
    }
    else printf("NO\n");

    return 0;
}