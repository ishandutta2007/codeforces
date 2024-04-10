#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

bool check(set<pair<int, int>> a, set<int> a1, set<int> a2) {
    vector<vector<int>> type(a1.size() + 1);
    for (auto i : a) {
        int it = 0;
        for (auto j : a1) {
            if (j == i.first) {
                type[it].push_back(i.second);
                break;
            } else {
                ++it;
            }
        }
        if (it == (int) a1.size()) {
            type[it].push_back(i.second);
        }
    }

    for (auto arr : type) {
        vector<vector<int>> c(a2.size() + 1);
        for (int i : arr) {
            int it = 0;
            for (auto j : a2) {
                if (j == i) {
                    c[it].push_back(i);
                    break;
                } else {
                    ++it;
                }
            }
            if (it == (int) a2.size()) {
                c[it].push_back(i);
            }
        }
        for (auto i : c) {
            if (i.size() > 1) {
                return false;
            }
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    set<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int val = 0;
        if (s[0] == 'G')
            val = 0;
        if (s[0] == 'R')
            val = 1;
        if (s[0] == 'B')
            val = 2;
        if (s[0] == 'Y')
            val = 3;
        if (s[0] == 'W')
            val = 4;
        a.insert({val, s[1] - '1'});
    }


    int ans = 10;

    for (int mask = 0; mask < (1 << 10); ++mask) {
        set<int> a1, a2;
        for (int i = 0; i < 5; ++i) {
            if (mask & (1 << i)) {
                a1.insert(i);
            }
        }
        for (int i = 5; i < 10; ++i) {
            if (mask & (1 << i)) {
                a2.insert(i - 5);
            }
        }
        if (check(a, a1, a2)) {
            ans = min(ans, (int) a1.size() + (int) a2.size());
        }
    }
    cout << ans << '\n';
}