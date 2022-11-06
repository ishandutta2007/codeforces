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

template <class T, size_t Size>
struct Matrix {
    array<T, Size * Size> data;

    T& operator()(size_t x, size_t y) {
        return data[y * Size + x];
    }
};

struct Dp {
    bool left;
    bool right;
    bool up;
    bool down;
};

Matrix<bool, 2000> m;
Matrix<Dp, 2000> dp;

int main() {
    ios::sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;

    for (size_t y = 0; y < n; ++y) {
        for (size_t x = 0; x < n; ++x) {
            char c;
            cin >> c;
            m(y, x) = c == 'W';
        }
    }

    for (size_t y = 0; y < n; ++y) {
        for (size_t x = 0; x < n; ++x) {
            dp(y, x).left = m(y, x) && (x == 0 ? true : dp(y, x - 1).left);
            dp(y, x).up = m(y, x) && (y == 0 ? true : dp(y - 1, x).up);
        }
    }

    for (int y = n - 1; y >= 0; --y) {
        for (int x = n - 1; x >= 0; --x) {
            dp(y, x).right = m(y, x) && (x + 1 == n ? true : dp(y, x + 1).right);
            dp(y, x).down = m(y, x) && (y + 1 == n ? true : dp(y + 1, x).down);
        }
    }

    vector<size_t> full_vert(n);
    for (size_t i = 0; i < n; ++i) {
        full_vert[i] = (i == 0 ? 0 : full_vert[i - 1]) + dp(0, i).down;
    }

    vector<size_t> full_hor(n);
    for (size_t i = 0; i < n; ++i) {
        full_hor[i] = (i == 0 ? 0 : full_hor[i - 1]) + dp(i, 0).right;
    }

    vector<bool> vert(k);
    size_t vert_count = 0;

    vector<array<bool, 2000>> dp2(k);
    vector<size_t> sum(n);
    dp2.back().fill(false);
    for (size_t y = 0; y < k - 1; ++y) {
        for (size_t x = 0; x < n; ++x) {
            dp2[y][x] = (x == 0 ? true : dp(y, x - 1).left) && (x + k < n ? dp(y, x + k).right : true);
            sum[x] += dp2[y][x];
        }
    }

    size_t cur_idx = k - 1;
    size_t best = 0;
    for (size_t y = k - 1; y < n; ++y) {
        auto& cur = dp2[cur_idx];
        size_t vert_idx = 0;
        vert_count = 0;
        vert.back() = false;
        for (size_t x = 0; x < k - 1; ++x) {
            vert[vert_idx] = (y >= k ? dp(y - k, x).up : true) && (y == n - 1 ? true : dp(y + 1, x).down);
            vert_count += vert[vert_idx];
            ++vert_idx;
        }

        for (size_t x = 0; x <= n - k; ++x) {
            if (vert[vert_idx]) {
                --vert_count;
            }
            vert[vert_idx] = (y >= k ? dp(y - k, x + k - 1).up : true) && (y == n - 1 ? true : dp(y + 1, x + k - 1).down);
            vert_count += vert[vert_idx];
            vert_idx = (vert_idx + 1) % k;

            if (cur[x]) {
                --sum[x];
            }
            cur[x] = (x == 0 ? true : dp(y, x - 1).left) && (x + k < n ? dp(y, x + k).right : true);
            sum[x] += cur[x];
            auto full_left = (x == 0 ? 0 : full_vert[x - 1]);
            auto full_right = full_vert.back() - full_vert[x + k - 1];
            auto full_above = (y < k ? 0 : full_hor[y - k]);
            auto full_below = full_hor.back() - full_hor[y];
//            cerr << '(' << y << ',' << x << "): " << sum[x] << ' ' << vert_count <<  ' ' << full_left << ' ' << full_right << ' ' << full_above << ' ' << full_below << '\n';
            best = max(best, sum[x] + vert_count + full_left + full_right + full_above + full_below);
        }

        cur_idx = (cur_idx + 1) % k;
    }

    cout << best << '\n';

    return 0;
}