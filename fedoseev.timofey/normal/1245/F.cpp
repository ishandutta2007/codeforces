#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int K = 31;

ll dp[K][2][2][2][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j <= 1; ++j) {
                for (int k = 0; k <= 1; ++k) {
                    for (int t = 0; t <= 1; ++t) {
                        for (int l = 0; l <= 1; ++l) {
                            dp[i][j][k][t][l] = 0;
                        }
                    }
                }
            }
        }
        dp[K - 1][0][0][0][0] = 1;

        for (int i = K - 1; i >= 1; --i) {
            int b1 = (l >> (i - 1)) & 1;
            int b2 = (r >> (i - 1)) & 1;
            for (int j = 0; j <= 1; ++j) {
                for (int k = 0; k <= 1; ++k) {
                    for (int t = 0; t <= 1; ++t) {
                        for (int l = 0; l <= 1; ++l) {
                            for (int nb1 = 0; nb1 <= 1; ++nb1) {
                                for (int nb2 = 0; nb2 <= 1; ++nb2) {
                                    if (nb1 && nb2) continue;
                                    if (!j && nb1 < b1) continue;
                                    if (!t && nb2 < b1) continue;
                                    if (!k && nb1 > b2) continue;
                                    if (!l && nb2 > b2) continue;
                                    int nj = j | (nb1 > b1);
                                    int nk = k | (nb1 < b2);
                                    int nt = t | (nb2 > b1);
                                    int nl = l | (nb2 < b2);
                                    dp[i - 1][nj][nk][nt][nl] += dp[i][j][k][t][l];
                                }
                            }
                        }
                    }
                }
            }
        }
        ll ans = 0;
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
                for (int t = 0; t <= 1; ++t) {
                    for (int l = 0; l <= 1; ++l) {
                        ans += dp[0][j][k][t][l];
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}