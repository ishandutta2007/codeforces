#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9;
const int N = 6002;

int f[N][N], cap[N][N], cost[N][N];
int prio[N], pot[N], prevNode[N], fq[N];
bool inq[N] = {};
int nodes, src, dest;

void addEdge(int from, int to, int cap, int cost) {
    ::cap[from][to] = cap;
    ::cost[from][to] = cost;
    ::cost[to][from] = -cost;
}

void bellmanFord(int *dist) {
    forn(i, nodes) dist[i] = INF;
    dist[src] = 0;
    forn(i, src) {
        dist[i] = 0;
        forn(j, i) if (f[j][i] < cap[j][i] && dist[i] > dist[j] + cost[j][i]) {
            dist[i] = dist[j] + cost[j][i];
        }
    }
    forn(i, src) if (f[i][dest] < cap[i][dest] && dist[dest] > dist[i] + cost[i][dest]) {
        dist[dest] = dist[i] + cost[i][dest];
    }
}

bool used[N];

PII minCostFlow(int maxFlow) {
    bellmanFord(pot);
    int flow = 0;
    int flowCost = 0;
    while (flow < maxFlow) {
        forn(i, nodes) prio[i] = INF;
        forn(i, nodes) used[i] = false;
        prio[src] = 0;
        while (true) {
            int v = -1;
            forn(i, nodes) if (!used[i] && (v == -1 || prio[i] < prio[v])) {
                v = i;
            }
            if (v == -1 || prio[v] >= INF) break;
            used[v] = true;
            forn(to, nodes) if (f[v][to] < cap[v][to]) {
                int newPrio = prio[v] + pot[v] - pot[to] + cost[v][to];
                if (prio[to] > newPrio) {
                    prio[to] = newPrio;
                    prevNode[to] = v;
                }
            }
        }
        if (prio[dest] >= INF) break;
        forn(i, nodes) if (prio[i] < INF) {
            pot[i] += prio[i];
        }
        ++flow;
        flowCost += pot[dest];
        for (int v = dest; v != src; v = prevNode[v]) {
            int from = prevNode[v];
            ++f[from][v];
            --f[v][from];
        }
    }
    return mp(flow, flowCost);
}

int n;
int a[3000];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    src = 2 * n;
    dest = src + 1;
    nodes = dest + 1;
    forn(i, n) addEdge(2 * i, 2 * i + 1, 1, -1);
    forn(i, n) addEdge(src, 2 * i, 1, 0);
    forn(i, n) addEdge(2 * i + 1, dest, 1, 0);
    forn(j, n) forn(i, j) {
        if ((a[i] - a[j]) % 7 == 0 || abs(a[i] - a[j]) == 1) {
            addEdge(2 * i + 1, 2 * j, 1, 0);
        }
    }
    PII res = minCostFlow(4);
    assert(res.first == 4);
    cout << -res.second << endl;
    return 0;
}