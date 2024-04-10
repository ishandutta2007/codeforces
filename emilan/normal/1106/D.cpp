#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
vector<int> adj[N];
bitset<N> vis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<int> pq;
    pq.push(0);
    vector<int> ans;
    while (!pq.empty()) {
        int u = -pq.top();
        pq.pop();
        if (vis[u]) continue;

        vis[u] = true;
        ans.push_back(u + 1);

        for (int v : adj[u]) {
            pq.push(-v);
        }
    }

    for (int i : ans) cout << i << ' ';
}