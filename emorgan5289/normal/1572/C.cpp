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
        vector<ll> a, b(n);
        map<ll, vector<ll>> ind;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (i == 0 || b[i] != b[i-1]) a.pb(b[i]);
        }
        n = a.size();
        debug(a);
        for (int i = 0; i < n; i++)
            ind[a[i]].pb(i);
        // vector<array<ll, 2>> v;
        // for (auto& [_, x] : ind) {
        //     for (int i = 0; i < x.size(); i++)
        //         for (int j = 0; j < i; j++)
        //             v.pb({x[j], x[i]});
        // }
        // // sort(all(v));
        // debug(v);
        vector<vector<ll>> dp(n, vector<ll>(n, 0));
        vector<vector<ll>> e(n);
        for (int i = 0; i < n; i++)
            for (int j : ind[a[i]])
                if (j < i) e[i].pb(j);
        for (ll len = 2; len <= n; len++)
            for (int i = 0; i < n-len+1; i++) {
                int j = i+len-1;
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                if (a[i] == a[j])
                    cmax(dp[i][j], dp[i+1][j-1]+1);
                for (int k : e[j]) {
                    cmax(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        cout << n-1-dp[0][n-1] << "\n";
    }
}