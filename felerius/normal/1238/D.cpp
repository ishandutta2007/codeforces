#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 74 (Rated for Div. 2) (https://codeforces.com/contest/1238)
// Problem: D: AB-string (https://codeforces.com/contest/1238/problem/D)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;

    array<vector<int>, 2> pos;
    for (int i = 0; i < n; ++i)
        pos[s[i] - 'A'].push_back(i);

    ll res = 0;
    array<decltype(pos[0].begin()), 2> j = {pos[0].begin(), pos[1].begin()};
    array<decltype(pos[0].begin()), 2> e = {pos[0].end(), pos[1].end()};
    for (int i = 0; i < n; ++i) {
        auto c = s[i] - 'A';
        j[c]++;
        if (j[c] != e[c]) {
            res += (n - i) - (*j[c] - *(j[c] - 1));
            if (j[1 - c] != e[1 - c] && *j[1 - c] > *j[c])
                --res;
        }
    }

    cout << res << '\n';

    return 0;
}