#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
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
    REP(i, nodes) dist[i] = INF;
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
        REP(i, nodes) prio[i] = INF;
        REP(i, N) used[i] = false;
        prio[src] = 0;
        curFlow[src] = INF;
        while (true) {
            int v = -1;
            REP(i, nodes) if (!used[i] && (v == -1 || prio[i] < prio[v])) {
                v = i;
            }
            if (v == -1 || prio[v] >= INF) break;
            used[v] = true;
            REP(i, g[v].size()) {
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
        REP(i, nodes) if (prio[i] < INF) {
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

int n, k;
char s[2000005], t[2000005];
int f[52][52] = {};
char ans[55];

int ctoi(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}

char itoc(int i) {
    if (i < 26) return i + 'a';
    return i - 26 + 'A';
}

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s%s", s, t);
    REP(i, n) ++f[ctoi(s[i])][ctoi(t[i])];
    src = 2 * k;
    dest = src + 1;
    nodes = dest + 1;
    REP(i, k) addEdge(src, i, 1, 0);
    REP(i, k) addEdge(k + i, dest, 1, 0);
    REP(i, k) REP(j, k) addEdge(i, k + j, 1, -f[i][j]);
    printf("%d\n", -minCostFlow(k).second);
    REP(i, k) {
        for (Edge e : g[i]) if (e.f == 1) {
            ans[i] = itoc(e.to - k);
            break;
        }
    }
    ans[k] = '\0';
    printf("%s\n", ans);
    return 0;
}