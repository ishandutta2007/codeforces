#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <set>
#include <string>
#include <tuple>
#include <vector>

// Contest: Codeforces Round #584 - Dasha Code Championship - Elimination Round (rated, open for everyone, Div. 1 + Div. 2) (https://codeforces.com/contest/1209)
// Problem: C: Paint the Digits (https://codeforces.com/contest/1209/problem/C)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> pref_max(n);
        pref_max[0] = s[0] - '0';
        for (int i = 1; i < n; ++i) {
            pref_max[i] = max(pref_max[i - 1], s[i] - '0');
        }

        vector<int> suff_min(n);
        suff_min[n - 1] = s[n - 1] - '0';
        for (int i = n - 2; i >= 0; --i) {
            suff_min[i] = min(suff_min[i + 1], s[i] - '0');
        }

        array<vector<int>, 10> pos_list;
        array<int, 10> pos_last; pos_last.fill(-1);
        array<int, 10> pos_first; pos_first.fill(n);
        for (int i = 0; i < n; ++i) {
            pos_list[s[i] - '0'].push_back(i);
            pos_last[s[i] - '0'] = i;
            if (pos_first[s[i] - '0'] == n)
                pos_first[s[i] - '0'] = i;
        }

        bool done = false;
        for (int i = 0; !done && i < 10; ++i) {
            bool poss = true;
            for (int j = 0; j < i - 1; ++j)
                for (int k = j + 1; k < i; ++k)
                    poss &= pos_last[j] < pos_first[k];
            for (int j = i + 1; j < 9; ++j)
                for (int k = j + 1; k <= 9; ++k)
                    poss &= pos_last[j] < pos_first[k];

            if (!poss)
                continue;

            int first_front_act = -1;
            for (int j = 0; j <= pos_list[i].size(); ++j) {
                auto first_front = j < pos_list[i].size() ? pos_list[i][j] : n;
                auto last_back = j == 0 ? -1 : pos_list[i][j - 1];
                bool poss2 = true;
                for (int k = 0; k < i; ++k)
                    poss2 &= first_front > pos_last[k];
                for (int k = i + 1; k < 10; ++k)
                    poss2 &= last_back < pos_first[k];
                if (poss2) {
                    first_front_act = first_front;
                    break;
                }
            }

            if (first_front_act == -1)
                break;

            for (int j = 0; j < n; ++j) {
                auto d = s[j] - '0';
                if (d < i)
                    cout << '1';
                else if (d > i)
                    cout << '2';
                else
                    cout << (j >= first_front_act ? '1' : '2');
            }
            cout << '\n';
            done = true;
        }

        if (!done)
            cout << "-\n";
    }

    return 0;
}