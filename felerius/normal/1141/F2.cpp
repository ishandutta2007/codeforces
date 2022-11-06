#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<int> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, vector<pair<size_t, size_t>>> dp;
    for (size_t i = 0; i < n; ++i) {
        int sum = 0;
        for (size_t l = 0; l <= i; ++l) {
            sum += a[i - l];
            auto [it, _] = dp.try_emplace(sum);
            auto& vec = it->second;
            if (vec.empty() || vec.back().second < i - l) {
                vec.emplace_back(i - l, i);
            }
        }
    }

    auto it = max_element(dp.begin(), dp.end(), [](const auto& p1, const auto& p2) {
        return p1.second.size() < p2.second.size();
    });

    cout << it->second.size() << '\n';
    for (auto [l, r] : it->second) {
        cout << (l + 1) << ' ' << (r + 1) << '\n';
    }

    return 0;
}