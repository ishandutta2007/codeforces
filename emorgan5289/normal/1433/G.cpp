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

vector<pair<int, int>> e;
int c[1005][1005], g;
int v[1005], a[1005][1005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, s; cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = i == j ? 0 : inf;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w; x--, y--;
        c[x][y] = c[y][x] = w;
        adj[x].pb({w, y}), adj[y].pb({w, x});
        e.pb({x, y});
    }
    for (int i = 0; i < n; i++) {
        auto cc = dijkstra(adj, i);
        for (int j = 0; j < n; j++)
            c[i][j] = cc[j];
    }
    for (int i = 0; i < s; i++) {
        int x, y; cin >> x >> y; x--, y--;
        g += c[x][y];
        for (auto& [p, q] : e)
            a[p][q] += min(c[x][y], min(c[x][p]+c[y][q], c[x][q]+c[y][p]));
    }
    int ans = inf;
    for (auto& [i, j] : e)
        ans = min(ans, a[i][j]);
    cout << ans << "\n";
}