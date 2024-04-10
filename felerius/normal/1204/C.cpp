#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

// Contest: Codeforces Round #581 (Div. 2) (https://codeforces.com/contest/1204)
// Problem: C: Anna, Svyatoslav and Maps (https://codeforces.com/contest/1204/problem/C)

using namespace std;

template <size_t Size>
struct Matrix {
    array<size_t, Size * Size> data;

    size_t& operator()(size_t x, size_t y) {
        return data[y * Size + x];
    }
};

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<vector<size_t>> adj(n);
    string s;
    for (size_t i = 0; i < n; ++i) {
        cin >> s;
        for (size_t j = 0; j < n; ++j) {
            if (s[j] == '1') {
                adj[i].emplace_back(j);
            }
        }
    }

    size_t m;
    cin >> m;
    vector<size_t> p(m);
    for (auto& pi : p) {
        cin >> pi;
        --pi;
    }

    Matrix<100> dist;
    dist.data.fill(2 * n);
    for (size_t i = 0; i < n; ++i) {
        for (auto ne : adj[i]) {
            dist(i, ne) = 1;
        }
    }
    for (size_t k = 0; k < n; ++k) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                dist(i, j) = min(dist(i, j), dist(i, k) + dist(k, j));
            }
        }
    }

    vector<size_t> v = {p[0]};
    size_t d = 0;
    for (size_t i = 1; i < m; ++i) {
        ++d;
        if (p[i] == v.back() || d > dist(v.back(), p[i])) {
            d = 1;
            v.emplace_back(p[i - 1]);
        }
    }

    v.emplace_back(p.back());
    cout << v.size() << '\n';
    for (auto vi : v) {
        cout << (vi + 1) << ' ';
    }
    cout << '\n';

    return 0;
}