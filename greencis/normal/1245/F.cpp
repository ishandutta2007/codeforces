#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll dp[2][2][2][2][31]; /// 0 - prefix =

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0][30] = 1;
        for (int i = 29; i >= 0; --i) {
            int dig_l = (l >> i) & 1;
            int dig_r = (r >> i) & 1;
            for (int al = 0; al < 2; ++al) {
                for (int ar = 0; ar < 2; ++ar) {
                    for (int bl = 0; bl < 2; ++bl) {
                        for (int br = 0; br < 2; ++br) {
                            if (dp[al][ar][bl][br][i + 1] == 0) continue;
                            for (int d1 = 0; d1 < 2; ++d1) {
                                if (al == 0 && d1 < dig_l) continue;
                                if (ar == 0 && d1 > dig_r) continue;
                                for (int d2 = 0; d2 <= !d1; ++d2) {
                                    if (bl == 0 && d2 < dig_l) continue;
                                    if (br == 0 && d2 > dig_r) continue;

                                    dp[al == 0 && d1 == dig_l ? 0 : 1][ar == 0 && d1 == dig_r ? 0 : 1]
                                      [bl == 0 && d2 == dig_l ? 0 : 1][br == 0 && d2 == dig_r ? 0 : 1][i]
                                        += dp[al][ar][bl][br][i + 1];
                                }
                            }
                        }
                    }
                }
            }
        }

        ll ans = 0;
        for (int a = 0; a < 2; ++a)
        for (int b = 0; b < 2; ++b)
        for (int c = 0; c < 2; ++c)
        for (int d = 0; d < 2; ++d)
            ans += dp[a][b][c][d][0];
        cout << ans << endl;
    }
}