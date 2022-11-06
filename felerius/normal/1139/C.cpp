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

static constexpr uint64_t MOD = 1000000007;

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;

    vector<vector<size_t>> adj(n);
    for (size_t i = 0; i < n - 1; ++i) {
        size_t a, b;
        int j;
        cin >> a >> b >> j;
        if (j == 0) {
            adj[a-1].emplace_back(b-1);
            adj[b-1].emplace_back(a-1);
        }
    }

    vector<bool> visited(n, false);
    uint64_t red_seq_count = 0;
    for (size_t i = 0; i < n; ++i) {
        if (visited[i]) {
            continue;
        }

        queue<size_t> q;
        q.push(i);
        visited[i] = true;
        size_t count = 0;
        while (!q.empty()) {
            count++;
            auto a = q.front();
            q.pop();

            for (auto b : adj[a]) {
                if (!visited[b]) {
                    visited[b] = true;
                    q.push(b);
                }
            }
        }

        uint64_t count_to_k = 1;
        for (size_t j = 0; j < k; ++j) {
            count_to_k *= count;
            count_to_k %= MOD;
        }

        red_seq_count += count_to_k;
        red_seq_count %= MOD;
    }

    uint64_t n_to_k = 1;
    for (size_t j = 0; j < k; ++j) {
        n_to_k *= n;
        n_to_k %= MOD;
    }

    cout << ((MOD + n_to_k - red_seq_count) % MOD) << '\n';

    return 0;
}