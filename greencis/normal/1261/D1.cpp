#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k, a[2005];
int dp[2005][4005];

const int mod = 998244353;
inline void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[n + 1] = a[1];
    dp[0][2002] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int z = -2000; z <= 2000; ++z) {
            if (dp[i - 1][z + 2002] == 0) continue;
            //cerr << i << ' ' << z << ' ' << dp[i][z] << endl;
            if (a[i] == a[i + 1])
                dp[i][z + 2002] = dp[i - 1][z + 2002] * (ll)k % mod;
            else {
                add(dp[i][z + 1 + 2002], dp[i - 1][z + 2002]);
                add(dp[i][z - 1 + 2002], dp[i - 1][z + 2002]);
                add(dp[i][z + 2002], dp[i - 1][z + 2002] * (ll)(k - 2) % mod);
            }
        }
    }

    int ans = 0;
    for (int z = 1; z <= n; ++z)
        add(ans, dp[n][z + 2002]);
    cout << ans << endl;
}