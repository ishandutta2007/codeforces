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

const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int dv(int a, int b) { return mod(a * fp(b, MOD - 2)); }

const int N = 1007;
int dp[N][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    dp[0][0] = 1;
    for (int i = 0; i <= 10; ++i) {
        for (int x = 0; x < N; ++x) {
            for (int j = 1; i + j <= 10; ++j) {
                for (int y = x + 1; y < N; ++y) {
                    dp[i + j][y] = mod(dp[i + j][y] + dp[i][x]);
                }   
            }   
        }
    }   
    for (int i = 0; i <= 10; ++i) {
        for (int j = 1; j < N; ++j)
            dp[i][j] = mod(dp[i][j] + dp[i][j - 1]);
    }   
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ans = mod(ans + dp[m - 1][i] * dp[m - 1][n - j + 1]);
        }   
    }   
    cout << ans << '\n';
}