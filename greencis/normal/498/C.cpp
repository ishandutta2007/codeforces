//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

struct Edge {
    int to, cap, flow;
};
vector<Edge> edges;

constexpr int MAXN = 205;
vector<int> g[MAXN];

void addEdge(int from, int to, int cap) {
    g[from].push_back((int)edges.size());
    edges.push_back({to, cap, 0});
    g[to].push_back((int)edges.size());
    edges.push_back({from, 0, 0});
}

int st, fi, numVer;
int q[MAXN], ptr[MAXN], d[MAXN];
constexpr int INF = 1e9;

bool bfs() {
    fill_n(d, numVer, INF);
    int qh = 0, qt = 0;
    d[st] = 0;
    q[qt++] = st;
    while (qh != qt && d[fi] == INF) {
        int v = q[qh++];
        for (int ed : g[v]) {
            int to = edges[ed].to;
            if (d[to] == INF && edges[ed].flow < edges[ed].cap) {
                d[to] = d[v] + 1;
                q[qt++] = to;
            }
        }
    }
    return d[fi] != INF;
}

int dfs(int v, int flow = INF) {
    if (flow == 0 || v == fi)
        return flow;
    while (ptr[v] < (int)g[v].size()) {
        int ed = g[v][ptr[v]++];
        int to = edges[ed].to;
        if (d[v] + 1 == d[to]) {
            int delta = dfs(to, min(flow, edges[ed].cap - edges[ed].flow));
            if (delta > 0) {
                edges[ed].flow += delta;
                edges[ed ^ 1].flow -= delta;
                return delta;
            }
        }
    }
    return 0;
}

int dinic() {
    int ans = 0;
    while (bfs()) {
        fill_n(ptr, numVer, 0);
        while (int flow = dfs(st))
            ans += flow;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> divisors;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        int tmp = v[i];
        for (int j = 2; j * j <= tmp; ++j) {
            int cnt = 0;
            while (tmp % j == 0)
                tmp /= j, ++cnt;
            if (cnt > 0)
                divisors.push_back(j);
        }
        if (tmp > 1)
            divisors.push_back(tmp);
    }
    sort(all(divisors));
    divisors.resize(unique(all(divisors)) - divisors.begin());

    vector<pii> pairs(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        if (x % 2) swap(x, y);
        pairs[i] = {x, y};
    }

    for (int i = 0; i < n; ++i) addEdge(2 * i, 2 * i + 1, 0);
    st = 2 * n;
    fi = 2 * n + 1;
    numVer = 2 * n + 2;
    for (int i = 0; i < n; i += 2) addEdge(st, 2 * i, INF);
    for (int i = 1; i < n; i += 2) addEdge(2 * i + 1, fi, INF);
    for (auto [x, y] : pairs) addEdge(2 * x + 1, 2 * y, INF);

    int ans = 0;
    for (int d : divisors) {
        bool was = false;
        for (auto [x, y] : pairs) {
            if (v[x] % d == 0 && v[y] % d == 0) {
                was = true;
                break;
            }
        }
        if (!was) continue;
        for (auto& edge : edges) edge.flow = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            int tmp = v[i];
            while (tmp % d == 0)
                tmp /= d, ++cnt;
            edges[2 * i].cap = cnt;
        }
        ans += dinic();
    }
    cout << ans << endl;
}