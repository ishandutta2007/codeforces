#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>
 
using namespace std;
using namespace std::chrono;
#define int long long
 
template <const int NMAX, const int MMAX>
class MaxFlow {
public:
    MaxFlow() { m = 0; }
 
    inline void setN(int _n) { n = _n; }
    inline void setS(int _s) { s = _s; }
    inline void setT(int _t) { t = _t; }
 
    inline int getN() { return n; }
    inline int getS() { return s; }
    inline int getT() { return t; }
 
    void clear() {
        m = 0;
        for (int i = 1; i <= n; ++ i)
            graph[i].clear();
    }
 
    void reset() {
        for (int i = 0; i < m; ++ i)
            edges[i].flow = 0;
    }
 
    void addEdge(int from, int to, int cap) {
        edges[m ++] = Edge(from, to, 0, cap);
        edges[m ++] = Edge(to, from, 0, 0);
 
        graph[from].push_back(m - 2);
        graph[to].push_back(m - 1);
    }
 
    inline int computeFlow() {
        return Dinic();
    }
 
    bool vis[NMAX];
private:
    struct Edge {
        int from, to;
        int flow, cap;
 
        Edge(int _from = 0, int _to = 0, int _flow = 0, int _cap = 0):
                from(_from), to(_to), flow(_flow), cap(_cap) {}
        inline int other(int node) {
            return from ^ to ^ node;
        }
    };
 
    int n, m, s, t;
 
    vector <int> graph[NMAX];
    Edge edges[2 * MMAX];
 
    int father[NMAX];
    queue <int> _queue;
 
    bool bfs() {
        memset(vis, 0, (n + 1) * sizeof(bool));
 
        vis[s] = true;
        _queue.push(s);
 
        int node;
        while (!_queue.empty()) {
            node = _queue.front();
            _queue.pop();
 
            if (node == t)
                continue;
 
            for (auto it: graph[node])
                if (!vis[edges[it].other(node)] && edges[it].flow < edges[it].cap) {
                    father[edges[it].other(node)] = it;
                    vis[edges[it].other(node)] = true;
                    _queue.push(edges[it].other(node));
                }
        }
 
        return vis[t];
    }
 
    int Dinic() {
        int flow = 0;
        while (bfs()) {
            for (auto it: graph[t])
                if (vis[edges[it ^ 1].other(t)] && edges[it ^ 1].flow < edges[it ^ 1].cap) {
                    int node = edges[it ^ 1].other(t);
                    int minimum = edges[it ^ 1].cap - edges[it ^ 1].flow;
 
                    while (node != s) {
                        minimum = min(minimum, edges[father[node]].cap - edges[father[node]].flow);
                        node = edges[father[node]].other(node);
                    }
 
                    node = edges[it ^ 1].other(t);
                    edges[it ^ 1].flow += minimum;
                    edges[it].flow -= minimum;
                    flow += minimum;
 
                    while (node != s) {
                        edges[father[node]].flow += minimum;
                        edges[father[node] ^ 1].flow -= minimum;
 
                        node = edges[father[node]].other(node);
                    }
                }
        }
 
        return flow;
    }
};
 
const int MAXN = 1000;
const int MAXM = 2000;
const int INF = 1e18;
 
int u[1 + MAXM], v[1 + MAXM], c[1 + MAXM], sum[1 + MAXN];
#define int int
int main() {
#define int long long
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    srand(time(0));
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    MaxFlow<3 * MAXN + 3 * MAXM + 100, 30 * (MAXN + MAXM)> flow;
    flow.setN(2 * n + 2 * m + 2);
    int S = 2 * n + 2 * m + 1, T = 2 * n + 2 * m + 2;
    flow.setS(S);
    flow.setT(T);
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> c[i];
        sum[u[i]] += c[i];
        sum[v[i]] += c[i];
    }
    flow.addEdge(S, 2 * a - 1, sum[a]);
    flow.addEdge(2 * a - 1, T, INF);
    flow.addEdge(S, 2 * a, INF);
 
    flow.addEdge(S, 2 * b - 1, INF);
    flow.addEdge(S, 2 * b, sum[b]);
    flow.addEdge(2 * b, T, INF);
 
    for (int i = 1; i <= n; i++) {
        if (i != a && i != b) {
            flow.addEdge(S, 2 * i - 1, sum[i]);
            flow.addEdge(S, 2 * i, sum[i]);
        }
    }
    int total = 0;
    for (int i = 1; i <= m; i++) {
        flow.addEdge(2 * n + 2 * i - 1, T, 2 * c[i]);
        flow.addEdge(2 * u[i] - 1, 2 * n + 2 * i - 1, INF);
        flow.addEdge(2 * v[i], 2 * n + 2 * i - 1, INF);
        total -= 2 * c[i];
 
        flow.addEdge(2 * n + 2 * i, T, 2 * c[i]);
        flow.addEdge(2 * u[i], 2 * n + 2 * i, INF);
        flow.addEdge(2 * v[i] - 1, 2 * n + 2 * i, INF);
        total -= 2 * c[i];
    }
 
    int ans = total + flow.computeFlow();
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) {
        if (flow.vis[2 * i - 1] && !flow.vis[2 * i]) {
            cout << "B";
        } else if (!flow.vis[2 * i - 1] && flow.vis[2 * i]) {
            cout << "A";
        } else {
            cout << "C";
        }
    }
 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}