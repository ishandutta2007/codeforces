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

template <class Get, class Set>
size_t calc_sort(vector<size_t>& indices, Get&& get, Set&& set) {
    sort(indices.begin(), indices.end(), [&get](size_t i, size_t j) {
        return get(i) < get(j);
    });

    size_t idx = 1;
    auto prev_val = get(indices[0]);
    set(indices[0], idx);
    for (size_t i = 1; i < indices.size(); ++i) {
        if (prev_val != get(indices[i])) {
            ++idx;
            prev_val = get(indices[i]);
        }

        set(indices[i], idx);
    }

    return idx;
}

int main() {
    ios_base::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;
    vector<vector<uint32_t>> a(n);
    for (size_t i = 0; i < n; ++i) {
        a[i].resize(m);
        for (size_t j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<size_t> row_max(n);
    vector<size_t> col_max(m);
    vector<size_t> indices(m);
    iota(indices.begin(), indices.end(), 0);
    vector<vector<pair<size_t, size_t>>> vals(n);
    for (size_t i = 0; i < n; ++i) {
        vals[i].resize(m);
        row_max[i] = calc_sort(indices, [&](size_t j) {
            return a[i][j];
        }, [&](size_t j, size_t idx) {
            vals[i][j].first = idx;
        });
    }

    indices.resize(n);
    iota(indices.begin(), indices.end(), 0);
    for (size_t i = 0; i < m; ++i) {
        col_max[i] = calc_sort(indices, [&](size_t j) {
            return a[j][i];
        }, [&](size_t j, size_t idx) {
            vals[j][i].second = idx;
        });
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            auto [left, up] = vals[i][j];
            cout << (max(left, up) + max(row_max[i] - left, col_max[j] - up)) << ' ';
        }

        cout << '\n';
    }

    return 0;
}