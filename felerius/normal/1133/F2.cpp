#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    size_t n, m, d;
    cin >> n >> m >> d;

    vector<vector<size_t>> adj(n);
    for (size_t i = 0; i < m; ++i) {
        size_t a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    vector<bool> visited(n);
    set<size_t> new_neighbors;
    visited[0] = true;
    queue<size_t> q;
    for (auto neigh : adj[0]) {
        if (!visited[neigh]) {
            new_neighbors.emplace(neigh);
            q.push(neigh);
            visited[neigh] = true;
            while (!q.empty()) {
                auto idx = q.front();
                q.pop();
                for (auto neigh2 : adj[idx]) {
                    if (!visited[neigh2]) {
                        visited[neigh2] = true;
                        q.push(neigh2);
                    }
                }
            }
        }
    }

    for (auto neigh : adj[0]) {
        if (new_neighbors.size() == d) {
            break;
        }

        new_neighbors.emplace(neigh);
    }

    if (new_neighbors.size() != d) {
        cout << "NO\n";
        return 0;
    }

    adj[0].resize(d);
    copy(new_neighbors.begin(), new_neighbors.end(), adj[0].begin());

    vector<pair<size_t, size_t>> tree;
    {
        queue<size_t> q;
        vector<bool> visited(n);
        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            auto idx = q.front();
            q.pop();

            for (auto neigh : adj[idx]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                    tree.emplace_back(idx, neigh);
                }
            }
        }
    }

    cout << "YES\n";
    for (auto [a, b] : tree) {
        cout << (a + 1) << ' ' << (b + 1) << '\n';
    }

    return 0;
}