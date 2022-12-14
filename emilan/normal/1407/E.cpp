#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 1, inf = 0x01010101;
vector<int> adj_t[N][2];
int dist[N][2];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v, t;
        cin >> u >> v >> t;
        adj_t[v][t].push_back(u);
    }

    queue<int> q;
    memset(dist, inf, sizeof(dist));

    q.push(n);
    dist[n][0] = dist[n][1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int d = max(dist[u][0], dist[u][1]);

        for (int t = 0; t < 2; t++) {
            for (int v : adj_t[u][t]) {
                if (dist[v][t] != inf) continue;

                dist[v][t] = min(d + 1, dist[v][t]);
                if (dist[v][!t] != inf) q.push(v);
            }
        }
    }

    int d = max(dist[1][0], dist[1][1]);
    if (d == inf) cout << -1;
    else cout << d;
    cout << '\n';

    for (int u = 1; u <= n; u++) {
        cout << (dist[u][0] < dist[u][1]);
    }
}