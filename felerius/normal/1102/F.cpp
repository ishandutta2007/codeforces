#include <array>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>


using namespace std;

constexpr static size_t N = 16;
constexpr static size_t M = 10'000;
using DiffType = int;

template <class T, size_t Width, size_t Height>
class Matrix {
private:
    array<T, Width * Height> data_;

public:
    T& operator[](pair<size_t, size_t> idx) {
        auto[x, y] = idx;
        return data_[y * Width + x];
    }

    const T& operator[](pair<size_t, size_t> idx) const {
        auto[x, y] = idx;
        return data_[y * Width + x];
    }
};

size_t n, m;
Matrix<int, M, N> mat;
Matrix<DiffType, N, N> adj;
Matrix<DiffType, N, N> last_to_first_adj;
Matrix<DiffType, 1u << (N - 1), N - 1> dp;

constexpr inline pair<size_t, size_t> next_node_index(uint16_t mask,
                                                      size_t excluded) {
    size_t index = __builtin_ctz(mask);
    return {index, index + (index >= excluded)};
}

DiffType calc_last_to_first(size_t first, size_t last) {
    if (m < 2) {
        return numeric_limits<DiffType>::max();
    }

    DiffType min_diff = abs(mat[{1, first}] - mat[{0, last}]);
    for (size_t i = 2; i < m; ++i) {
        min_diff = min(min_diff, (DiffType)abs(mat[{i, first}] - mat[{i - 1, last}]));
    }

    return min_diff;
}

DiffType tsp(size_t first) {
    uint16_t mask_max = 1u << (n - 1);
    for (uint16_t mask = 1; mask < mask_max; ++mask) {
        if (__builtin_popcount(mask) == 1) {
            auto [bit_index, node_index] = next_node_index(mask, first);
            dp[{mask, bit_index}] = adj[{first, node_index}];
            continue;
        }

        auto mask_iter = mask;
        while (mask_iter != 0) {
            auto [last_bit, last_node] = next_node_index(mask_iter, first);
            mask_iter &= mask_iter - 1;

            uint16_t mask_without_last = mask & ~(1u << last_bit);
            auto mask_iter2 = mask_without_last;
            DiffType best = 0;
            while (mask_iter2 != 0) {
                auto [second_last_bit, second_last_node] = next_node_index(mask_iter2, first);
                mask_iter2 &= mask_iter2 - 1;
                auto value = min(dp[{mask_without_last, second_last_bit}], adj[{last_node, second_last_node}]);
                best = max(best, value);
            }

            dp[{mask, last_bit}] = best;
        }
    }

    auto full_mask = mask_max - 1;
    auto best = 0;
    for (size_t last_bit = 0; last_bit < n - 1; ++last_bit) {
        size_t last_node = last_bit + (last_bit >= first);
        auto value = min(dp[{full_mask, last_bit}], last_to_first_adj[{last_node, first}]);
        best = max(best, value);
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> mat[{j, i}];
        }
    }

    if (n == 1) {
        cout << calc_last_to_first(0, 0) << '\n';
        return 0;
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            last_to_first_adj[{i, j}] = calc_last_to_first(i, j);
        }

        for (size_t j = i + 1; j < n; ++j) {
            DiffType min_diff = abs(mat[{0, i}] - mat[{0, j}]);
            for (size_t k = 1; k < m; ++k) {
                min_diff = min(min_diff, (DiffType)abs(mat[{k, i}] - mat[{k, j}]));
            }

            adj[{i, j}] = adj[{j, i}] = min_diff;
            last_to_first_adj[{i, j}] = calc_last_to_first(i, j);
        }
    }

    DiffType best_overall = 0;
    for (size_t first = 0; first < n; ++first) {
        best_overall = max(best_overall, tsp(first));
    }

    cout << best_overall << '\n';

    return 0;
}