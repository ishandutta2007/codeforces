#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k, dp[1005][2005][4];
const int mod = 998244353;
const int a[4][4] = {
{ 0, 1, 1, 1 },
{ 0, 0, 2, 0 },
{ 0, 2, 0, 0 },
{ 1, 1, 1, 0 }
};

inline void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    dp[1][1][0] = 1;
    dp[1][1][3] = 1;
    dp[1][2][1] = 1;
    dp[1][2][2] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 2000; ++j) {
            for (int x = 0; x < 4; ++x) {
                for (int y = 0; y < 4; ++y) {
                    add(dp[i][j + a[x][y]][y], dp[i - 1][j][x]);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 4; ++i)
        ans += dp[n][k][i];
    cout << ans % mod;
}