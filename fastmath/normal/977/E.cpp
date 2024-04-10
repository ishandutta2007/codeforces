#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

vector <int> g[MAXN];
bool used[MAXN];

bool jfs(int u) {
    bool res = (g[u].size() == 2);
    used[u] = true;
    for (int v : g[u]) {
        if (used[v]) continue;
        res &= jfs(v);
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) ans += jfs(i);
    }

    cout << ans << '\n';
    return 0;
}