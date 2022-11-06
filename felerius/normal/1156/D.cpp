//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>


using namespace std;

struct Result {
    uint64_t in_tree;
    uint64_t _0;
    uint64_t _1;
    uint64_t _01;
    uint64_t _10;
};

void run_dp(const vector<vector<pair<size_t, bool>>>& adj, size_t node, size_t parent, vector<Result>& dp) {
    auto& r = dp[node];

    for (auto [neigh, edge] : adj[node]) {
        if (neigh == parent) {
            continue;
        }

        run_dp(adj, neigh, node, dp);
        if (edge) {
            r._1 += dp[neigh]._1 + 1;
            r._10 += dp[neigh]._0 + dp[neigh]._10;
        } else {
            r._0 += dp[neigh]._0 + 1;
            r._01 += dp[neigh]._1 + dp[neigh]._01;
        }

        r.in_tree += dp[neigh].in_tree;
    }

    r.in_tree += 2 * r._0 + 2 * r._1 + r._01 + r._10;

    for (auto [neigh, edge] : adj[node]) {
        if (neigh == parent) {
            continue;
        }

        auto& rn = dp[neigh];
        if (edge) {
            r.in_tree += (rn._1 + 1) * (r._10 - rn._10 - rn._0);
            r.in_tree += (rn._1 + 1) * r._0;
            r.in_tree += (rn._1 + 1) * (r._1 - rn._1 - 1);
        } else {
            r.in_tree += (rn._0 + 1) * (r._0 - rn._0 - 1);
            r.in_tree += (rn._0 + 1) * (r._01 - rn._01 - rn._1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<vector<pair<size_t, bool>>> adj(n);
    for (size_t i = 0; i < n - 1; ++i) {
        size_t a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    vector<Result> dp(n, {0, 0, 0, 0, 0});
    run_dp(adj, 0, n, dp);

    cout << dp[0].in_tree << '\n';

    return 0;
}