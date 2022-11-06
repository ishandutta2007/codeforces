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

int main() {
    ios_base::sync_with_stdio(false);

    size_t n, m, q;
    cin >> n >> m >> q;

    vector<uint32_t> perm(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> perm[i];
        perm[i]--;
    }

    vector<uint32_t> a(m);
    for (size_t i = 0; i < m; ++i) {
        cin >> a[i];
        a[i]--;
    }

    vector<uint32_t> next(n);
    next[perm.back()] = perm.front();
    for (size_t i = 0; i < n - 1; ++i) {
        next[perm[i]] = perm[i + 1];
    }

    constexpr static auto IMPOSSIBLE = numeric_limits<size_t>::max();
    size_t log2n = 8 * sizeof(int) - __builtin_clz((int)n);
    vector<vector<size_t>> cycle_ends(log2n);
    for (size_t i = 0; i < log2n; ++i) {
        cycle_ends[i].resize(m);
    }

    vector<size_t> closest_next(n, IMPOSSIBLE);
    for (int i = m - 1; i >= 0; --i) {
        cycle_ends[0][i] = closest_next[next[a[i]]];
        closest_next[a[i]] = i;
    }

    for (size_t i = 1; i < log2n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            auto next = cycle_ends[i - 1][j];
            cycle_ends[i][j] = next == IMPOSSIBLE ? IMPOSSIBLE : cycle_ends[i - 1][next];
        }
    }

    vector<size_t> bits;
    for (size_t i = 0; i < log2n; ++i) {
        if (((n - 1) >> i) & 1) {
            bits.emplace_back(i);
        }
    }

    vector<size_t> min_right(m);
    size_t closest = IMPOSSIBLE;
    for (int i = m - 1; i >= 0; --i) {
        size_t next = i;
        for (auto j : bits) {
            next = cycle_ends[j][next];
            if (next == IMPOSSIBLE) {
                break;
            }
        }

        closest = min(closest, next);
        min_right[i] = closest;
    }

    for (size_t i = 0; i < q; ++i) {
        size_t l, r;
        cin >> l >> r;
        cout << (int)(min_right[l - 1] <= r - 1);
    }

    cout << '\n';

    return 0;
}