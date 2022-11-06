#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    vector<vector<size_t>> adj(n);
    for (size_t i = 0; i < m; ++i) {
        size_t a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    auto it = max_element(adj.begin(), adj.end(), [](auto& v1, auto& v2) {
        return v1.size() < v2.size();
    });
    auto start_idx = it - adj.begin();

    vector<pair<size_t, size_t>> tree;
    vector<bool> visited(n);
    visited[start_idx] = true;
    queue<size_t> q;
    q.push(start_idx);
    while (!q.empty()) {
        auto idx = q.front();
        q.pop();

        for (auto neighbor : adj[idx]) {
            if (!visited[neighbor]) {
                tree.emplace_back(idx, neighbor);
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    for (auto [a, b] : tree) {
        cout << (a + 1) << ' ' << (b + 1) << '\n';
    }

    return 0;
}