#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (41) Destroying Roads (Difficulty: 5) (http://codeforces.com/problemset/problem/543/B)

using namespace std;

int INF = 1'000'000'000;

int main() {
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    --s1; --t1; --s2; --t2;

    vector<vector<int>> dist(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            for (auto v2 : adj[v]) {
                if (dist[i][v2] == -1) {
                    dist[i][v2] = dist[i][v] + 1;
                    q.push(v2);
                }
            }
        }
    }

    int best = -1;
    if (dist[s1][t1] <= l1 && dist[s2][t2] <= l2)
        best = m - dist[s1][t1] - dist[s2][t2];
    auto path_len = [&](int a, int i, int j, int b) {
        return dist[a][i] + dist[i][j] + dist[j][b];
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (path_len(s1, i, j, t1) <= l1 && path_len(s2, i, j, t2) <= l2)
                best = max(best, m - path_len(s1, i, j, t1) - path_len(s2, i, j, t2) + dist[i][j]);
            if (path_len(s1, i, j, t1) <= l1 && path_len(s2, j, i, t2) <= l2)
                best = max(best, m - path_len(s1, i, j, t1) - path_len(s2, j, i, t2) + dist[i][j]);
        }
    }

    cout << best << '\n';
    return 0;
}