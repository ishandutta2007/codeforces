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
        string s; cin >> s;
        vector<ll> row(n*m), col(n*m);
        ll x = 0;
        vector<ll> a(m);
        for (int i = 0; i < n*m; i++) {
            if (s[i] == '1' && a[i%m] == 0)
                a[i%m] = 1, x++;
            col[i] = x;
        }

        vector<ll> p(n*m);
        for (int i = 0; i < n*m; i++)
            p[i] = (s[i] == '1' ? 1 : 0) + (i == 0 ? 0 : p[i-1]);
        for (int i = n*m-1; i >= m; i--)
            p[i] -= p[i-m];

        debug(p);

        for (int i = 0; i < n*m; i++) {
            row[i] = (i < m ? 0 : row[i-m]) + (p[i] > 0 ? 1 : 0);
        }

        debug(col);
        debug(row);

        for (int i = 0; i < n*m; i++)
            cout << row[i]+col[i] << " \n"[i == n*m-1];
    }
}