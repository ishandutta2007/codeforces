// Important and Semi-important cities
#include <bits/stdc++.h>
#define MN 300030

using namespace std;

int deg[MN], n, m, a, b, ans[MN];
vector<int> adj[2][MN];

void solve(int rev) {
    int remaining = n;
    memset(deg, 0, sizeof deg);

    for(int u = 1; u <= n; u++)
        for(int v : adj[rev][u])
            deg[v]++;

    queue<int> fila;
    for(int i = 1; i <= n; i++) {
        if(!deg[i]) {
            fila.push(i);
            remaining--;
        }
    }

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();

        if(fila.empty()) {
            ans[u] += remaining;
        } else if(fila.size() == 1) {
            int semi = 1, other = fila.front();

            for(int v : adj[rev][other])
                if(deg[v] == 1) semi = 0;

            if(semi) ans[u] += remaining;
        }

        for(int v : adj[rev][u]) {
            deg[v]--;
            if(!deg[v]) {
                fila.push(v);
                remaining--;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
    }

    solve(0);
    solve(1);

    int quant = 0;
    for(int i = 1; i <= n; i++)
        if(ans[i] >= n - 2) quant++;

    printf("%d\n", quant);
    return 0;
}