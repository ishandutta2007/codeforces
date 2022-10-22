#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e6 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

inline int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}

int lp[MAXN];
vector <int> pr;

int dp[MAXN];
void precalc() {
    for (int i = 2; i < MAXN; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < MAXN; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }   

    dp[1] = 0;
    for (int i = 2; i < MAXN; ++i) {
        int e = lp[i];
        dp[i] = (i / e) * (e * (e - 1) / 2) + dp[i / e];
        dp[i] = mod(dp[i]);
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    precalc();

    int t, l, r;
    cin >> t >> l >> r;

    int ans = 0;
    int curr = 1;
    for (int i = l; i <= r; ++i) {
        ans += mod(curr * dp[i]);
        curr = mod(curr * t);
    }
    cout << mod(ans) << '\n';

    return 0;
}