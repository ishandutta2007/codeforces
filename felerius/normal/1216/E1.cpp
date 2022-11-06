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

// Contest: Codeforces Round #587 (Div. 3) (https://codeforces.com/contest/1216)
// Problem: E1: Numerical Sequence (easy version) (https://codeforces.com/contest/1216/problem/E1)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<uint64_t> lens = {1};
    vector<uint64_t> ends = {1};
    uint64_t digits = 1;
    uint64_t len = 1;
    uint64_t next = 10;
    while (ends.back() < 1e9) {
        if ((ends.size() + 1) % next == 0) {
            next *= 10;
            ++digits;
        }

        len += digits;
        lens.emplace_back(len);
        ends.emplace_back(ends.back() + len);
    }

    size_t q; cin >> q;
    while (q--) {
        uint64_t k; cin >> k; --k;
        auto it = upper_bound(begin(ends), end(ends), k);
        size_t seq_num = it - begin(ends);
        size_t in_seq = k - (it == begin(ends) ? 0 : *(it - 1));
        auto it2 = upper_bound(begin(lens), end(lens), in_seq);
        auto num = it2 - begin(lens) + 1;
        size_t in_num = in_seq - (it2 == begin(lens) ? 0 : *(it2 - 1));
        auto s = to_string(num);
        cout << s[in_num] << '\n';
    }

    return 0;
}