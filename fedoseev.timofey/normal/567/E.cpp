#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

mt19937 rnd(time(0));

int md;
const ll Inf = 1e18;

vector <vector <pair <int, int>>> g, gr;

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

bool prime(int a) {
    for (int d = 2; d * d <= a; ++d) {
        if (a % d == 0) return 0;
    }
    return 1;
}

int n;
void dijkstra(int s, vector <ll> &d, vector <vector <pair <int, int>>> &g, vector <int> &dp) {
    for (int i = 0; i < n; ++i) d[i] = (i == s ? 0 : Inf);
    set <pair <ll, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        auto p = *q.begin();
        q.erase(q.begin());
        int u = p.second;
        for (auto e : g[u]) {
            if (d[e.first] > d[u] + e.second) {
                q.erase({d[e.first], e.first});
                d[e.first] = d[u] + e.second;
                q.insert({d[e.first], e.first});
                dp[e.first] = dp[u];
            }
            else if (d[e.first] == d[u] + e.second) {
                add(dp[e.first], dp[u]);
            }
        }
    }
}

struct triple {
    int a, b, c;
    triple(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    md = 5e8 + rnd() % (int) 5e8;
    while (!prime(md)) md--;
    int m, s, t;
    cin >> n >> m >> s >> t;
    --s, --t;
    g.resize(n), gr.resize(n);
    vector <triple> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        gr[v].push_back({u, w});
        edges.emplace_back(u, v, w);
    }
    vector <ll> ds(n), dt(n);
    vector <int> dps(n), dpt(n);
    dps[s] = 1;
    dpt[t] = 1;
    dijkstra(s, ds, g, dps);
    dijkstra(t, dt, gr, dpt);
    for (int i = 0; i < m; ++i) {
        int u = edges[i].a;
        int v = edges[i].b;
        int w = edges[i].c;
        if (ds[u] + dt[v] + w == ds[t] && mul(dps[u], dpt[v]) == dps[t]) {
            cout << "YES\n";
        }
        else {
            ll cur = (ds[u] + dt[v] + w);
            ll need = ds[t] - 1;
            if ((cur - need) < w) {
                cout << "CAN " << cur - need << '\n';
            }
            else {
                cout << "NO\n";
            }
        }
    }
}