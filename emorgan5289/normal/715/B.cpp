#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

ll gw;

template<typename T>
T dijkstra(vector<vector<tuple<T, int, int>>>& adj, int s, int e) {

    const static T inf_T = numeric_limits<T>::max();
    int n = adj.size();
    vector<bool> vis(n, 0);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> heap;
    heap.push({0, s});

    while (!heap.empty()) {
        auto [c, i] = heap.top(); heap.pop();
        if (vis[i]) continue;
        vis[i] = 1;
        if (i == e) return c;
        for (auto& [w, j, x] : adj[i])
            if (!vis[j])
                heap.push({c+(w == 0 ? gw : w)+x, j});
    }
    return inf_T;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, l, s, t; cin >> n >> m >> l >> s >> t;
    vector<vector<tuple<ll, int, int>>> adj(n);
    vector<pair<int, int>> e;
    for (int i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].pb({w, v, 0}); adj[v].pb({w, u, 0});
        if (w == 0) e.pb({u, v});
    }
    ll a = 1, b = l;
    while (a < b) {
        gw = (a+b+1)/2;
        if (dijkstra(adj, s, t) > l)
            b = gw-1;
        else
            a = gw;
    }
    gw = a;
    while (e.size() > 0 && dijkstra(adj, s, t) < l) {
        auto [u, v] = e.back(); e.pop_back();
        for (auto& [w, j, x] : adj[u])
            if (j == v) x++;
        for (auto& [w, j, x] : adj[v])
            if (j == u) x++;
    }
    if (dijkstra(adj, s, t) == l) {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            for (auto& [w, j, x] : adj[i])
                if (i < j)
                    cout << i << " " << j << " " << (w == 0 ? gw : w)+x << "\n";
    } else
        cout << "NO\n";
}