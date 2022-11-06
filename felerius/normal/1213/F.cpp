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

// Contest: Codeforces Round #582 (Div. 3) (https://codeforces.com/contest/1213)
// Problem: F: Unstable String Sort (https://codeforces.com/contest/1213/problem/F)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;

    vector<size_t> p(n), q(n);
    for (auto& pi : p) { cin >> pi; --pi; }
    for (auto& qi : q) { cin >> qi; --qi; }

    vector<size_t> ppos(n);
    for (size_t i = 0; i < n; ++i) {
        ppos[p[i]] = i;
    }

    vector<size_t> range_start;
    vector<size_t> range_end;
    for (size_t i = 1; i < n; ++i) {
        if (ppos[q[i]] < ppos[q[i - 1]]) {
            range_start.emplace_back(ppos[q[i]]);
            range_end.emplace_back(ppos[q[i - 1]]);
        }
    }

    sort(begin(range_start), end(range_start));
    sort(begin(range_end), end(range_end));

    auto sit = begin(range_start);
    auto eit = begin(range_end);
    size_t c = 0;
    size_t act = 0;
    string s(n, ' ');
    for (size_t i = 0; i < n; ++i) {
        while (sit != end(range_start) && *sit == i) {
            ++act; ++sit;
        }

        s[p[i]] = 'a' + (char)c;

        while (eit != end(range_end) && *eit == i) {
            --act; ++eit;
        }

        if (i < n - 1 && c < k - 1 && act == 0) {
            ++c;
        }
    }

    if (c == k - 1) {
        cout << "YES\n" << s << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}