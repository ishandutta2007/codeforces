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

constexpr uint64_t MOD = 998244353;

uint64_t color_from(size_t node, const vector<vector<size_t>>& adjacencies,
                    vector<uint8_t>& color) {
    queue<size_t> q;
    color[node] = 1;
    q.push(node);
    size_t count1 = 1;
    size_t count2 = 0;

    while (!q.empty()) {
       auto node2 = q.front();
       q.pop();

       for (auto neigh : adjacencies[node2]) {
           if (color[neigh] == 0) {
               color[neigh] = 3 - color[node2];
               if (color[neigh] == 1) {
                   count1++;
               } else {
                   count2++;
               }
               q.push(neigh);
           } else if (color[neigh] == color[node2]) {
               return 0;
           }
       }
    }

    uint64_t pos1 = 1;
    uint64_t pos2 = 1;
    while (count1--) {
        pos1 = (2 * pos1) % MOD;
    }
    while (count2--) {
        pos2 = (2 * pos2) % MOD;
    }

    return (pos1 + pos2) % MOD;
}

void solve_testcase() {
    size_t n, m;
    cin >> n >> m;

    vector<vector<size_t>> adjacencies(n);
    while (m--) {
        size_t a, b;
        cin >> a >> b;
        a--;
        b--;
        adjacencies[a].emplace_back(b);
        adjacencies[b].emplace_back(a);
    }

    vector<uint8_t> color(n, 0);
    uint64_t colorings = 1;

    for (size_t i = 0; i < n; ++i) {
        if (color[i] != 0) {
            continue;
        }

        auto pos = color_from(i, adjacencies, color);
        colorings = (colorings * pos) % MOD;
    }

    cout << colorings << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }

    return 0;
}