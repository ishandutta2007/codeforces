#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

tuple<size_t, size_t, size_t>
count_nice_edges(size_t parent, size_t node, size_t total_red,
                 size_t total_blue,
                 const vector<vector<size_t>>& adj,
                 const vector<uint16_t>& colors) {
    size_t num_red = colors[node] == 1;
    size_t num_blue = colors[node] == 2;
    size_t num_nice = 0;
    for (auto n : adj[node]) {
        if (n == parent) {
            continue;
        }

        auto[sub_nice, sub_red, sub_blue] = count_nice_edges(node, n, total_red,
                                                             total_blue, adj,
                                                             colors);
        num_nice += sub_nice;
        num_red += sub_red;
        num_blue += sub_blue;
    }

    if ((num_blue == 0 && num_red == total_red) || (num_red == 0 && num_blue == total_blue)) {
        num_nice++;
    }

    return {num_nice, num_red, num_blue};
}

int main() {
    ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<uint16_t> colors(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> colors[i];
    }

    vector<vector<size_t>> adj(n);
    for (size_t i = 0; i < n - 1; ++i) {
        size_t a, b;
        cin >> a >> b;
        adj[a - 1].emplace_back(b - 1);
        adj[b - 1].emplace_back(a - 1);
    }

    auto total_red = count(colors.begin(), colors.end(), 1);
    auto total_blue = count(colors.begin(), colors.end(), 2);

    size_t num_nice = 0;
    for (auto n : adj[0]) {
        auto [nice, _, __] = count_nice_edges(0, n, total_red, total_blue, adj, colors);
        num_nice += nice;
    }

    cout << num_nice << '\n';

    return 0;
}