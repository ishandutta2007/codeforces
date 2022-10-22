#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1001;
const int MOD = 998244353;
const int C = 100007;

inline int mod(int n) {
    if (n < 0) return n + MOD;
    if (n < MOD) return n;
    if (n < 2 * MOD) return n - MOD;
    return n % MOD;
}   

int dp[N][N];

int n, k;
int a[N];
int cnt[C];

int an[N][N];
int ptr[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int i = 0; i < N; ++i) an[i][0] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            an[i][j] = mod(an[i - 1][j - 1] + an[i - 1][j]);
        }   
    }   

    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);           
    
    cnt[0] = an[n][k];
    for (int i = 0; i < n; ++i) {
        ptr[i] = i - 1;
    }   
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }   
    for (int d = 1; d < C; ++d) {
        for (int i = 0; i < n; ++i) {
            while (ptr[i] != -1 && a[i] - a[ptr[i]] < d) --ptr[i];
        }   
        int c = min(k, C / d + 1);
        if (c < k) continue;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= c; ++j) {
                dp[i + 1][j] = mod(dp[i][j] + dp[ptr[i] + 1][j - 1]);
            }
        }
        cnt[d] = dp[n][k];
    }   
    
    for (int i = 0; i + 1 < C; ++i) cnt[i] = mod(cnt[i] - cnt[i + 1]);
    int ans = 0;
    for (int i = 0; i < C; ++i) ans = mod(ans + cnt[i] * i);
    cout << ans << '\n';
}