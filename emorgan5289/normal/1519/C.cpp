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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<ll>> a(n);
        vector<ll> u(n), s(n), ans(n+1);
        for (int i = 0; i < n; i++)
            cin >> u[i];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            a[u[i]-1].pb(s[i]);
        }
        for (int i = 0; i < n; i++) {
            sort(all(a[i]), greater<>());
            int m = a[i].size();
            for (int k = 1; k < m; k++)
                a[i][k] += a[i][k-1];
            for (int k = 1; k <= m; k++)
                ans[k] += a[i][m/k*k-1];
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " \n"[i == n];
    }
}