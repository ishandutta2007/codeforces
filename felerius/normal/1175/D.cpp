#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

// Contest: Educational Codeforces Round 66 (Rated for Div. 2) (https://codeforces.com/contest/1175)
// Problem: D: Array Splitting (https://codeforces.com/contest/1175/problem/D)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;

    vector<int64_t> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<int64_t> sufsum(n);
    partial_sum(rbegin(a), rend(a), rbegin(sufsum));

    int64_t total_sum = sufsum[0];
    if (k > 1) {
        auto it = end(sufsum) - (k - 1);
//        nth_element(begin(sufsum) + 1, it, end(sufsum));
        sort(begin(sufsum) + 1, end(sufsum));
        total_sum += accumulate(it, end(sufsum), (int64_t)0);
    }

    cout << total_sum << '\n';

    return 0;
}