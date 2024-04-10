#include <bits/stdc++.h>

#define MN 301000

using namespace std;

int n, m, k, d[2][MN], spec[MN], ans;
vector<int> adj[MN], dist[2][MN];

void bfs(int st, int t) {
    for(int i = 0; i < MN; i++) d[t][i] = -1;

    d[t][st] = 0;
    if(spec[st])
        dist[t][0].push_back(st);

    queue<int> fila;
    fila.push(st);

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for(int &v : adj[u]) {
            if(d[t][v] == -1) {
                d[t][v] = d[t][u] + 1;
                if(spec[v])
                    dist[t][d[t][v]].push_back(v);
                fila.push(v);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        spec[x] = 1;
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1, 0);
    bfs(n, 1);

    int len = d[0][n], maxi = -1;
    for(int dd = MN-1; dd >= 0; dd--) {
        if(dist[0][dd].empty()) continue;

        if(maxi != -1) ans = max(ans, min(len, dd + 1 + maxi));

        vector<int> &vs = dist[0][dd];
        for(int v : vs) maxi = max(maxi, d[1][v]);

        if(vs.size() > 1) ans = max(ans, min(len, dd + 1 + maxi));
    }

    printf("%d\n", ans);
    return 0;
}