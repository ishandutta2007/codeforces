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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2007, MOD = 998244353;
int mod(int n) {
    if (n < MOD) return n;
    else if (n < 2 * MOD) return n - MOD;
    return n % MOD;
}   
void add(int &a, int b) {
    a = mod(a + b);
}   
int dp[N][N << 1];
int n, k, h[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> h[i];
    int cnt = 0, neu = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        if (h[i] != h[j]) ++cnt;
        else ++neu;
    }   
    dp[0][N] = 1;
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < 2 * N; ++j) {
            if (dp[i][j]) {
                add(dp[i + 1][j - 1], dp[i][j]);
                add(dp[i + 1][j + 1], dp[i][j]);
                add(dp[i + 1][j], dp[i][j] * (k - 2));
            }   
        }   
    }   
    int ans = 0;
    for (int i = N + 1; i < 2 * N; ++i) add(ans, dp[cnt][i]);
    for (int i = 0; i < neu; ++i) ans = mod(ans * k);
    cout << ans << '\n';
}