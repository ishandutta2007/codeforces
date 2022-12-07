#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

//BEGIN Dinic

struct Edge {
    int to, rev, cap, f = 0;
    Edge(int to, int rev, int cap) : to(to), rev(rev), cap(cap) {}
};

vector<Edge> g[10000];
int q[10000], dist[10000], pos[10000];
int nodes, src, dest;

void addEdge(int from, int to, int cap) {
    g[from].pb(Edge(to, (int)g[to].size(), cap));
    g[to].pb(Edge(from, (int)g[from].size() - 1, 0));
}

bool bfs() {
    forn(i, nodes) dist[i] = -1;
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
        forn(i, nodes) pos[i] = 0;
        while (int df = dfs(src, 12341234)) {
            flow += df;
        }
    }
    return flow;
}

//END Dinic

bool pr[200005];

void initPrimes() {
    forn(i, 200005) pr[i] = true;
    pr[0] = pr[1] = false;
    forn(i, 2000) if (pr[i]) {
        for (int j = i * i; j < 200005; j += i) {
            pr[j] = false;
        }
    }
}

int n, k;
int p[100], c[100], l[100];
vector<PII> le, ri;

bool solve(int mx) {
    int maxOne = 0;
    le.clear();
    ri.clear();
    forn(i, n) if (l[i] <= mx) {
        if (c[i] == 1) {
            maxOne = max(maxOne, p[i]);
        } else if (c[i] % 2 == 0) {
            le.pb(mp(c[i], p[i]));
        } else {
            ri.pb(mp(c[i], p[i]));
        }
    }
    if (maxOne > 0) {
        ri.pb(mp(1, maxOne));
    }
    int res = 0;
    for (PII x : le) res += x.second;
    for (PII x : ri) res += x.second;
    int lesz = (int)le.size();
    int risz = (int)ri.size();
    forn(i, nodes) {
        g[i].clear();
    }
    src = lesz + risz;
    dest = src + 1;
    nodes = dest + 1;
    forn(i, lesz) addEdge(src, i, le[i].second);
    forn(i, risz) addEdge(lesz + i, dest, ri[i].second);
    forn(i, lesz) forn(j, risz) if (pr[le[i].first + ri[j].first]) {
        addEdge(i, lesz + j, 12341234);
    }
    res -= maxFlow();
    return res >= k;
}

int main() {
    initPrimes();
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d%d%d", p + i, c + i, l + i);
    int lo = 1, hi = n + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (solve(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << (lo == n + 1 ? -1 : lo) << endl;
    return 0;
}