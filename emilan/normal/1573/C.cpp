#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    using P = pair<int, bool>;
    vector<vector<P>> adj_o(n);
    vector<int> deg_i(n);
    for (int v = 0; v < n; v++) {
        cin >> deg_i[v];
        for (int i = 0; i < deg_i[v]; i++) {
            int u;
            cin >> u;
            u--;
            adj_o[u].emplace_back(v, u < v);
        }
    }

    int rounds = 0;
    int vis_cnt = 0;
    vector<int> ping(n);

    vector<int> ready;
    for (int u = 0; u < n; u++) if (deg_i[u] == 0) {
        ready.push_back(u);
    }
    for (; !ready.empty(); rounds++) {
        vector<int> nxt;
        while (!ready.empty()) {
            int u = ready.back();
            ready.pop_back();
            vis_cnt++;
            for (auto [v, later] : adj_o[u]) {
                ping[v] = max(ping[v], rounds + !later);
                if (--deg_i[v] == 0) {
                    if (ping[v] == rounds) ready.push_back(v);
                    else nxt.push_back(v);
                }
            }
        }
        swap(ready, nxt);
    }

    if (vis_cnt != n) cout << -1;
    else cout << rounds;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}