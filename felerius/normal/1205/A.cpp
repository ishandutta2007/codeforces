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

// Contest: Codeforces Round #580 (Div. 1) (https://codeforces.com/contest/1205)
// Problem: A: Almost Equal (https://codeforces.com/contest/1205/problem/A)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "NO\n";
        return 0;
    }

    array<vector<int>, 2> a;
    size_t i1 = 0;
    size_t i2 = 1;
    for (int i = 0; i < n; ++i) {
        a[i1].emplace_back(2 * i + 1);
        a[i2].emplace_back(2 * i + 2);
        swap(i1, i2);
    }

    cout << "YES\n";
    for (auto ai : a[0]) {
        cout << ai << ' ';
    }
    for (auto ai : a[1]) {
        cout << ai << ' ';
    }
    cout << '\n';

    return 0;
}