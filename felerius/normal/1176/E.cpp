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
    ios::sync_with_stdio(false);

    size_t t;
    cin >> t;
    while (t--) {
        size_t n, m;
        cin >> n >> m;

        vector<vector<size_t>> adj(n);

        for (size_t i = 0; i < m; ++i) {
            size_t u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[v].emplace_back(u);
            adj[u].emplace_back(v);
        }

        queue<pair<size_t, size_t>> q;
        array<vector<size_t>, 2> layers;
        vector<bool> visited(n);

        q.emplace(0, 0);
        visited[0] = true;
        while (!q.empty()) {
            auto [i, l] = q.front();
            q.pop();

            layers[l % 2].emplace_back(i);

            for (auto k : adj[i]) {
                if (!visited[k]) {
                    visited[k] = true;
                    q.emplace(k, l + 1);
                }
            }
        }

        auto cover = layers[0].size() < layers[1].size() ? layers[0] : layers[1];
        cout << cover.size() << '\n';
        for (auto i : cover) {
            cout << (i + 1) << ' ';
        }
        cout << '\n';
    }

    return 0;
}