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

const int N = 4e5+5;
vector<pair<int, int>> adj[N];
int vis[N], col[N], del0[N], del1[N], even[N], odd[N], c = 0;

void dfs(int i, int k) {
    vis[i] = 1;
    for (auto& [id, j] : adj[i]) {
        if (j == k) continue;
        if (vis[j] && !even[id] && !odd[id]) {
            if (col[j] == col[i])
                c++, del1[j]--, del1[i]++, odd[id] = 1;
            else
                del0[j]--, del0[i]++, even[id] = 1;
        }
        if (!vis[j]) {
            col[j] = col[i]^1, dfs(j, i);
            even[id] = del0[j] > 0;
            odd[id] += del1[j];
            del0[i] += del0[j], del1[i] += del1[j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb({i, v}), adj[v].pb({i, u});
    }
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs(i, -1);
    vector<int> ans;
    if (c == 0) ans.resize(m), iota(all(ans), 0);
    else
        for (int i = 0; i < m; i++)
            if (!even[i] && odd[i] == c)
                ans.pb(i);
    cout << ans.size() << "\n";
    for (auto& x : ans) cout << x+1 << " ";
}