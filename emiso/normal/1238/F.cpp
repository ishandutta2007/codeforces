#include <bits/stdc++.h>

using namespace std;

int q, n, rootans[300030], best[300030];
vector<int> adj[300030];

void dfs(int u, int pai = 0) {
    int val = adj[u].size() - (pai > 0), v1 = 0, v2 = 0;
    best[u] = val;
    for(int v : adj[u]) {
        if(v == pai) continue;
        dfs(v, u);
        best[u] = max(best[u], best[v] + val);
        if(best[v] > v2) v2 = best[v];
        if(v2 > v1) swap(v1, v2);
    }
    rootans[u] = v1 + v2 + adj[u].size();
}

int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
            ans = max(ans, rootans[i] + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}