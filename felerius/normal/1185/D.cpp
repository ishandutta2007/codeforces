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

// Contest: Codeforces Round #568 (Div. 2) (https://codeforces.com/contest/1185)
// Problem: D: Extra Element (https://codeforces.com/contest/1185/problem/D)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<pair<int, size_t>> b(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(begin(b), end(b));
    map<int, size_t> counts;
    for (size_t i = 1; i < n; ++i) {
        counts[b[i].first - b[i - 1].first]++;
    }

    for (size_t i = 0; i < n; ++i) {
        if (i == 0 || i == n - 1) {
            auto diff = i == 0 ? b[1].first - b[0].first : b[n - 1].first - b[n - 2].first;
            auto it = counts.find(diff);
            if (--it->second == 0) {
                counts.erase(it);
            }

            if (counts.size() <= 1) {
                cout << (b[i].second + 1) << '\n';
                return 0;
            }

            counts[diff]++;
            continue;
        }

        auto prev = b[i].first - b[i - 1].first;
        auto next = b[i + 1].first - b[i].first;
        auto it1 = counts.find(prev);
        auto it2 = counts.find(next);
        if (--it1->second == 0) {
            counts.erase(it1);
        }
        if (--it2->second == 0) {
            counts.erase(it2);
        }

        counts[prev + next]++;
        if (counts.size() <= 1) {
            cout << (b[i].second + 1) << '\n';
            return 0;
        }

        auto it3 = counts.find(prev + next);
        if (--it3->second == 0) {
            counts.erase(it3);
        }

        counts[prev]++;
        counts[next]++;
    }

    cout << "-1\n";

    return 0;
}