#include <algorithm>
#include <array>
#include <cassert>
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
    int64_t a, cf, cm, m;
    cin >> n >> a >> cf >> cm >> m;

    vector<pair<int64_t, size_t>> s(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> s[i].first;
        s[i].second = i;
    }

    sort(begin(s), end(s));
    vector<int64_t> slevel(n);
    slevel[0] = 0;
    for (size_t i = 1; i < n; ++i) {
        slevel[i] = slevel[i - 1] + (int64_t)i * (s[i].first - s[i - 1].first);
    }

    auto get_min_skill = [&](auto coins, auto not_maxed) {
        if (not_maxed == 0) {
            return a;
        }
        auto it = upper_bound(begin(slevel), begin(slevel) + not_maxed, coins);
        assert(it != begin(slevel));
        auto num_leveled = it - begin(slevel);
        --it;
        auto coins_rem = coins - *it;
        return min(a, s[num_leveled - 1].first + (coins_rem) / num_leveled);
    };

    int64_t max_cost = 0;

    auto best_min_level = get_min_skill(m, n);
    int64_t best_rating = best_min_level * cm;
    size_t best_maxed_start = n;

    for (int i = n - 1; i >= 0; --i) {
        max_cost += a - s[i].first;
        if (max_cost > m) {
            break;
        }

        auto min_skill = get_min_skill(m - max_cost, i);
        auto rating = (n - i) * cf + min_skill * cm;
        if (rating > best_rating) {
            best_rating = rating;
            best_maxed_start = i;
            best_min_level = min_skill;
        }
    }

    vector<int64_t> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[s[i].second] = i >= best_maxed_start ? a : (s[i].first < best_min_level ? best_min_level : s[i].first);
    }

    cout << best_rating << '\n';
    for (size_t i = 0; i < n; ++i) {
        cout << result[i] << ' ';
    }

    cout << '\n';

    return 0;
}