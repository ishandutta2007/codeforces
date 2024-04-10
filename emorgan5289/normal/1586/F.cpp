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
    ll n, k; cin >> n >> k;
    vector<vector<ll>> c(n, vector<ll>(n));
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            for (ll x = 1, y = 0; 1; x *= k, y++) {
                if (i/x == j/x) {
                    cmax(ans, y);
                    c[i][j] = y;
                    break;
                }
            }
        }
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            cout << c[i][j] << " \n"[i == n-1];
}