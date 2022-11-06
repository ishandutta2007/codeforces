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
// Problem: D: Cow and Snacks (https://codeforces.com/contest/1209/problem/D)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < k; ++i) {
        int x, y; cin >> x >> y; --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> visited(n);
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i])
            continue;
        ++c;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            for (int nei : adj[v]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }
    }

    cout << (k - (n - c)) << '\n';

    return 0;
}