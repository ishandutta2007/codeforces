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

// Contest: Codeforces Round #581 (Div. 2) (https://codeforces.com/contest/1204)
// Problem: D2: Kirk and a Binary String (hard version) (https://codeforces.com/contest/1204/problem/D2)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    auto n = s.size();

    vector<int> pref_ones(n);
    pref_ones[0] = s[0] == '1' ? 1 : -1;
    for (size_t i = 1; i < n; ++i) {
        pref_ones[i] = pref_ones[i - 1] + (s[i] == '1' ? 1 : -1);
    }

    vector<int> suf_zero(n);
    suf_zero.back() = s.back() == '0' ? 1 : -1;
    for (int i = n - 2; i >= 0; --i) {
        suf_zero[i] = suf_zero[i + 1] + (s[i] == '0' ? 1 : -1);
    }

    multiset<int> one_counts(begin(pref_ones), end(pref_ones));
    multiset<int> zero_counts;
    int flipped = 0;

    for (size_t i = 0; i < n; ++i) {
        one_counts.erase(one_counts.find(pref_ones[i]));

        auto min_zeroes_bef = (zero_counts.empty() ? 0 : *zero_counts.begin()) + flipped - suf_zero[i];
        auto min_ones_after = (one_counts.empty() ? 0 : *one_counts.begin()  - pref_ones[i]);
        if (s[i] == '1' && min_zeroes_bef >= 0 && min_ones_after >= 0) {
            s[i] = '0';
            flipped++;
        }

        zero_counts.emplace(suf_zero[i]);
    }

    cout << s << '\n';

    return 0;
}