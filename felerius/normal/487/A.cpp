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

// Contest: 21 - Codeforces Rating >= 2200 (https://a2oj.com/ladder?ID=21)
// Problem: (13) Fight the Monster (Difficulty: 4) (http://codeforces.com/problemset/problem/487/A)

using namespace std;

int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    ios::sync_with_stdio(false);

    int hp_y, atk_y, def_y;
    int hp_m, atk_m, def_m;
    int h, a, d;
    cin >> hp_y >> atk_y >> def_y;
    cin >> hp_m >> atk_m >> def_m;
    cin >> h >> a >> d;

    int cost = 0;
    if (atk_y <= def_m) {
        cost += (def_m + 1 - atk_y) * a;
        atk_y = def_m + 1;
    }

    int min_add_cost = max(0, atk_m - def_y) * d;
    for (int i = 0; i < hp_m; ++i) {
        for (int j = 0; j < max(0, atk_m - def_y); ++j) {
            int rounds_y_base = ceil_div(hp_y, atk_m - def_y - j);
            for (int k = 0; k <= 100; ++k) {
                auto rounds_m = ceil_div(hp_m, atk_y + i - def_m);
                if (rounds_m < rounds_y_base + k) {
                    auto total_hp = max(hp_y, (rounds_y_base + k - 1) * (atk_m - def_y - j) + 1);
                    auto hp_cost = (total_hp - hp_y) * h;
                    min_add_cost = min(min_add_cost, i * a + j * d + hp_cost);
                }
            }
        }
    }

    cout << (cost + min_add_cost) << '\n';

    return 0;
}