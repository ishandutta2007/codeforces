#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

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

int n, m;
char buf[1234];
string s;
string w[100];
int p[100];

int main() {
    scanf("%d%s", &n, buf);
    s = string(buf);
    scanf("%d", &m);
    forn(i, m) {
        scanf("%s%d", buf, p + i);
        w[i] = string(buf);
    }
    int x;
    scanf("%d", &x);
    dest = n;
    src = dest + 1;
    nodes = src + 1;
    addEdge(src, 0, x, 0);
    forn(i, n) {
        forn(j, m) {
            int ni = i + (int)w[j].length();
            if (ni > n) continue;
            if (s.substr(i, w[j].length()) != w[j]) continue;
            addEdge(i, ni, 1, -p[j]);
        }
        addEdge(i, i + 1, 1234, 0);
    }
    printf("%d\n", -minCostFlow(1234).second);
    return 0;
}