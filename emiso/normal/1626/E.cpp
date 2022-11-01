#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, a[MN], c[MN], vis[MN], sz[MN], par[MN];
vector<int> adj[MN];

int dfs(int no, int pai = 0) {
    par[no] = pai;
    sz[no] = c[no];
    for (int v : adj[no]) 
        if (v != pai)
            sz[no] += dfs(v, no);
    return sz[no];
}

int main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &c[i]);
    }
    for (int i = 1, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!c[i] || vis[i]) continue;
        vis[i] = 1;
        for (int v : adj[i]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (vis[v]) continue;
            int howmany;
            if (v == par[u]) {
                howmany = sz[u];
            } else {
                howmany = sz[1] - sz[v];
            }
            if (howmany >= 2) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%lld ", vis[i]);
    return 0;
}