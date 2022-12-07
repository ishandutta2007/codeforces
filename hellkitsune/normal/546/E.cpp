#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

//start max flow

struct Edge {
    int f, cap, to, rev;
    Edge(int f, int cap, int to, int rev) : f(f), cap(cap), to(to), rev(rev) {}
    Edge() {}
};

const int INF = 1e9;

int nodes, src, dest;
int dist[222], q[222], pos[222];
vector<Edge> g[222];

void addEdge(int s, int t, int cap) {
    g[s].pb(Edge(0, cap, t, (int)g[t].size()));
    g[t].pb(Edge(0, 0, s, (int)g[s].size() - 1));
}

bool bfs() {
    fill(dist, dist + nodes, -1);
    dist[src] = 0;
    int qt = 0;
    q[qt++] = src;
    for (int qh = 0; qh < qt; ++qh) {
        int v = q[qh];
        for (Edge e : g[v]) {
            if (dist[e.to] < 0 && e.f < e.cap) {
                dist[e.to] = dist[v] + 1;
                q[qt++] = e.to;
            }
        }
    }
    return dist[dest] >= 0;
}

int dfs(int v, int f) {
    if (v == dest) return f;
    for (int &i = pos[v]; i < (int)g[v].size(); ++i) {
        Edge &e = g[v][i];
        if (e.cap <= e.f) continue;
        if (dist[e.to] == dist[v] + 1) {
            int df = dfs(e.to, min(f, e.cap - e.f));
            if (df > 0) {
                e.f += df;
                g[e.to][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t) {
    src = s;
    dest = t;
    int res = 0;
    while (bfs()) {
        fill(pos, pos + nodes, 0);
        while (int delta = dfs(src, INF))
            res += delta;
    }
    return res;
}

//end max flow

int n, m;
int a[100], b[100];
int sum = 0, sumb = 0;
int ans[100][100] = {};

int main() {
    scanf("%d%d", &n, &m);
    nodes = 2 * n + 2;
    REP(i, n) scanf("%d", a + i), sum += a[i];
    REP(i, n) scanf("%d", b + i), sumb += b[i];
    if (sum != sumb) {
        printf("NO\n");
        return 0;
    }
    REP(i, n) addEdge(i, n + i, INF);
    REP(i, n) if (a[i]) addEdge(2 * n, i, a[i]);
    REP(i, n) if (b[i]) addEdge(n + i, 2 * n + 1, b[i]);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        addEdge(from, n + to, INF);
        addEdge(to, n + from, INF);
    }
    if (maxFlow(2 * n, 2 * n + 1) != sum) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    REP(i, n) for (Edge e : g[i]) if (e.to != 2 * n)
        ans[i][e.to - n] = e.f;
    REP(i, n) {
        REP(j, n) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}