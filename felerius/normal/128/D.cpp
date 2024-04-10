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

// Contest: 21 - Codeforces Rating >= 2200 (https://a2oj.com/ladder?ID=21)
// Problem: (19) Numbers (Difficulty: 5) (http://codeforces.com/problemset/problem/128/D)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    sort(begin(a), end(a));
    vector<pair<int, size_t>> b;

    int cur = a[0];
    size_t cur_count = 1;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] == cur) {
            ++cur_count;
        } else {
            b.emplace_back(cur, cur_count);
            cur = a[i];
            cur_count = 1;
        }
    }

    b.emplace_back(cur, cur_count);

    auto n2 = b.size();
    b[0].second--;
    for (size_t i = 1; i < n2; ++i) {
        if (b[i].first != b[i - 1].first + 1) {
            cout << "NO\n"; return 0;
        }

        if (i < n2 - 1) {
            if (b[i].second < 2) {
                cout << "NO\n"; return 0;
            }
        }

        b[i].second -= i == n2 - 1 ? 1 : 2;
    }

    size_t par = 0;
    for (auto [_, count] : b) {
        if (count < par) {
            cout << "NO\n"; return 0;
        } else if (count <= 2 * par) {
            par -= 2 * par - count;
        } else {
            par += count - 2 * par;
        }
    }

    cout << (par == 0 ? "YES\n" : "NO\n");

    return 0;
}