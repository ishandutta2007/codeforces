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

// Contest: Codeforces Round #584 - Dasha Code Championship - Elimination Round (rated, open for everyone, Div. 1 + Div. 2) (https://codeforces.com/contest/1209)
// Problem: G1: Into Blocks (easy version) (https://codeforces.com/contest/1209/problem/G1)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai; --ai;
    }

    vector<int> last(200'000);
    vector<int> count(200'000);
    for (int i = 0; i < n; ++i) {
        last[a[i]] = i;
        count[a[i]]++;
    }

    int first_in_block = 0;
    int last_in_block = 0;
    int max_same = 0;
    int difficulty = 0;
    for (int i = 0; i < n; ++i) {
        last_in_block = max(last_in_block, last[a[i]]);
        max_same = max(max_same, count[a[i]]);
        if (last_in_block == i) {
            auto block_len = last_in_block - first_in_block + 1;
            difficulty += block_len - max_same;
            last_in_block = first_in_block = i + 1;
            max_same = 0;
        }
    }

    cout << difficulty << '\n';

    return 0;
}