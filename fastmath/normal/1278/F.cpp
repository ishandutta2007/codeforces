#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 5007, MOD = 998244353;
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) 
            ans = ans * c % MOD;
        c = c * c % MOD;
    }   
    return ans;
}   
int f[N], inv[N];
int C(int n, int k) {
    if (n < k)
        return 0;
    int a = 1;
    for (int i = n; i > n - k; --i)
        a = a * i % MOD;
    return a * inv[k] % MOD;
}   
int n, m, k, mem[N], dp[N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    f[0] = inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % MOD;
        inv[i] = fp(f[i], MOD - 2);
    }
    cin >> n >> m >> k;
    int ans = 0;
    int inv = fp(m, MOD - 2);
    for (int i = 0; i < N; ++i)
        mem[i] = C(n, i);
    dp[0][0] = 1;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= i && j <= n; ++j) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * j) % MOD;
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * (n - j)) % MOD;
        }   
    }   
    for (int i = 1; i <= min(n, k); ++i) {
        int cnt = dp[k][i];
        int p = fp(inv, i);
        ans = (ans + cnt * p) % MOD;
    }   
    cout << ans << '\n';
}