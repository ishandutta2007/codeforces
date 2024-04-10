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

using ld = long double;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll k, q; cin >> k >> q;
    int n = 1000;
    vector<ld> dp(k+1), tmp(k+1);
    vector<int> ans(n+1, inf);
    dp[0] = 1;
    for (int j = 1; 1; j++) {
        tmp[0] = 0;
        for (int i = 1; i <= k; i++)
            tmp[i] = (dp[i]*i + dp[i-1]*(k-i+1))/k;
        swap(dp, tmp);
        for (int i = 0; i <= n; i++)
            if (dp[k]*2000 > i) cmin(ans[i], j);
        if (dp[k]*2000 > n) break;
    }
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        cout << ans[x] << "\n";
    }
}