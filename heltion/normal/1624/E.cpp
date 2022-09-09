#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        map<string, tuple<int, int, int>> mp;
        for (int i = 0; i < n; i += 1) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j += 1) {
                if (j + 2 <= m) mp[s.substr(j, 2)] = {j + 1, j + 2, i + 1};
                if (j + 3 <= m) mp[s.substr(j, 3)] = {j + 1, j + 3, i + 1};
            }
        }
        string s;
        cin >> s;
        vector<int> dp(m + 1);
        dp[0] = 1;
        for (int i = 0; i < m; i += 1) if (dp[i]) {
            if (mp.contains(s.substr(i, 2))) dp[i + 2] = 1;
            if (i + 3 <= m and mp.contains(s.substr(i, 3))) dp[i + 3] = 1;
        }
        if (not dp.back()) cout << "-1\n";
        else {
            int p = m;
            vector<tuple<int, int, int>> vt;
            while (p) {
                if (dp[p - 2] and mp.contains(s.substr(p - 2, 2))) {
                    p -= 2;
                    vt.push_back(mp[s.substr(p, 2)]);
                }
                else {
                    p -= 3;
                    vt.push_back(mp[s.substr(p, 3)]);
                }
            }
            ranges::reverse(vt);
            cout << vt.size() << "\n";
            for (auto [l, r, i] : vt) cout << l << " " << r << " " << i << "\n";
        }
    }
}