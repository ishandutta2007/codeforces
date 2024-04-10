#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i].resize(a[i].size());
        }

        int k = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] != '.') {
                    k = (i+j+(a[i][j] == 'W'))&1;
                    break;
                }
        bool ok = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                b[i][j] = (i+j+k+1)&1 ? 'R' : 'W';
                if (a[i][j] != '.' && a[i][j] != b[i][j])
                    ok = 0;
            }
        debug(b);
        if (ok) {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                cout << b[i] << "\n";
        } else {
            cout << "NO\n";
        }
    }
}