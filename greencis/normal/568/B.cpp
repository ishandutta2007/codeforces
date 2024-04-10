#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;
int n,C[4005][4005];
int dp[4005][4005];
char u[4005][4005];

int f(int k, int cl) {
    if (k == 0) return !cl;
    if (cl < 0) return 0;
    if (!u[k][cl]) {
        u[k][cl] = 1;
        dp[k][cl] = int(((ll)cl * (ll)f(k-1, cl) + (ll)f(k-1, cl-1)) % (ll)MOD);
    }
    return dp[k][cl];
}

int main()
{
    for (int i = 1; i < 4005; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }

    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        for (int j = 0; j <= n - i; ++j) (cur += f(n - i, j)) %= MOD;
        (ans += int( C[n][i] * 1ll * cur % ll(MOD) )) %= MOD;
    }
    cout << ans;

    return 0;
}