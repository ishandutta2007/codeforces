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

// Contest: Codeforces Global Round 4 (https://codeforces.com/contest/1178)
// Problem: E: Archaeology (https://codeforces.com/contest/1178/problem/E)

using namespace std;

string pal(const string& s, int mid) {
    auto n = s.size();
    string p = {s[mid]};

    int l = mid - 1;
    int r = mid + 1;
    while (l >= 0 && r < n) {
        auto b1 = l > 0;
        auto b2 = r < n - 1;
        if (s[l] == s[r]) {
            p.push_back(s[l]);
            --l; ++r;
            continue;
        }
        if (b1 && s[l - 1] == s[r]) {
            p.push_back(s[r]);
            ----l; ++r;
            continue;
        }
        if (b2 && s[l] == s[r + 1]) {
            p.push_back(s[l]);
            --l; ++++r;
            continue;
        }
        if (b1 && b2 && s[l - 1] == s[r + 1]) {
            p.push_back(s[l - 1]);
            ----l; ++++r;
            continue;
        }

//        assert(!b1 && !b2);
        break;
    }

    return p;
}

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    auto p1 = pal(s, s.size() / 2);
    auto p2 = pal(s, (s.size() - 1) / 2);
    auto& p = p1.size() > p2.size() ? p1 : p2;

    for (size_t i = p.size() - 1; i > 0; --i) {
        cout << p[i];
    }

    cout << p << '\n';

    return 0;
}