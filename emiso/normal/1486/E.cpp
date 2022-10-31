#include <bits/stdc++.h>

using namespace std;

#define MN 100020

int n, m, dist[MN][51], ok;
vector<pair<int, int>> adj[MN];

struct node {
    int u, t, d;
    bool operator < (const node& o) const {
        if(d == o.d) return t > o.t;
        return d > o.d;
    }
};

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 50; j++)
            dist[i][j] = INT_MAX;

    dist[1][0] = 0;
    priority_queue<node> pq;
    pq.push({1, 0, 0});

    while(!pq.empty()) {
        auto tt = pq.top(); pq.pop();
        int u = tt.u, t = tt.t, d = tt.d;
        if(d != dist[u][t]) continue;

        for(auto ed : adj[u]) {
            int v = ed.first, c = ed.second;

            if(t == 0) {
                if(d < dist[v][c]) {
                    dist[v][c] = d;
                    pq.push({v, c, dist[v][c]});
                }
            } else {
                if(d+(t+c)*(t+c) < dist[v][0]) {
                    dist[v][0] = d+(t+c)*(t+c);
                    pq.push({v, 0, dist[v][0]});
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", (dist[i][0] < INT_MAX) ? dist[i][0] : -1);
    }
    return 0;
}