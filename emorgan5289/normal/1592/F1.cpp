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
    ll n, m; cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(m+1, 0));
    vector<vector<int>> b(n+1, vector<int>(m+1, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char x; cin >> x;
            a[i][j] = x == 'B';
        }
    for (auto& row : a)
        debug(row);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            a[i][j] ^= a[i+1][j+1]^a[i+1][j]^a[i][j+1];
            if (a[i][j]) ans++;
        }
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < m-1; j++)
            if (a[n-1][m-1] && a[i][m-1] && a[n-1][j] && a[i][j]) {
                debug(i, j);
                ans--; goto done;
            }
    done:;
    debug();
    for (auto& row : a)
        debug(row);
    cout << ans << "\n";
}