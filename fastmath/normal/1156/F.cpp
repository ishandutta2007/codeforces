#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int N = 5001;
int mod(int n) {
    if (n < MOD) return n;
    else if (n < 2 * MOD) return n - MOD;
    else return n % MOD;
}
int fp(int a, int p) {
    int ans = 1, cur = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * cur);
        cur = mod(cur * cur);
    }   
    return ans;
}              
int cnt[N];
int dp[N][N];
int sum[N];
int rev[N];
int dv(int a, int b) {
    return mod(a * rev[b]);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int i = 0; i < N; ++i) {
        rev[i] = fp(i, MOD - 2);
    }   

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }   
    sum[0] = 1;
    int ans = 0;
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += cnt[i];
        if (cnt[i]) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dv(mod(sum[j - 1] * cnt[i]), n - j + 1);
                if (j < n) {
                    ans = mod(ans + dv(mod(dp[i][j] * (cnt[i] - 1)), n - j));
                }
            }   
            for (int j = 1; j < n; ++j) {
                sum[j] = sum[j] + dp[i][j];
            }   
        }
    }   
    cout << ans << '\n';
}