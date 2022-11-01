#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int n, m, k, a[1010][1010], dist[41][1010][1010], dc[41][41];
vector<ii> adj[1010][1010], occ[41];

void bfs(int t) {
    queue<ii> fila;

    dc[t][t] = 0;
    for(auto &tt : occ[t]) {
        fila.push(tt);
        dist[t][tt.first][tt.second] = 0;
    }

    while(!fila.empty()) {
        int i = fila.front().first, j = fila.front().second;
        fila.pop();

        for(auto &ch : adj[i][j]) {
            int x = ch.first, y = ch.second;
            if(dist[t][x][y] == -1) {
                dist[t][x][y] = dist[t][i][j] + 1;
                dc[t][a[x][y]] = min(dc[t][a[x][y]], dist[t][x][y]);
                fila.push({x, y});
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    memset(dist, -1, sizeof dist);
    for(int i = 0; i <= k; i++)
        for(int j = 0; j <= k; j++)
            dc[i][j] = 112345678;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i > 1) adj[i][j].emplace_back(i-1, j);
            if(j > 1) adj[i][j].emplace_back(i, j-1);
            if(i < n) adj[i][j].emplace_back(i+1, j);
            if(j < m) adj[i][j].emplace_back(i, j+1);
            occ[a[i][j]].emplace_back(i, j);
        }
    }

    for(int i = 1; i <= k; i++)
        bfs(i);

    for(int p = 1; p <= k; p++)
        for(int i = 1; i <= k; i++)
            for(int j = 1; j <= k; j++)
                dc[i][j] = min(dc[i][j], dc[i][p] + dc[p][j] + 1);

    int q;
    scanf("%d", &q);
    while(q--) {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        int ans = abs(r1 - r2) + abs(c1 - c2);

        for(int i = 1; i <= k; i++) {
            ans = min(ans, dist[i][r1][c1] + 1 + dist[i][r2][c2]);
            for(int j = 1; j <= k; j++)
                ans = min(ans, dist[i][r1][c1] + 1 + dc[i][j] + 1 + dist[j][r2][c2]);
        }

        printf("%d\n", ans);
    }

    return 0;
}