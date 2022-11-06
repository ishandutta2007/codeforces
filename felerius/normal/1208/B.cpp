#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

// Contest: Manthan, Codefest 19 (open for everyone, rated, Div. 1 + Div. 2) (https://codeforces.com/contest/1208)
// Problem: B: Uniqueness (https://codeforces.com/contest/1208/problem/B)

using namespace std;

void map_del(map<int, size_t>& m, int i) {
    auto it = m.find(i);
    if (--it->second == 0) {
        m.erase(it);
    }
}

int main() {
    ios::sync_with_stdio(false);

    size_t n; cin >> n;
    vector<int> a(n);
    for (auto& ai : a) cin >> ai;

    map<int, size_t> m;
    for (auto ai : a) {
        m[ai]++;
    }

    if (m.size() == n) {
        cout << "0\n";
        return 0;
    }

    size_t best = n;
    for (size_t l = 0; l < n; ++l) {
        auto m2 = m;
        map_del(m2, a[l]);
        size_t r = l + 1;
        while (r < n && m2.size() < n - (r - l)) {
            map_del(m2, a[r++]);
        }

        if (m2.size() == n - (r - l)) {
            best = min(best, r - l);
        }
    }

    cout << best << '\n';

    return 0;
}