#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;
const int MOD = 998244353;
const int MAXV = 201;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int n;
int a[MAXN];
void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

int dp[MAXN][MAXV][2];
void solve() {
    dp[0][0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i - 1] == -1) {
            int pr = mod(dp[i - 1][0][0] + dp[i - 1][0][1]);
            for (int t = 1; t < MAXV; ++t) {
                dp[i][t][0] = pr;
                pr = mod(pr + dp[i - 1][t][0] + dp[i - 1][t][1]);
            }
            int curr = 0;
            for (int t = MAXV - 1; t >= 1; --t) {
                curr = mod(curr + dp[i - 1][t][1]);
                dp[i][t][1] = mod(curr + dp[i - 1][t][0]);
            }   
        }
        else {
            int x = a[i - 1];
            for (int t = 0; t < x; ++t) {
                dp[i][x][0] = mod(dp[i][x][0] + dp[i - 1][t][0] + dp[i - 1][t][1]);
            }
            dp[i][x][1] = dp[i - 1][x][0];
            for (int t = x; t < MAXV; ++t) {
                dp[i][x][1] = mod(dp[i][x][1] + dp[i - 1][t][1]);
            }
        }   
    }
}

void print() {
    int ans = 0;
    for (int i = 1; i < MAXV; ++i) {
        ans = mod(ans + dp[n][i][1]);
    }
    cout << ans << '\n';
}   

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}