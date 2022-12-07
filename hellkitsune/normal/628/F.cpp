#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct Edge {
    int to, rev, cap, f = 0;
    Edge(int to, int rev, int cap) : to(to), rev(rev), cap(cap) {}
};

vector<Edge> g[22222];
int q[22222], dist[22222], pos[22222];
int nodes, src, dest;

void addEdge(int from, int to, int cap) {
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

int dfs(int v, int flow) {
    if (v == dest) return flow;
    for (int &i = pos[v]; i < (int)g[v].size(); ++i) {
        Edge &e = g[v][i];
        if (e.f < e.cap && dist[e.to] == dist[v] + 1) {
            int df = dfs(e.to, min(flow, e.cap - e.f));
            if (df > 0) {
                e.f += df;
                g[e.to][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

int maxFlow() {
    int flow = 0;
    while (bfs()) {
        REP(i, nodes) pos[i] = 0;
        while (int df = dfs(src, 12341234)) {
            flow += df;
        }
    }
    return flow;
}

int n, b, qq;
PII a[10002];

int main() {
    scanf("%d%d%d", &n, &b, &qq);
    REP(i, qq) scanf("%d%d", &a[i].first, &a[i].second);
    a[qq] = mp(0, 0);
    a[qq + 1] = mp(b, n);
    qq += 2;
    sort(a, a + qq);
    src = qq + 4;
    dest = src + 1;
    nodes = dest + 1;
    REP(i, 5) addEdge(i, dest, n / 5);
    REP(i, qq - 1) {
        if (a[i + 1].second < a[i].second) {
            printf("unfair\n");
            return 0;
        }
        if (a[i + 1].first - a[i].first < a[i + 1].second - a[i].second) {
            printf("unfair\n");
            return 0;
        }
        addEdge(src, 5 + i, a[i + 1].second - a[i].second);
        int cnt[5] = {};
        for (int z = a[i].first + 1; z <= a[i + 1].first; ++z) {
            ++cnt[z % 5];
        }
        REP(j, 5) {
            addEdge(5 + i, j, cnt[j]);
        }
    }
    if (maxFlow() == n) {
        printf("fair\n");
    } else {
        printf("unfair\n");
    }
    return 0;
}