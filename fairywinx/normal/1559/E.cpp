#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

const int mod = 998244353;

int solve(int n, vector<pair<int, int>> a, int m) {
    for (int i = 0; i < n; ++i)
        m -= a[i].first;
    if (m < 0)
        return 0;
    vector<int> dp_last(m + 2);
    dp_last[m + 1] = 1;
    for (int i = 0; i < n; ++i) {
        vector<int> dp(m + 1);
        for (int j = 0; j <= m; ++j) {
            // cout << j << ' ' << j + a[i].second - a[i].first << '\n';
            dp[j] = dp_last[min(j + a[i].second - a[i].first + 1, m + 1)] - dp_last[j];
            dp[j] = (dp[j] + mod) % mod;
        }
        for (int j = 0; j <= m; ++j)
            dp_last[j + 1] = (dp_last[j] + dp[j]) % mod;
    }
    return dp_last.back();
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    int ans = solve(n, a, m);

    vector<int> min_del(m + 1);
    iota(all(min_del), 0);
    for (int i = 2; i <= m; ++i) {
        if (min_del[i] == i) {
            for (int j = i; j <= m; j += i)
                min_del[j] = min(min_del[j], i);
        }
    }

    vector<int> who(m + 1);
    vector<int> good(m + 1, 1);
    for (int i = 2; i <= m; ++i) {
        int cnt = 0;
        int now = i;
        while (now > 1) {
            int z = 0;
            int c = min_del[now];
            ++cnt;
            while (now % c == 0)
                now /= c, ++z;
            if (z > 1)
                good[i] = 0;
        }
        who[i] = cnt;
    }
    for (int c = 2; c <= m; ++c) {
        if (!good[c])
            continue;
        vector<pair<int, int>> tmp(n);
        for (int i = 0; i < n; ++i) {
            tmp[i].first = (a[i].first + c - 1) / c;
            tmp[i].second = a[i].second / c;
            if (tmp[i].first > tmp[i].second)
                good[c] = false;
        }
        if (!good[c])
            continue;
        int val = solve(n, tmp, m / c);
        if (who[c] % 2 == 1)
            ans = (ans - val + mod) % mod;
        else
            ans = (ans + val) % mod;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    // int t;
    // cin >> t;
    // while (t--)
    //     solve();
}