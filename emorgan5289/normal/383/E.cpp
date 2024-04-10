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

const int N = 24;
ll dp[1<<N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x = 0;
        string s; cin >> s;
        for (char c : s) x |= 1<<(c-'a');
        dp[x]++;
    }
    // for (int i = 0; i < 1<<N; i++)
    //     if (dp[i] > 0) debug(i, dp[i]);
    for (int j = 0; j < N; j++)
        for (int i = 0; i < 1<<N; i++)
            if (i&(1<<j))
                dp[i] += dp[i^(1<<j)];
    ll ans = 0;
    for (int i = 0; i < 1<<N; i++) {
        // if (dp[i] > 0) debug(i, dp[i]);
        ans ^= (n-dp[i])*(n-dp[i]);
    }
    cout << ans << "\n";
}