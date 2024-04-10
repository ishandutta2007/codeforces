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

template <class T>
auto ceil_div(T a, T b) {
    return (a + b - 1) / b;
}

int main() {
    ios_base::sync_with_stdio(false);

    size_t n;
    uint32_t x, y;
    cin >> n >> x >> y;

    if (x > y) {
        cout << n << '\n';
        return 0;
    }

    vector<uint32_t> doors(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> doors[i];
    }

    int broken = 0;
    while (true) {
        bool found = false;
        for (auto& d : doors) {
            if (d > 0 && d <= x) {
                ++broken;
                d = 0;
                found = true;
                break;
            }
        }

        if (!found) {
            break;
        }

        size_t best_i = 0;
        uint32_t best_steps = numeric_limits<uint32_t>::max();
        for (size_t i = 0; i < n; ++i) {
            auto d = doors[i];
            if (d > 0 && d <= x) {
                auto steps = ceil_div(x - d, y);
                if (steps < best_steps) {
                    best_i = i;
                    best_steps = steps;
                }
            }
        }

        if (best_steps != numeric_limits<uint32_t>::max()) {
            doors[best_i] += y;
        }
    }

    cout << broken << '\n';

    return 0;
}