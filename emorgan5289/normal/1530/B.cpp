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
        ll n, m; cin >> n >> m;
        vector<vector<int>> c(n, vector<int>(m, 0));
        for (int i = 2; i < n; i += 2)
            c[i][0] = c[n-1-i][m-1] = 1;
        for (int i = 2; i < m; i += 2)
            c[0][m-1-i] = c[n-1][i] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << c[i][j];
            cout << "\n";
        }
        cout << "\n";
    }
}