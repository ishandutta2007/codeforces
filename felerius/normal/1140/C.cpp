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
    std::ios_base::sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;

    vector<pair<uint32_t, uint32_t>> songs(n);
    for (size_t i = 0; i < n; ++i) {
        uint32_t t, b;
        cin >> t >> b;
        songs[i] = {t, b};
    }

    sort(songs.begin(), songs.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    multiset<uint32_t> s;
    uint64_t set_sum = 0;
    uint64_t max_pl = 0;
    for (auto [t, b] : songs) {
        max_pl = max(max_pl, (set_sum + t) * b);
        s.insert(t);
        set_sum += t;
        if (s.size() > k - 1) {
            auto it = s.begin();
            set_sum -= *it;
            s.erase(it);
        }
    }

    cout << max_pl << '\n';

    return 0;
}