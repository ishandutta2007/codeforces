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

int main() {
    ios::sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;

    vector<int> books(n);
    vector<vector<int>> occ(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> books[i];
    }

    for (auto it = rbegin(books); it != rend(books); ++it) {
        occ[*it - 1].emplace_back(n - 1 - (it - rbegin(books)));
    }

    int bought = 0;
    set<pair<int, int>> inv;

    for (size_t i = 0; i < n; ++i) {
        auto b = books[i];
        occ[b - 1].pop_back();
        auto it = inv.find(pair(i, b));
        if (it != end(inv)) {
            inv.erase(it);
            if (!occ[b - 1].empty()) {
                inv.emplace(occ[b - 1].back(), b);
            }

            continue;
        }

        ++bought;
        if (inv.size() == k) {
            inv.erase(prev(end(inv)));
        }

        if (!occ[b - 1].empty()) {
            inv.emplace(occ[b - 1].back(), b);
        }
    }

    cout << bought << '\n';

    return 0;
}