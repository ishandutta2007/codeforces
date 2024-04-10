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
    ll m, n; cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n+1));
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            int y; cin >> y;
            a[i][y] = 1;
        }
    }
    bool ok = 1;
    for (int i = 0; i < m; i++)
        for (int j = i+1; j < m; j++) {
            bool p = 0;
            for (int k = 0; k < n; k++)
                if (a[i][k] && a[j][k])
                    p = 1;
            ok = ok && p;
        }
    cout << (ok ? "possible" : "impossible") << "\n";
}