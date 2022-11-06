#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (28) Maximum Value (Difficulty: 5) (http://codeforces.com/problemset/problem/484/B)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n);
    for (auto& ai : a) cin >> ai;
    sort(begin(a), end(a));

    int max_val = a.back();
    vector<int> s(2 * max_val + 1);
    {
        int j = 0;
        for (int i = a[0]; i < s.size(); ++i) {
            s[i] = a[j];
            while (j + 1 < n && i == a[j + 1])
                ++j;
        }
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && a[i] == a[i - 1])
            continue;
        for (int j = 2 * a[i]; j <= 2 * max_val; j += a[i]) {
            if (s[j] >= a[i])
                mx = max(mx, s[j] % a[i]);
        }
    }

    cout << mx << '\n';

    return 0;
}