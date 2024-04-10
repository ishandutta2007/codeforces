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

// Contest: Codeforces Round #584 - Dasha Code Championship - Elimination Round (rated, open for everyone, Div. 1 + Div. 2) (https://codeforces.com/contest/1209)
// Problem: F: Koala and Notebook (https://codeforces.com/contest/1209/problem/F)

using namespace std;

int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    int new_node = n;
    vector<array<vector<int>, 10>> adj(1'200'000);
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y; --x; --y;
        for (auto [from, to] : {pair(x, y), pair(y, x)}) {
            int num = i + 1;
            while (num > 9) {
                adj[new_node][num % 10].push_back(to);
                to = new_node++;
                num /= 10;
            }
            adj[from][num].push_back(to);
        }
    }

    vector<int> ans(adj.size(), -1);
    ans[0] = 0;
    queue<int> q;
    q.push(0); q.push(-1);
    vector<int> group;
    while (!q.empty()) {
        group.clear();
        while (true) {
            int v = q.front(); q.pop();
            if (v == -1)
                break;
            group.push_back(v);
        }

        for (int i = 0; i < 10; ++i) {
            bool dirty = false;
            for (auto v : group) {
                for (auto v2 : adj[v][i]) {
                    if (ans[v2] == -1) {
                        ans[v2] = ((int64_t)ans[v] * 10 + i) % M;
                        dirty = true;
                        q.push(v2);
                    }
                }
            }

            if (dirty)
                q.push(-1);
        }
    }

    for (int i = 1; i < n; ++i)
        cout << ans[i] << '\n';

    return 0;
}