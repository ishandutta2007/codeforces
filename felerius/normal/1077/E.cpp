#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <map>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <unordered_map>
#include <vector>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    map<uint32_t, uint32_t> mapped_counts;
    for (size_t i = 0; i < n; ++i) {
        uint32_t topic;
        cin >> topic;
        mapped_counts[topic]++;
    }

    vector<uint32_t> counts;
    counts.reserve(mapped_counts.size());
    for (auto& [_, c] : mapped_counts) {
        counts.emplace_back(c);
    }

    sort(counts.begin(), counts.end(), greater<>());

    uint32_t best = 0;
    auto max_l = min((size_t)20, counts.size());
    for (uint32_t l = 1; l <= max_l; ++l) {
        uint32_t div = 2;
        uint32_t min_base = counts[l - 1];
        for (size_t i = 1; i < l; ++i) {
            min_base = min(min_base, counts[l - i - 1] / div);
            div *= 2;
        }

        uint32_t val = 0;
        for (size_t i = 0; i < l; ++i) {
            val += min_base;
            min_base *= 2;
        }

        best = max(best, val);
    }

    cout << best << '\n';

    return 0;
}