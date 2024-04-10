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
// Problem: D1: Kirk and a Binary String (easy version) (https://codeforces.com/contest/1204/problem/D1)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    auto n = s.size();

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0') {
            continue;
        }

        auto pos = true;
        int su = 0;
        for (int j = i - 1; j >= 0; --j) {
            su += s[j] == '0' ? 1 : -1;
            pos &= su >= 0;
        }
        su = 0;
        for (size_t j = i + 1; j < n; ++j) {
            su += s[j] == '1' ? 1 : -1;
            pos &= su >= 0;
        }

        if (pos) {
            s[i] = '0';
        }
    }

    cout << s;

    return 0;
}