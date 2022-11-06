#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <optional>
#include <set>
#include <string>
#include <tuple>
#include <vector>

// Contest: Codeforces Round #570 (Div. 3) (https://codeforces.com/contest/1183)
// Problem: G: Candy Box (hard version) (https://codeforces.com/contest/1183/problem/G)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t q;
    cin >> q;

    while (q--) {
        size_t n;
        cin >> n;
        vector<pair<size_t, size_t>> c(n);
        for (size_t i = 0; i < n; ++i) {
            size_t ai, fi;
            cin >> ai >> fi;
            c[ai - 1].first++;
            c[ai - 1].second += fi;
        }

        sort(begin(c), end(c), greater<>{});
        vector<size_t> sizes;
        size_t s = 0;
        size_t ma = numeric_limits<size_t>::max();
        for (auto [co, _] : c) {
            if (ma == 0 || co == 0) {
                break;
            }

            auto a = min(ma, co);
            sizes.emplace_back(a);
            s += a;
            ma = a - 1;
        }

        size_t f = 0;
        auto it = begin(c);
        multiset<size_t> avail;
        for (auto si : sizes) {
            while (it != end(c) && it->first >= si) {
                avail.emplace(it->second);
                ++it;
            }

            f += min(si, *prev(end(avail)));
            avail.erase(prev(end(avail)));
        }

        cout << s << ' ' << f << '\n';
    }

    return 0;
}