#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
struct Edge{
    int type, u, v;
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& [type, u, v] : edges) cin >> type >> u >> v;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < m ; i += 1) {
        G[edges[i].u].push_back(i);
        G[edges[i].v].push_back(i);
    }
    auto no = [&]() {
        cout << "NO";
        exit(0);
    };
    vector<int> c(n + 1, -1);
    function<void(int)> DFS = [&](int u) {
        for (int i : G[u]) {
            int v = u ^ edges[i].u ^ edges[i].v;
            if (c[v] == -1) {
                c[v] = c[u] ^ 1;
                DFS(v);
            }
            else if (c[v] == c[u]) no();
        } 
    };
    for (int i = 1; i <= n; i += 1) if (c[i] == -1) {
        c[i] = 0;
        DFS(i);
    }
    vector<vector<int>> g(n + 1);
    for (auto e : edges) {
        if (e.type == 1) {
            if (c[e.u]) g[e.v].push_back(e.u);
            else g[e.u].push_back(e.v);
        }
        else {
            if (c[e.u]) g[e.u].push_back(e.v);
            else g[e.v].push_back(e.u);
        }
    }
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i += 1) for (int j : g[i]) d[j] += 1;
    queue<int> q;
    for (int i = 1; i <= n; i += 1) if (not d[i]) q.push(i);
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i += 1) {
        if (q.empty()) no();
        int u = q.front();
        q.pop();
        x[u] = i;
        for (int v : g[u]) if (not (d[v] -= 1)) q.push(v);
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i += 1)
        cout << "LR"[c[i]] << " " << x[i] << "\n";
}