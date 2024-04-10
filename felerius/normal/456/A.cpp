#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (11) Caisa and Sugar (Difficulty: 3) (http://codeforces.com/problemset/problem/463/A)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    map<int, int> m;
    for (size_t i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        m[a] = max(m[a], b);
    }

    int ma = -1;
    for (auto [_, b] : m) {
        if (b < ma) {
            cout << "Happy Alex\n";
            return 0;
        }

        ma = max(ma, b);
    }

    cout << "Poor Alex\n";

    return 0;
}