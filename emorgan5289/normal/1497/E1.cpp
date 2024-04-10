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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), l(n), r(n, inf);
        map<int, int> m;
        vector<vector<int>> p(n+1, vector<int>(k+1)), dp(n+1, vector<int>(k+1));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 2; j*j <= a[i]; j++)
                while (a[i]%(j*j) == 0) a[i] /= j*j;
            l[i] = m[a[i]]-1;
            if (m[a[i]]) r[m[a[i]]-1] = i;
            m[a[i]] = i+1;
        }
        debug(l, r);
        for (int j = 0; j <= k; j++) {
            int f = 0, x = 0;
            for (int i = 0; i < n; i++) {
                while (x < n && f+(l[x] >= i) <= j) f += l[x++] >= i;
                f -= r[i] < x;
                p[i][j] = x;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = inf;
                for (int x = 0; x <= j; x++)
                    cmin(dp[i][j], dp[p[i][x]][j-x]+1);
            }
        }
        cout << dp[0][k] << "\n";
    }
}