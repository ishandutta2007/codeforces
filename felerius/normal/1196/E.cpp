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
    ios::sync_with_stdio(false);

    size_t q;
    cin >> q;
    while (q--) {
        size_t b, w;
        cin >> b >> w;
        if (b > 3 * w + 1 || w > 3 * b + 1) {
            cout << "NO\n";
            continue;
        }

        auto [x, y] = std::minmax(b, w);
        vector<pair<size_t, size_t>> pos;
        pos.reserve(b + w);
        for (size_t i = 0; i < x; ++i) {
            pos.emplace_back(2, 2 * i + 1);
            pos.emplace_back(2, 2 * i + 2);
        }

        auto rem = y - x;
        if (rem > 0) {
            pos.emplace_back(2, 2 * x + 1);
            --rem;
        }

        for (size_t i = 0; i < rem; ++i) {
            pos.emplace_back(i % 2 == 0 ? 3 : 1, 2 + 2 * (i / 2));
        }

        cout << "YES\n";
        for (auto [c, d] : pos) {
            d += w > b;
            cout << c << ' ' << d << '\n';
        }
    }

    return 0;
}