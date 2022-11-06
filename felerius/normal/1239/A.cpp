#include <bits/stdc++.h>

// Contest: Codeforces Round #594 (Div. 1) (https://codeforces.com/contest/1239)
// Problem: A: Ivan the Fool and the Probability Theory (https://codeforces.com/contest/1239/problem/A)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

const ll M = 1e9 + 7;

ll mod_pow(ll b, ll e) {
    ll r = 1;
    while (e) {
        if (e % 2)
            r = (r * b) % M;
        b = b * b % M;
        e /= 2;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    // 0: 1st black, 1: 2nd black, 2: 1st white, 3: 2nd white
    vector<array<ll, 4>> dp(max(n, m));
    dp[0][0] = dp[0][2] = 1;
    for (int i = 1; i < max(m, n); ++i) {
        dp[i][0] = (dp[i-1][2] + dp[i-1][3]) % M;
        dp[i][1] = dp[i-1][0];
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % M;
        dp[i][3] = dp[i-1][2];
    }

    // Alternating + others
    ll res = (dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] - 2) + (dp[m-1][0] + dp[m-1][1] + dp[m-1][2] + dp[m-1][3]);

    cout << (res % M) << '\n';
    return 0;
}