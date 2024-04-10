#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

using cost_type = i64;
const cost_type COST_INF = (i64)1e18;
const int FLOW_INF = (i64)1e9;

struct MinCost {
    explicit MinCost(int n) {
        g.resize(n);
    }

    struct edge {
        int from, to;
        int cap;
        cost_type cost;
        int flow;
    };

    vector<edge> edges;
    vector<vector<int>> g;

    void add_edge(int from, int to, cost_type cost, int cap) {
        edge e = {from, to, cap, cost, 0};
        g[from].push_back(edges.size());
        edges.push_back(e);
        edge e2 = {to, from, 0, -cost, 0};
        g[to].push_back(edges.size());
        edges.push_back(e2);
    }

    pair<int, cost_type> min_cost(int n, int s, int t, bool need_max_flow, int max_flow_value = FLOW_INF) {
        cost_type cost = 0;
        int flow = 0;
        vector<cost_type> potential;
        {
            vector<int> p(n, -1);
            vector<cost_type> d(n);
            d[s] = 0;
            p[s] = s;
            bool changed = true;
            while (changed) {
                changed = false;
                for (size_t i = 0; i < edges.size(); ++i) {
                    edge &e = edges[i];
                    if (e.cap == e.flow || p[e.from] == -1)
                        continue;
                    if (p[e.to] == -1 || d[e.to] > d[e.from] + e.cost) {
                        d[e.to] = d[e.from] + e.cost;
                        p[e.to] = i;
                        changed = true;
                    }
                }
            }
            potential = std::move(d);
        }
        while (flow < max_flow_value) {
            vector<cost_type> d(n);
            vector<int> p(n, -1);

            using queue_type = pair<cost_type, int>;
            priority_queue<queue_type, vector<queue_type>, greater<queue_type>> q;

            q.push({0, s});

            while (!q.empty()) {
                int v = q.top().second;
                cost_type oldD = q.top().first;
                q.pop();
                if (oldD != d[v])
                    continue;
                for (int id: g[v]) {
                    edge &e = edges[id];
                    if (e.to == s)
                        continue;
                    if (e.cap > e.flow) {
                        cost_type newd = d[v] + e.cost + potential[e.from] - potential[e.to];
                        if (p[e.to] == -1 || d[e.to] > newd) {
                            d[e.to] = newd;
                            p[e.to] = id;
                            q.push({d[e.to], e.to});
                        }
                    }
                }
            }

            if (p[t] == -1) {
                break;
            }

            if (d[t] + potential[t] >= 0 && !need_max_flow) {
                break;
            }

            int cur = t;
            int maxAdd = max_flow_value - flow;
            while (cur != s) {
                edge &e = edges[p[cur]];
                cur = e.from;
                maxAdd = min(maxAdd, e.cap - e.flow);
            }

            flow += maxAdd;
            cost += (potential[t] + d[t]) * maxAdd;
            cur = t;
            while (cur != s) {
                int id = p[cur];
                edges[id].flow += maxAdd;
                edges[id ^ 1].flow -= maxAdd;
                cur = edges[id].from;
            }

            for (int i = 0; i < n; ++i) {
                if (i != s && p[i] == -1) {
                    potential[i] = COST_INF;
                } else
                    potential[i] = min(potential[i] + d[i], COST_INF);
            }
        }

        return make_pair(flow, cost);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n1, n2, m, r, b;
    cin >> n1 >> n2 >> m >> r >> b;
    int off0 = 0, off1 = n1, off2 = n1 + n2;
    int S = off2, T = off2 + 1;
    int V = T + 1;

    string s1, s2;
    cin >> s1 >> s2;
    string s = s1 + s2;

    MinCost mc(V);
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        mc.add_edge(off0 + u, off1 + v, r, 1);
        mc.add_edge(off1 + v, off0 + u, b, 1);
    }

    i64 INF = 1e9;
    i64 add = 0;
    forn(i, n1 + n2) {
        char c = s[i];
        if (i >= n1 && c != 'U') c ^= 'R' ^ 'B';
        if (c == 'R') {
            add += INF;
            mc.add_edge(S, i, -INF, 1);
            mc.add_edge(S, i, 0, 1e9);
        }
        if (c == 'B') {
            add += INF;
            mc.add_edge(i, T, -INF, 1);
            mc.add_edge(i, T, 0, 1e9);
        }
        if (c == 'U') {
            mc.add_edge(S, i, 0, 1e9);
            mc.add_edge(i, T, 0, 1e9);
        }
    }

    i64 cost = mc.min_cost(V, S, T, false).se;
    cost += add;
    if (cost > INF / 2) {
        cout << -1 << '\n';
    } else {
        cout << cost << '\n';
        forn(i, m) {
            int val = mc.edges[4 * i].flow - mc.edges[4 * i + 2].flow;
            cout << "BUR"[val + 1];
        }
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}