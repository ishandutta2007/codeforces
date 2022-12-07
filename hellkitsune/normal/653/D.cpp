#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct Edge {
    int to, rev;
    LL cap, f = 0;
    Edge(int to, int rev, LL cap) : to(to), rev(rev), cap(cap) {}
};

vector<Edge> g[10000];
int q[10000], dist[10000], pos[10000];
int nodes, src, dest;

void addEdge(int from, int to, LL cap) {
    g[from].pb(Edge(to, (int)g[to].size(), cap));
    g[to].pb(Edge(from, (int)g[from].size() - 1, 0));
}

bool bfs() {
    REP(i, nodes) dist[i] = -1;
    dist[src] = 0;
    q[0] = src;
    for (int qh = 0, qt = 1; qh != qt; ++qh) {
        int v = q[qh];
        for (Edge e : g[v]) if (e.f < e.cap && dist[e.to] == -1) {
            dist[e.to] = dist[v] + 1;
            q[qt++] = e.to;
        }
    }
    return dist[dest] != -1;
}

LL dfs(int v, LL flow) {
    if (v == dest) return flow;
    for (int &i = pos[v]; i < (int)g[v].size(); ++i) {
        Edge &e = g[v][i];
        if (e.f < e.cap && dist[e.to] == dist[v] + 1) {
            LL df = dfs(e.to, min(flow, e.cap - e.f));
            if (df > 0) {
                e.f += df;
                g[e.to][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

LL maxFlow() {
    LL flow = 0;
    while (bfs()) {
        REP(i, nodes) pos[i] = 0;
        while (LL df = dfs(src, (LL)1e18)) {
            flow += df;
        }
    }
    return flow;
}

int n, m, x;
int from[500], to[500], cap[500];

int main() {
    scanf("%d%d%d", &n, &m, &x);
    nodes = n;
    src = 0;
    dest = n - 1;
    REP(i, m) scanf("%d%d%d", from + i, to + i, cap + i), --from[i], --to[i];
    double lo = 0, hi = 1000000, mid;
    REP(times, 65) {
        mid = 0.5 * (lo + hi);
        REP(i, n) g[i].clear();
        REP(i, m) {
            LL ncap = cap[i] / mid;
            addEdge(from[i], to[i], ncap);
        }
        if (maxFlow() >= x) lo = mid;
        else hi = mid;
    }
    printf("%.12f\n", lo * x);
    return 0;
}