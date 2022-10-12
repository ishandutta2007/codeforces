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
        ll n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<ll>> d(n, vector<ll>(n));
        for (int len = 2; len <= n; len++)
            for (int i = 0; i < n-len+1; i++) {
                int j = i+len-1;
                if (a[i] > a[j]) d[i][j]++;
                if (j > i+1)
                    d[i][j] += d[i][j-1]+d[i+1][j]-d[i+1][j-1];
            }
        ll ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i+2; j < n; j++) {
                if (a[i] < a[j]) {
                    ans += d[i+1][n-1];
                    ans -= d[i+1][j];
                    ans -= d[j][n-1];
                }
            }
        cout << ans << "\n";
    }
}