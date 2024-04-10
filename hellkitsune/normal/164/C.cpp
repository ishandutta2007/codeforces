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

const int N = 1111;
const int INF = 2e9;

int nodes;
int prio[N], curFlow[N], prevEdge[N], prevNode[N], fq[N], pot[N];
bool used[N];

struct Cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (prio[lhs] != prio[rhs])
            return prio[lhs] < prio[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> q;

struct E {
    int to, f, cap, cost, rev;
    E(int to, int f, int cap, int cost, int rev) : to(to), f(f), cap(cap), cost(cost), rev(rev) {}
    E() {}
};

vector<E> g[N];

void addEdge(int s, int t, int cap, int cost) {
    g[s].pb(E(t, 0, cap, cost, (int)g[t].size()));
    g[t].pb(E(s, 0, 0, -cost, (int)g[s].size() - 1));
}

void bellmanFord(int s, int *dist) {
    fill(dist, dist + nodes, INF);
    dist[s] = 0;
    fq[0] = s;
    for (int qh = 0, qt = 1; qh != qt; ) {
        int v = fq[qh];
        used[v] = false;
        for (E e : g[v]) if (e.f < e.cap && dist[e.to] > dist[v] + e.cost) {
            dist[e.to] = dist[v] + e.cost;
            if (!used[e.to]) {
                used[e.to] = true;
                fq[qt++] = e.to;
                if (qt == nodes) qt = 0;
            }
        }
        ++qh;
        if (qh == nodes) qh = 0;
    }
}

PII minCostFlow(int s, int t, int maxF) {
    bellmanFord(s, pot);
    int flow = 0;
    int flowCost = 0;
    while (flow < maxF) {
        fill(prio, prio + nodes, INF);
        prio[s] = 0;
        curFlow[s] = INF;
        q.insert(s);
        while (!q.empty()) {
            int v = *q.begin();
            q.erase(q.begin());
            REP(i, g[v].size()) if (g[v][i].f < g[v][i].cap) {
                E &e = g[v][i];
                int nprio = prio[v] + e.cost + pot[v] - pot[e.to];
                if (prio[e.to] > nprio) {
                    q.erase(e.to);
                    prio[e.to] = nprio;
                    q.insert(e.to);
                    prevNode[e.to] = v;
                    prevEdge[e.to] = i;
                    curFlow[e.to] = min(curFlow[v], e.cap - e.f);
                }
            }
        }
        if (prio[t] == INF) break;
        REP(i, nodes)
            pot[i] += prio[i];
        int df = min(curFlow[t], maxF - flow);
        flow += df;
        for (int v = t; v != s; v = prevNode[v]) {
            E &e = g[prevNode[v]][prevEdge[v]];
            e.f += df;
            g[v][e.rev].f -= df;
            flowCost += df * e.cost;
        }
    }
    return mp(flow, flowCost);
}

int n, k;
int s[1000], t[1000], c[1000], ord[1000], ns[1000], nt[1000], nc[1000];
int nx[1000];
int ans[1000], eind[1000];

bool cmp(const int &lhs, const int &rhs) {
    return s[lhs] < s[rhs];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    REP(i, n) cin >> s[i] >> t[i] >> c[i];
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n) ns[i] = s[ord[i]], nt[i] = t[ord[i]], nc[i] = c[ord[i]];
    REP(i, n) s[i] = ns[i], t[i] = nt[i], c[i] = nc[i];
    REP(i, n) {
        nx[i] = i + 1;
        while (nx[i] < n && s[nx[i]] < s[i] + t[i])
            ++nx[i];
    }
    nodes = n + 2;
    addEdge(n + 1, 0, k, 0);
    REP(i, n) addEdge(i, i + 1, k, 0);
    REP(i, n) {
        addEdge(i, nx[i], 1, -c[i]);
        eind[i] = (int)g[i].size() - 1;
    }
    minCostFlow(n + 1, n, k);
    REP(i, n) ans[i] = 0;
    REP(i, n) if (g[i][eind[i]].f > 0)
        ans[ord[i]] = 1;
    REP(i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}