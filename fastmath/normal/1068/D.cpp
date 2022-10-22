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
const int N = 1e5 + 7, C = 200, MOD = 998244353;
int mod(int n) {
    n %= MOD;
    if (n < 0)
        return n + MOD;
    else
        return n;
}   
void add(int &a, int b) {
    a = mod(a + b);
}   
int a[N];
int dp[N][C + 1][2];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; 
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    if (a[1] != -1) {
        dp[1][a[1]][0] = 1;
    }   
    else {
        for (int i = 1; i <= 200; ++i) {
            dp[1][i][0] = 1;
        }   
    }   
    for (int i = 2; i <= n; ++i) {
        if (a[i] != -1) {
            for (int p = 1; p < a[i]; ++p)
                add(dp[i][a[i]][0], dp[i - 1][p][0] + dp[i - 1][p][1]);
            dp[i][a[i]][1] = mod(dp[i - 1][a[i]][0] + dp[i - 1][a[i]][1]);
            for (int p = a[i] + 1; p <= 200; ++p)
                add(dp[i][a[i]][1], dp[i - 1][p][1]);
        }       
        else {
            int l = 0, r = 0;
            for (int j = 1; j <= 200; ++j)
                add(r, dp[i - 1][j][1]);
            for (int j = 1; j <= 200; ++j) {
                add(r, -dp[i - 1][j][1]);
                dp[i][j][0] = l;
                dp[i][j][1] = mod(dp[i - 1][j][0] + dp[i - 1][j][1] + r);
                add(l, dp[i - 1][j][0] + dp[i - 1][j][1]);
            }   
        }   
    }
    int ans = 0;
    for (int i = 1; i <= 200; ++i) {
        add(ans, dp[n][i][1]);
    }   
    cout << ans << '\n';
}