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

// Contest: Codeforces Round #570 (Div. 3) (https://codeforces.com/contest/1183)
// Problem: F: Topforces Strikes Back (https://codeforces.com/contest/1183/problem/F)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t q;
    cin >> q;

    while (q--) {
        size_t n;
        cin >> n;
        vector<uint32_t> a(n);
        for (auto& ai : a) {
            cin >> ai;
        }

        sort(begin(a), end(a));
        auto last = unique(begin(a), end(a));
        a.erase(last, end(a));

        n = a.size();
        uint32_t best = *max_element(begin(a), end(a));
        if (n <= 100) {
            for (size_t i = 0; i < n; ++i) {
                for (size_t j = i + 1; j < n; ++j) {
                    if (a[j] % a[i] == 0) {
                        continue;
                    }

                    best = max(best, a[i] + a[j]);
                    for (size_t k = j + 1; k < n; ++k) {
                        if (a[k] % a[i] != 0 && a[k] % a[j] != 0) {
                            best = max(best, a[i] + a[j] + a[k]);
                        }
                    }
                }
            }
        } else {
            for (size_t i = 0; i < 5; ++i) {
                auto ai = a[n - i - 1];
                int c = 0;
                for (size_t j = i + 1; j < n && c < 5; ++j) {
                    auto aj = a[n - j - 1];
                    if (ai % aj == 0) {
                        continue;
                    }

                    c++;
                    best = max(best, a[i] + a[j]);
                    for (size_t k = 0; k < n - j; ++k) {
                        if (ai % a[k] != 0 && aj % a[k] != 0) {
                            best = max(best, ai + aj + a[k]);
                        }
                    }
                }
            }
        }

        cout << best << '\n';
    }

    return 0;
}