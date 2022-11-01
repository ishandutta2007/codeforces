#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <string>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(26));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char ch : s) {
            ++arr[i][ch - 'a'];
        }
    }
    vector<ll> a(1 << n);
    for (int mask = 1; mask < (1 << n); ++mask) {
        vector<ll> res(26, MOD);
        vector<int> ind;
        for (int i = 0; i < n; ++i) {
            if ((1 << i) & mask) {
                ind.push_back(i);
            }
        }
        for (int i : ind) {
            for (int j = 0; j < 26; ++j) {
                res[j] = min(res[j], arr[i][j]);
            }
        }
        ll ans = 1;
        for (int i = 0; i < 26; ++i) {
            ans = ans * (res[i] + 1) % MOD;
        }
        if (ind.size() % 2 == 0) {
            ans = -ans;
        }
        a[mask] = ans;
    }
    vector<ll> ans(1 << n);
    vector<vector<int>> dp(n + 1, vector<int>(1 << n));
    for (int mask = 0; mask < (1 << n); ++mask) {
        dp[0][mask] = a[mask];
        if (dp[0][mask] < 0) {
            dp[0][mask] += MOD;
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            dp[k + 1][mask] = dp[k][mask];
            if ((mask >> k) & 1) {
                dp[k + 1][mask] += dp[k][mask ^ (1 << k)];
                if (dp[k + 1][mask] >= MOD) {
                    dp[k + 1][mask] -= MOD;
                }
            }
        }
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        ans[mask] = dp[n][mask];
    }
    ll kek = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        ans[mask] += MOD;
        ans[mask] %= MOD;
        ll sz = 0;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            if ((1 << i) & mask) {
                ++sz;
                sum += i + 1;
            }
        }
        kek ^= sz * sum * ans[mask];
    }
    cout << kek;
    return 0;
}