#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

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
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> heap;
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

vector<vector<pair<ll, int>>> adj;
vector<array<ll, 2>> x, y;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    adj.resize(m+2);
    x.resize(m), y.resize(m);
    ll sx, sy, fx, fy; cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < m; i++) {
        cin >> x[i][0] >> y[i][0];
        x[i][1] = y[i][1] = i;
        adj[m].pb({min(abs(x[i][0]-sx), abs(y[i][0]-sy)), i});
        adj[i].pb({abs(x[i][0]-fx)+abs(y[i][0]-fy), m+1});
    }
    sort(all(x)), sort(all(y));
    for (int i = 0; i < m-1; i++) {
        adj[x[i+1][1]].pb({x[i+1][0]-x[i][0], x[i][1]});
        adj[x[i][1]].pb({x[i+1][0]-x[i][0], x[i+1][1]});
        adj[y[i+1][1]].pb({y[i+1][0]-y[i][0], y[i][1]});
        adj[y[i][1]].pb({y[i+1][0]-y[i][0], y[i+1][1]});
    }
    cout << min(dijkstra(adj, m, m+1), abs(sx-fx)+abs(sy-fy)) << "\n";
}