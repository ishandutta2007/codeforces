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

struct Castle {
    uint32_t x_min;
    uint32_t x_max;
    uint32_t y_min;
    uint32_t y_max;
};

using evtvec = vector<tuple<uint32_t, bool, size_t>>;

bool divide_and_conquer(evtvec& ex, evtvec& ey, size_t ex_beg, size_t ex_end, size_t ey_beg, size_t ey_end, const vector<Castle>& cast) {
    if (ex_end - ex_beg < 3) {
        return true;
    }

    uint32_t count = 0;
    for (size_t i = ex_beg; i < ex_end - 1; ++i) {
        auto [x, start, idx] = ex[i];
        if (!start) {
            count--;
        } else {
            count++;
        }

        if (count == 0) {
            auto it = stable_partition(ey.begin() + ey_beg, ey.begin() + ey_end, [&, x=x](auto& e) {
                return cast[get<2>(e)].x_max <= x;
            });
            auto b1 = divide_and_conquer(ex, ey, ex_beg, i + 1, ey_beg, it - ey.begin(), cast);
            auto b2 = divide_and_conquer(ex, ey, i + 1, ex_end, it - ey.begin(), ey_end, cast);
            return b1 && b2;
        }
    }

    count = 0;
    for (size_t i = ey_beg; i < ey_end - 1; ++i) {
        auto [y, start, idx] = ey[i];
        if (!start) {
            count--;
        } else {
            count++;
        }

        if (count == 0) {
            auto it = stable_partition(ex.begin() + ex_beg, ex.begin() + ex_end, [&, y=y](auto& e) {
                return cast[get<2>(e)].y_max <= y;
            });
            auto b1 = divide_and_conquer(ex, ey, ex_beg, it - ex.begin(), ey_beg, i + 1, cast);
            auto b2 = divide_and_conquer(ex, ey, it - ex.begin(), ex_end, i + 1, ey_end, cast);
            return b1 && b2;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<Castle> cast(n);
    evtvec ex;
    evtvec ey;
    ex.reserve(2 * n);
    ey.reserve(2 * n);
    for (size_t i = 0; i < n; ++i) {
        cin >> cast[i].x_min >> cast[i].y_min >> cast[i].x_max >> cast[i].y_max;
        ex.emplace_back(cast[i].x_min, true, i);
        ex.emplace_back(cast[i].x_max, false, i);
        ey.emplace_back(cast[i].y_min, true, i);
        ey.emplace_back(cast[i].y_max, false, i);
    }

    sort(begin(ex), end(ex));
    sort(begin(ey), end(ey));

    auto b = divide_and_conquer(ex, ey, 0, ex.size(), 0, ey.size(), cast);
    if (b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}