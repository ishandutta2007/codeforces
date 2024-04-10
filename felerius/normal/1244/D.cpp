#include <bits/stdc++.h>

// Contest: Codeforces Round #592 (Div. 2) (https://codeforces.com/contest/1244)
// Problem: D: Paint the Tree (https://codeforces.com/contest/1244/problem/D)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int n;
array<vector<ll>, 3> c;
vector<vector<int>> adj;
array<vector<int>, 6> cols;

ll dfs(int v, int par, int col, int par_col, int col_idx) {
    ll cost = c[col][v];
    cols[col_idx][v] = col;
    ll nei_cost = 0;
    if (adj[v].size() > 1) {
        int nei = adj[v][0] == par ? adj[v][1] : adj[v][0];
        int nei_col = 0;
        while (nei_col == col || nei_col == par_col)
            ++nei_col;
        nei_cost = dfs(nei, v, nei_col, col, col_idx);
    }
    return cost + nei_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    adj.resize(n);
    for (int i = 0; i < 3; ++i) {
        c[i].resize(n);
        for (auto& ci : c[i]) cin >> ci;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (adj[i].size() > 2) {
            cout << "-1\n";
            return 0;
        }
    }

    ll min_cost = 1e18;
    int min_col = 0;
    int i = 0;
    for (auto [c1, c2, c3] : {tuple(0, 1, 2), tuple(0, 2, 1), tuple(1, 0, 2), tuple(1, 2, 0), tuple(2, 0, 1), tuple(2, 1, 0)}) {
        cols[i].resize(n);
        cols[i][0] = c1;
        ll cost = c[c1][0];
        if (!adj[0].empty())
            cost += dfs(adj[0][0], 0, c2, c1, i);
        if (adj[0].size() == 2)
            cost += dfs(adj[0][1], 0, c3, c1, i);
        if (cost < min_cost) {
            min_col = i;
            min_cost = cost;
        }
        ++i;
    }

    cout << min_cost << '\n';
    for (auto col : cols[min_col])
        cout << (col + 1) << ' ';
    cout << '\n';

    return 0;
}