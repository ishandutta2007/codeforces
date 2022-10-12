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
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> b(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            a[i][j] = c == 'X';
        }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            b[i][j] = a[i-1][j] && a[i][j-1];
            b[i][j] += b[i-1][j]+b[i][j-1]-b[i-1][j-1];
        }
    ll q; cin >> q;
    while (q--) {
        ll x, y; cin >> x >> y; x--, y--;
        bool ans = b[n-1][y]-b[n-1][x] == 0;
        cout << (ans ? "YES" : "NO") << "\n";
    }
}