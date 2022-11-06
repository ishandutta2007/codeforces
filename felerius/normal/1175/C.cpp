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
    std::ios_base::sync_with_stdio(false);

    size_t t;
    cin >> t;

    vector<uint64_t> a;
    for (size_t j = 0; j < t; ++j) {
        size_t n, k;
        cin >> n >> k;
        a.resize(n);
        for (size_t i = 0; i < n; ++i) {
            cin >> a[i];
        }

        uint64_t best = 0;
        uint64_t best_dist = numeric_limits<uint64_t>::max();
        for (size_t i = 0; i + k < n; ++i) {
            auto min = a[i];
            auto max = a[i + k];
            auto mid = (min + max) / 2;
            auto dist = std::max(mid - min, max - mid);
            if (dist < best_dist) {
                best = mid;
                best_dist = dist;
            }
        }

        cout << best << '\n';
    }

    return 0;
}