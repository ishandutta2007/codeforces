#include <bits/stdc++.h>

// Contest: Codeforces Round #592 (Div. 2) (https://codeforces.com/contest/1244)
// Problem: F: Chips (https://codeforces.com/contest/1244/problem/F)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<bool> c(n); char ch;
    for (int i = 0; i < n; ++i)
        cin >> ch, c[i] = ch == 'W';

    if (n % 2 == 0) {
        bool alt = true;
        for (int i = 0; i < n; ++i)
            alt &= c[i] != c[(i + 1) % n];
        if (alt) {
            auto inv = k % 2 == 1;
            for (int i = 0; i < n; ++i)
                cout << (c[i] ^ inv ? 'W' : 'B');
            cout << '\n';
            return 0;
        }
    }

    bool uni = true;
    for (int i = 0; i < n; ++i)
        uni &= c[i] == c[(i + 1) % n];
    if (uni) {
        for (int i = 0; i < n; ++i)
            cout << (c[i] ? 'W' : 'B');
        cout << '\n';
        return 0;
    }

    vector<pair<pair<int, int>, bool>> uni_ranges;
    int start = 0;
    while (c[start] == c[0])
        ++start;
    uni_ranges.emplace_back(pair(start, start), c[start]);
    for (int i = 1; i < n; ++i) {
        int j = (start + i) % n;
        if (c[j] == c[uni_ranges.back().first.first]) {
            uni_ranges.back().first.second = j;
        } else {
            if (uni_ranges.back().first.first == uni_ranges.back().first.second)
                uni_ranges.pop_back();
            uni_ranges.emplace_back(pair(j, j), c[j]);
        }
    }
    if (uni_ranges.back().first.first == uni_ranges.back().first.second)
        uni_ranges.pop_back();

    for (int i = 0; i < uni_ranges.size(); ++i) {
        auto& [s1, e1] = uni_ranges[i].first;
        auto& [s2, e2] = uni_ranges[(i + 1) % uni_ranges.size()].first;
        int diff = (s2 + n - e1) % n - 1;
        e1 += min(diff / 2, k);
        s2 -= min((diff + 1) / 2, k);
        s2 = (s2 + n) % n;
    }

    vector<bool> res(n);
    for (int i = 0; i < uni_ranges.size(); ++i) {
        auto& [s, e] = uni_ranges[i].first;
        auto col = uni_ranges[i].second;
        int len = (e + n - s) % n + 1;
        for (int j = 0; j < len; ++j)
            res[(s + j) % n] = col;
        auto& snext = uni_ranges[(i + 1) % uni_ranges.size()].first.first;
        for (int j = (e + 1) % n; j != snext; j = (j + 1) % n) {
            col = !col;
            res[j] = col;
        }
    }

    for (auto col : res)
        cout << (col ? 'W' : 'B');
    cout << '\n';
    return 0;
}