#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// Accepts an adjacency list. Returns the minimum cost from s to e.
// Pairs should be in the form {weight, destination}, runs in O(ElogV).
template<typename T>
T dijkstra(vector<vector<pair<T, int>>>& adj, int s, int e) {

    const static T inf_T = numeric_limits<T>::max();
    int n = adj.size();
    vector<bool> vis(n, 0);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> heap;
    heap.push({0, s});

    while (!heap.empty()) {
        auto [c, i] = heap.top(); heap.pop();
        if (vis[i]) continue;
        vis[i] = 1;
        if (i == e) return c;
        for (auto& [w, j] : adj[i])
            if (!vis[j])
                heap.push({c+w, j});
    }
    return inf_T;
}

// Accepts an adjacency list. Returns the minimum cost from s to all vertices.
// Pairs should be in the form {weight, destination}, runs in O(ElogV).
template<typename T>
vector<T> dijkstra(vector<vector<pair<T, int>>>& adj, int s) {

    const static T inf_T = numeric_limits<T>::max();
    int n = adj.size();
    vector<bool> vis(n, 0);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> heap;
    heap.push({0, s});
    vector<T> out(n, inf_T);

    while (!heap.empty()) {
        auto [c, i] = heap.top(); heap.pop();
        if (vis[i]) continue;
        vis[i] = 1;
        out[i] = c;
        for (auto& [w, j] : adj[i])
            if (!vis[j])
                heap.push({c+w, j});
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, int>>> adj(4*n);
    while (m--) {
        ll x, y, w; cin >> x >> y >> w; x--, y--;
        for (int i = 0; i < 4; i++)
            adj[x+i*n].pb({w, y+i*n}), adj[y+i*n].pb({w, x+i*n});
        adj[x].pb({2*w, y+n}), adj[y].pb({2*w, x+n});
        adj[x+2*n].pb({2*w, y+3*n}), adj[y+2*n].pb({2*w, x+3*n});
        adj[x].pb({0, y+2*n}), adj[y].pb({0, x+2*n});
        adj[x+n].pb({0, y+3*n}), adj[y+n].pb({0, x+3*n});
        adj[x].pb({w, y+3*n}), adj[y].pb({w, x+3*n});
    }
    auto ans = dijkstra(adj, 0);
    for (int i = 1; i < n; i++)
        cout << ans[3*n+i] << " \n"[i == n-1];
}