#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <random>
#include <ctime>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> c(n);
    vector<vector<int>> a(n);
    vector<pair<int, int>> d;
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        c[i] = {0, m - 1};
        // cout << m << '\n';
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            d.emplace_back(a[i][j], i);
        }
        sort(all(a[i]));
    }
    sort(all(d));
    vector<vector<int>> ans(n);
    for (int i = 0; i < m; ++i) {
        int z = d[i].second;
        for (int j = 0; j < n; ++j) {
            // cout << z << ' ' << j << ' ' << c[j].first << ' ' << c[j].second << '\n';
            // cout << a[j].size() << '\n';
            if (j == z) {
                ans[j].push_back(a[j][c[j].first++]);
            } else {
                ans[j].push_back(a[j][c[j].second--]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j : ans[i])
            cout << j << ' ';
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}