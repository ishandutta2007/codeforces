#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

void row(set<pair<uint32_t, uint32_t>>& out, uint32_t x1, uint32_t x2, uint32_t y) {
    if (x1 > x2) {
        swap(x1, x2);
    }

    for (auto x = x1; x <= x2; ++x) {
        out.emplace(pair(x, y));
    }
}

void col(set<pair<uint32_t, uint32_t>>& out, uint32_t y1, uint32_t y2, uint32_t x) {
    if (y1 > y2) {
        swap(y1, y2);
    }

    for (auto y = y1; y <= y2; ++y) {
        out.emplace(pair(x, y));
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    uint32_t x[3];
    uint32_t y[3];

    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

    size_t idxs[] = {0, 1, 2};
    sort(begin(idxs), end(idxs), [&](auto i1, auto i2) { return x[i1] < x[i2]; });

    auto ax = x[idxs[0]];
    auto ay = y[idxs[0]];
    auto bx = x[idxs[1]];
    auto by = y[idxs[1]];
    auto cx = x[idxs[2]];
    auto cy = y[idxs[2]];

    set<pair<uint32_t, uint32_t>> var[8];

    row(var[0], ax, bx, ay);
    col(var[0], ay, by, bx);

    col(var[4], ay, by, bx);
    row(var[4], ax, bx, by);

    var[3] = var[2] = var[1] = var[0];
    var[7] = var[6] = var[5] = var[4];

    for (auto i : {0, 1}) {
        row(var[4 * i + 0], ax, cx, cy);
        col(var[4 * i + 0], ay, cy, cx);

        col(var[4 * i + 1], ay, cy, ax);
        row(var[4 * i + 1], ax, cx, cy);

        row(var[4 * i + 2], bx, cx, cy);
        col(var[4 * i + 2], by, cy, cx);

        col(var[4 * i + 3], by, cy, bx);
        row(var[4 * i + 3], bx, cx, cy);
    }


    auto min_plots = *min_element(begin(var), end(var), [](const auto& a, const auto& b) {
        return a.size() < b.size();
    });

    cout << min_plots.size() << '\n';
    for (auto [x, y] : min_plots) {
        cout << x << ' ' << y << '\n';
    }

    return 0;
}