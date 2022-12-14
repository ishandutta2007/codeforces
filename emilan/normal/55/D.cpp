#include <bits/stdc++.h>

using namespace std;

using u64 = unsigned long long;

// dp[pos][pow_2][pow_3][pow_5][pow_7][rem_8][rem_9][rem_5][rem_7][high]
u64 dp[20][4][3][2][2][8][9][5][7][2];
// 4838400

int a[19];
int ten8[19], ten9[19], ten5[19], ten7[19];

u64 solve(u64 x) {
    memset(dp, 0, sizeof(dp));

    for (int i = 18; ~i; i--) {
        a[i] = x % 10;
        x /= 10;
    }

    (*********dp)[1] = 1;
    u64 ans = 0;
    for (int i = 0; i < 19; i++) {
        for (int p2 = 0; p2 < 4; p2++) {
            for (int p3 = 0; p3 < 3; p3++) {
                for (int p5 = 0; p5 < 2; p5++) {
                    for (int p7 = 0; p7 < 2; p7++) {
                        for (int r8 = 0; r8 < 8; r8++) {
                            for (int r9 = 0; r9 < 9; r9++) {
                                for (int r5 = 0; r5 < 5; r5++) {
                                    for (int r7 = 0; r7 < 7; r7++) {
                                        for (int hi = 0; hi < 2; hi++) {

u64 cur = dp[i][p2][p3][p5][p7][r8][r9][r5][r7][hi];
if (!cur) continue;
for (int k = 0; k < 10; k++) {
    if (hi && k > a[i]) break;

    int np2 = k == 8 ? 3 : k == 4 ? 2 : k == 2 || k == 6 ? 1 : 0,
        np3 = k == 9 ? 2 : k == 3 || k == 6 ? 1 : 0,
        np5 = k == 5 ? 1 : 0,
        np7 = k == 7 ? 1 : 0;

    dp[i + 1]
        [max(p2, np2)][max(p3, np3)][max(p5, np5)][max(p7, np7)]
        [(r8 + k * ten8[i]) & 7]
        [(r9 + k * ten9[i]) % 9]
        [(r5 + k * ten5[i]) % 5]
        [(r7 + k * ten7[i]) % 7]
        [hi && k == a[i]] += cur;
}

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int p2 = 0; p2 < 4; p2++) {
        for (int p3 = 0; p3 < 3; p3++) {
            for (int p5 = 0; p5 < 2; p5++) {
                for (int p7 = 0; p7 < 2; p7++) {
                    for (int r8 = 0; r8 < 8; r8++) {
                        if (p2 == 1 && r8 & 1) continue;
                        if (p2 == 2 && r8 & 3) continue;
                        if (p2 == 3 && r8) continue;

                        for (int r9 = 0; r9 < 9; r9++) {
                            if (p3 == 1 && r9 && r9 != 3 && r9 != 6) continue;
                            if (p3 == 2 && r9) continue;

                            for (int r5 = 0; r5 < 5; r5++) {
                                if (p5 && r5) continue;

                                for (int r7 = 0; r7 < 7; r7++) {
                                    if (p7 && r7) continue;

                                    for (int hi = 0; hi < 2; hi++) {
                                        ans += dp[19][p2][p3][p5][p7]
                                            [r8][r9][r5][r7][hi];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return ans;
}

int main() {
    ten8[18] = ten9[18] = ten5[18] = ten7[18] = 1;
    for (int i = 17; ~i; i--) {
        ten8[i] = (ten8[i + 1] * 10) & 7;
        ten9[i] = (ten9[i + 1] * 10) % 9;
        ten5[i] = (ten5[i + 1] * 10) % 5;
        ten7[i] = (ten7[i + 1] * 10) % 7;
    }

    int t;
    cin >> t;
    while (t--) {
        u64 l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << '\n';
    }

    // sync

    // for (int i = 0; i < 100; i++) {
    //     int ans = solve(i);
    //     int ans2 = 1;
    //     for (int j = 1; j <= i; j++) {
    //         bool ok = true;
    //         for (int k = j; k; k /= 10) {
    //             if (k % 10 && j % (k % 10)) ok = false;
    //         }

    //         ans2 += ok;
    //     }

    //     if (ans != ans2) cout << i << endl;
    // }
}