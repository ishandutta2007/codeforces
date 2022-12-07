#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

// min cost START

const int INF = 1e9;

struct Edge {
    int to, rev, cap, cost, f = 0;
    Edge(int to, int rev, int cap, int cost) : to(to), rev(rev), cap(cap), cost(cost) {}
};

const int N = 1000;

vector<Edge> g[N];
int prio[N], pot[N], prevNode[N], prevEdge[N], curFlow[N], fq[N];
bool inq[N] = {};
int nodes, src, dest;

void addEdge(int from, int to, int cap, int cost) {
    g[from].pb(Edge(to, (int)g[to].size(), cap, cost));
    g[to].pb(Edge(from, (int)g[from].size() - 1, 0, -cost));
}

void bellmanFord(int *dist) {
    forn(i, nodes) dist[i] = INF;
    dist[src] = 0;
    fq[0] = src;
    for (int qh = 0, qt = 1; qh != qt; qh = ((qh == nodes - 1) ? 0 : (qh + 1))) {
        int v = fq[qh];
        inq[v] = false;
        for (Edge e : g[v]) if (e.f < e.cap && dist[e.to] > dist[v] + e.cost) {
            dist[e.to] = dist[v] + e.cost;
            if (!inq[e.to]) {
                inq[e.to] = true;
                fq[qt++] = e.to;
                if (qt == nodes) qt = 0;
            }
        }
    }
}

bool used[N];

PII minCostFlow(int maxFlow) {
    bellmanFord(pot);
    int flow = 0;
    int flowCost = 0;
    while (flow < maxFlow) {
        forn(i, nodes) prio[i] = INF;
        forn(i, N) used[i] = false;
        prio[src] = 0;
        curFlow[src] = INF;
        while (true) {
            int v = -1;
            forn(i, nodes) if (!used[i] && (v == -1 || prio[i] < prio[v])) {
                v = i;
            }
            if (v == -1 || prio[v] >= INF) break;
            used[v] = true;
            forn(i, g[v].size()) {
                Edge &e = g[v][i];
                if (e.f >= e.cap) continue;
                int newPrio = prio[v] + pot[v] - pot[e.to] + e.cost;
                if (prio[e.to] > newPrio) {
                    prio[e.to] = newPrio;
                    prevNode[e.to] = v;
                    prevEdge[e.to] = i;
                    curFlow[e.to] = min(curFlow[v], e.cap - e.f);
                }
            }
        }
        if (prio[dest] >= INF) break;
        forn(i, nodes) if (prio[i] < INF) {
            pot[i] += prio[i];
        }
        int df = min(maxFlow - flow, curFlow[dest]);
        flow += df;
        flowCost += df * pot[dest];
        for (int v = dest; v != src; v = prevNode[v]) {
            Edge &e = g[prevNode[v]][prevEdge[v]];
            e.f += df;
            g[v][e.rev].f -= df;
        }
    }
    return mp(flow, flowCost);
}

// min cost END

int n, q;
int from[50], to[50];

int main() {
    scanf("%d%d", &n, &q);
    forn(i, n) from[i] = 0, to[i] = n - 1;
    forn(i, q) {
        int qt, le, ri, val;
        scanf("%d%d%d%d", &qt, &le, &ri, &val);
        --le, --ri, --val;
        for (int j = le; j <= ri; ++j) {
            if (qt == 1) {
                from[j] = max(from[j], val);
            } else {
                to[j] = min(to[j], val);
            }
        }
    }
    forn(i, n) if (from[i] > to[i]) {
        cout << -1 << endl;
        return 0;
    }
    src = 2 * n;
    dest = src + 1;
    nodes = dest + 1;
    forn(i, n) {
        addEdge(src, i, 1, 0);
        for (int j = from[i]; j <= to[i]; ++j) {
            addEdge(i, n + j, 1, 0);
        }
    }
    forn(i, n) {
        forn(j, n) {
            addEdge(n + i, dest, 1, 1 + 2 * j);
        }
    }
    PII res = minCostFlow(n);
    assert(res.first == n);
    cout << res.second << endl;
    return 0;
}