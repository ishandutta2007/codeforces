#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, m, d[MN], last[MN], ans[MN];
vector<int> adj[MN], ev[MN];

void bfs() {
    for(int i = 0; i <= n; i++) d[i] = 12345678;
    d[1] = 0;
    queue<int> fila({1});
    while(!fila.empty()) {
        int u = fila.front(); fila.pop();
        ev[d[u]].push_back(u);
        for(int v : adj[u]) {
            if(d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                fila.push(v);
            }
        }
    }
}

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }
    bfs();

    for(int i = 1; i <= n; i++) {
        last[i] = d[i];
        for(int v : adj[i])
            last[i] = min(last[i], d[v]);
    }
    for(int i = n; i >= 0; i--) {
        for(int u : ev[i])
            for(int v : adj[u])
                if(d[v] > d[u])
                    last[u] = min(last[u], last[v]);
    }

    for(int i = 1; i <= n; i++) {
        printf("%lld ", last[i]);
    } puts("");

    for(int i = 0; i <= n; i++) {
        adj[i].clear();
        ev[i].clear();
    }
    if(--t) goto st;
    return 0;
}