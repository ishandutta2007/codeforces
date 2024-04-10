#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1'000'000'007;
inline void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

int dp[2][1 << 11];

int main() {
    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    int cur = 0;
    while (n--) {
        cur ^= 1;
        memset(dp[cur], 0, sizeof(dp[cur][0]) * (1 << k));
        int L, R;
        cin >> L;
        if (L == 0) L = 0, R = 1;
        else L = R = (L == 4);
        for (int mask = 0; mask < (1 << k); ++mask) {
            if (dp[cur ^ 1][mask]) {
                for (int d = L; d <= R; ++d) {
                    int nxtMask = mask + (1 << d);
                    if (d == 1 && (mask & 1))
                        nxtMask = 2;
                    if (nxtMask >= (1 << (k - 1)))
                        nxtMask = 1 << (k - 1);
                    add(dp[cur][nxtMask], dp[cur ^ 1][mask]);
                }
            }
        }
    }
    cout << dp[cur][1 << (k - 1)] << endl;
}