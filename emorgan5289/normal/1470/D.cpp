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

pair<int, vector<int>> components(vector<vector<int>>& adj) {
    int size = adj.size();
    vector<bool> vis(size, 0);
    vector<int> c(size), s;
    int t = -1;
    for (int i = 0; i < size; i++)
        if (!vis[i]) {
            s.push_back(i); c[i] = ++t; vis[i] = 1;
            while (!s.empty()) {
                int j = s.back(); s.pop_back();
                for (auto k : adj[j])
                    if (!vis[k]) {
                        vis[k] = 1;
                        c[k] = t;
                        s.push_back(k);
                    }
            }
        }
    return make_pair(t+1, c);
}

vector<int> vis, on, ans;
vector<vector<int>> adj;

void dfs(int i) {
    vis[i] = 1;
    bool v = 1;
    for (auto& j : adj[i])
        if (on[j]) v = 0;
    if (v) on[i] = 1, ans.pb(i);
    for (auto& j : adj[i])
        if (!vis[j]) dfs(j);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        adj.assign(n, {});
        while (m--) {
            int x, y; cin >> x >> y; x--, y--;
            adj[x].pb(y), adj[y].pb(x);
        }
        auto [c, cc] = components(adj);
        if (c > 1) {
            cout << "NO\n"; continue;
        }
        ans.clear();
        vis.assign(n, 0);
        on.assign(n, 0);
        dfs(0);
        cout << "YES\n" << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i]+1 << " \n"[i+1 == ans.size()];
    }
}