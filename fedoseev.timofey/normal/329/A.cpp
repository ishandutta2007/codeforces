#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <vector <int>> a(n, vector <int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == '.') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    bool fl = true;
    vector <pair <int, int>> ans;
    for (int i = 0; i < n; ++i) {
        bool ok = false;
        for (int j = 0; j < n; ++j) {
            if (a[i][j]) {
                ok = true;
                ans.push_back({i + 1, j + 1});
                break;
            }
        }
        if (!ok) {
            fl = false;
            break;
        }
    }
    if (fl) {
        for (auto p : ans) cout << p.first << ' ' << p.second << '\n';
        return 0;
    }
    fl = true;
    ans.clear();
    for (int j = 0; j < n; ++j) {
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (a[i][j]) {
                ok = true;
                ans.push_back({i + 1, j + 1});
                break;
            }
        }
        if (!ok) {
            fl = false;
            break;
        }
    }
    if (fl) {
        for (auto p : ans) cout << p.first << ' ' << p.second << '\n';
        return 0;
    }
    cout << "-1\n";
}