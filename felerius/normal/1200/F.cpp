#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

constexpr int M = 2520;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    vector<array<int, M>> ans(n);
    for (auto& a : ans) {
        a.fill(-1);
    }

    vector<uint32_t> k(n);
    for (auto& ki : k) {
        int32_t a;
        cin >> a;
        ki = (a % M + M) % M;
    }

    vector<vector<size_t>> adj(n);
    for (size_t i = 0; i < n; ++i) {
        size_t mi;
        cin >> mi;
        adj[i].resize(mi);
        for (auto& eij : adj[i]) {
            cin >> eij;
            --eij;
        }
    }

    uint64_t time = 0;
    vector<array<uint64_t, M>> times(n);
    for (auto& t : times) {
        t.fill(0);
    }

    vector<pair<size_t, uint64_t>> vis;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < M; ++j) {
            if (ans[i][j] != -1) {
                continue;
            }

            vis.clear();
            auto start_time = ++time;
            auto node = i;
            auto c = (uint64_t)j;
            while (ans[node][c] == -1 && times[node][c] < start_time) {
                vis.emplace_back(node, c);
                times[node][c] = time++;
                node = adj[node][c % adj[node].size()];
                c = (c + k[node]) % M;
            }

            int cycle_length = ans[node][c];
            if (cycle_length == -1) {
                array<bool, 1000> seen = {0};
                for (size_t x = 0; x < time - times[node][c]; ++x) {
                    seen[(rbegin(vis) + x)->first] = true;
                }

                cycle_length = accumulate(begin(seen), end(seen), 0);
            }

            for (auto [no, c2] : vis) {
                ans[no][c2] = cycle_length;
            }
        }
    }

    size_t q = 0;
    cin >> q;

    for (size_t i = 0; i < q; ++i) {
        size_t x;
        int32_t y;
        cin >> x >> y;
        size_t c = (y % M + M + k[x - 1]) % M;
        cout << ans[x - 1][c] << '\n';
    }

    return 0;
}