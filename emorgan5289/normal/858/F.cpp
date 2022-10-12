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

const int N = 2e5+5;
vector<pair<int, int>> adj[N];
vector<array<int, 3>> ans;
bool v[N];

int dfs(int i) {
    int s = -1;
    for (auto& [e, j] : adj[i])
        if (!v[e]) {
            v[e] = 1;
            int k = dfs(j);
            if (k == -1) {
                if (s == -1) s = j;
                else ans.pb({j, i, s}), s = -1;
            }
            else ans.pb({i, j, k});
        }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].pb({i, y}), adj[y].pb({i, x});
    }
    for (int i = 0; i < n; i++)
        for (auto& [e, j] : adj[i])
            if (!v[e]) dfs(i);
    cout << ans.size() << "\n";
    for (auto& [i, j, k] : ans)
        cout << i << " " << j << " " << k << "\n";
}