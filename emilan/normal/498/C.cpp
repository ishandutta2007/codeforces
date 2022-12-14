#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int INF = 1 << 30;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a_n, a_m;
    cin >> a_n >> a_m;
    vector<int> a(a_n);
    for (int &x : a) cin >> x;
    vector<vector<int>> a_adj(a_n);
    while (a_m--) {
        int i, j;
        cin >> i >> j;
        i--, j--;

        if (i & 1) a_adj[i].push_back(j);
        else a_adj[j].push_back(i);
    }

    int n = 2;
    vector<map<int, pii>> decomp(a_n);
    for (int i = 0; i < a_n; i++) {
        int x = a[i];
        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0) {
                x /= d;
                decomp[i][d] = {1, n++};

                while (x % d == 0) {
                    x /= d;
                    decomp[i][d].first++;
                }
            }
        }
        if (x != 1) decomp[i][x] = {1, n++};
    }

    // u = 0 -> source
    // u = 1 -> sink
    vector<vector<int>> adj(n);
    vector<vector<int>> cap(n, vector<int>(n));
    for (int i = 1; i < a_n; i += 2) {
        for (auto [d, _pair] : decomp[i]) {
            auto [p, u] = _pair;

            adj[0].push_back(u);
            adj[u].push_back(0);
            cap[0][u] = p;

            for (int j : a_adj[i]) if (a[j] % d == 0) {
                auto [_p, v] = decomp[j][d];

                adj[u].push_back(v);
                adj[v].push_back(u);
                cap[u][v] = INF;
            }
        }
    }
    for (int i = 0; i < a_n; i += 2) {
        for (auto [d, _pair] : decomp[i]) {
            auto [p, u] = _pair;

            adj[u].push_back(1);
            adj[1].push_back(u);
            cap[u][1] = p;
        }
    }

    // mf  30 * a_n / 2  1500
    // m  9 * a_m  900
    int mf = 0;
    for (;;) {
        vector<int> par(n, -1);
        vector<int> flow(n);
        queue<int> q;

        par[0] = 0;
        flow[0] = INF;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == 1) break;

            for (int v : adj[u]) {
                if (par[v] != -1 || cap[u][v] == 0) continue;

                par[v] = u;
                flow[v] = min(flow[u], cap[u][v]);
                q.push(v);
            }
        }

        if (flow[1] == 0) break;

        mf += flow[1];

        for (int u = 1; u != 0; u = par[u]) {
            cap[ par[u] ][u] -= flow[1];
            cap[u][ par[u] ] += flow[1];
        }
    }

    cout << mf << "\n";
}