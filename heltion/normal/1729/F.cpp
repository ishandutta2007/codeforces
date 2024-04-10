#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        int w, m;
        cin >> s >> w >> m;
        int n = s.size();
        vector<int> a(n + 1);
        for (int i = 0; i < n; i += 1)
            a[i + 1] = (a[i] + s[i] - '0') % 9;
        vector<vector<int>> v(9);
        for (int i = 1; i + w - 1 <= n; i += 1)
            v[(a[i + w - 1] + 9 - a[i - 1]) % 9].push_back(i);
        for (int i = 0; i < m; i += 1) {
            int l, r, k;
            cin >> l >> r >> k;
            pair<int, int> p = {-1, -1};
            int w = (a[r] + 9 - a[l - 1]) % 9;
            for (int i = 0; i < 9; i += 1)
                for (int j = 0; j < 9; j += 1)
                    if ((i * w + j) % 9 == k) {
                        if (i == j) {
                            if (v[i].size() >= 2) {
                                if (p.first == -1 or p > make_pair(v[i][0], v[i][1]))
                                    p = {v[i][0], v[i][1]};
                            }
                        }
                        else if (v[i].size() and v[j].size()) {
                            if (p.first == -1 or p > make_pair(v[i][0], v[j][0]))
                                p = {v[i][0], v[j][0]};
                        }
                    }
            cout << p.first << " " << p.second << "\n";
        }
    }
}