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

    size_t n, m, k;
    cin >> n >> m >> k;

    vector<pair<int64_t, pair<size_t, size_t>>> e(m);
    for (size_t i = 0; i < m; ++i) {
        cin >> e[i].second.first >> e[i].second.second >> e[i].first;
        e[i].second.first--;
        e[i].second.second--;
    }

    sort(begin(e), end(e));
    if (m > k) {
        e.resize(k);
    }

    vector<size_t> nodes;
    nodes.reserve(2 * k);
    for (auto [_, p] : e) {
        auto [a, b] = p;
        nodes.emplace_back(a);
        nodes.emplace_back(b);
    }

    sort(begin(nodes), end(nodes));
    auto last = unique(begin(nodes), end(nodes));
    nodes.erase(last, end(nodes));

    vector<vector<pair<size_t, int64_t>>> adj(n);
    for (auto [w, p] : e) {
        auto [a, b] = p;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
//    for (auto [w, p] : e) {
//        auto [a, b] = p;
//        auto it = lower_bound(begin(nodes), end(nodes), a);
//        auto af = it - begin(nodes);
//        it = lower_bound(begin(nodes), end(nodes), b);
//        auto bf = it - begin(nodes);
//        adj[af].emplace_back(bf, w);
//        adj[bf].emplace_back(af, w);
//    }

    vector<int64_t> paths;
    vector<bool> vis(n);
    vector<int64_t> shortest(n);
    for (auto i : nodes) {
        priority_queue<pair<int64_t, size_t>> q;

        for (auto j : nodes) {
            vis[j] = false;
            shortest[j] = numeric_limits<int64_t>::max();
        }

        q.emplace(0, i);
        shortest[i] = 0;
        while (!q.empty()) {
            auto [neg_dist, node] = q.top();
            q.pop();
            if (vis[node]) {
                continue;
            }

            vis[node] = true;
            if (node > i) {
                paths.emplace_back(-neg_dist);
            }

            for (auto [neighbor, w] : adj[node]) {
                if (-neg_dist + w < shortest[neighbor]) {
                    shortest[neighbor] = -neg_dist + w;
                    q.emplace(neg_dist - w, neighbor);
                }
            }
        }
    }

    sort(begin(paths), end(paths));
    cout << paths[k - 1] << '\n';

    return 0;
}