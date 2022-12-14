#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5 + 1;
vector<pair<int, int>> adj[N];
ll dist[N];
int par[N];

void dijkstra(int s) {
    priority_queue<pair<ll, int>> q;

    dist[s] = 0;
    q.emplace(0, s);
    while (!q.empty()) {
        int u = q.top().second;
        ll d = -q.top().first;
        q.pop();

        if (d != dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                par[v] = u;
                q.emplace(-(d + w), v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    memset(dist, 1, sizeof(dist));
    dijkstra(1);

    if (!par[n]) cout << -1;
    else {
        vector<int> ans;
        for (; n; n = par[n]) ans.push_back(n);
        reverse(ans.begin(), ans.end());
        for (int u : ans) cout << u << ' ';
    }
}