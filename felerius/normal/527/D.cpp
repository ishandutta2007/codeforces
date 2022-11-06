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

    size_t n;
    cin >> n;

    vector<pair<int, int>> p(n);
    for (auto& pi : p) {
        cin >> pi.first >> pi.second;
    }

    sort(begin(p), end(p), [](auto& a, auto& b) {
        return a.first + a.second < b.first + b.second;
    });

    vector<pair<int, int>> r(n);
    int max_count = 0;
    for (size_t i = 0; i < n; ++i) {
        auto it = upper_bound(begin(r), begin(r) + (int)i, pair(p[i].first - p[i].second, (int)n + 1));
        auto count = it == begin(r) ? 1 : (it - 1)->second + 1;
        max_count = max(max_count, count);
        r[i] = {p[i].first + p[i].second, max_count};
    }

    cout << max_count << '\n';

    return 0;
}