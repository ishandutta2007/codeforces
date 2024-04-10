#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    const int progmatic[5] = {25, 25, 25, 25, 15};
    static int dp[4][4][201][201];
    static pair<int, int> p[4][4][201][201];

    for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j <= 3; ++j) {
            for (int k = 0; k <= 200; ++k) {
                for (int l = 0; l <= 200; ++l) {
                    dp[i][j][k][l] = INT_MIN;
                }
            }
        }
    }

    for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j <= 3; ++j) {
            if ((i == 3) ^ (j == 3)) {
                dp[i][j][0][0] = i-j;
            }
        }
    }

    for (int i = 3; i >= 0; --i) {
        for (int j = 3; j >= 0; --j) {
            if (i == 0 && j == 0) {
                continue;
            }
            int kontest = progmatic[i + j - 1];
            for (int k = 0; k <= 200; ++k) {
                for (int l = 0; l <= 200; ++l) {
                    if (dp[i][j][k][l] == INT_MIN) {
                        continue;
                    }

                    auto updGame = [&](int dk, int dl) {
                        assert(abs(dk-dl) >= 2);
                        int ni = i - (dk > dl), nj = j - (dk < dl);
                        assert(ni >= 0 && nj >= 0);
                        int nk = k+dk, nl = l+dl;
                        if (ni == 3 || nj == 3) {
                            return;
                        }
                        if (nk <= 200 && nl <= 200 && dp[ni][nj][nk][nl] < dp[i][j][k][l]) {
                            dp[ni][nj][nk][nl] = dp[i][j][k][l];
                            p[ni][nj][nk][nl] = make_pair(dk, dl);
                        }
                    };

                    if (i != 0) {
                        // first must win!
                        for (int q = 0; q <= kontest-2; ++q) {
                            updGame(kontest, q);
                        }
                        for (int q = kontest; q <= 200; ++q) {
                            updGame(q, q-2);
                        }
                    }
                    if (j != 0) {
                        // second must win!
                        for (int q = 0; q <= kontest-2; ++q) {
                            updGame(q, kontest);
                        }
                        for (int q = kontest; q <= 200; ++q) {
                            updGame(q-2, q);
                        }
                    }
                }
            }
        }
    }

    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        int val = dp[0][0][a][b];
        if (val == INT_MIN) {
            cout << "Impossible\n";
            continue;
        }
        if (val > 0) {
            cout << 3 << ":" << 3-val << "\n";
        } else {
            cout << 3 + val << ":" << 3 << "\n";
        }
        int q = 0, w = 0;
        while (a != 0 || b != 0) {
            int da, db; tie(da, db) = p[q][w][a][b];
            a -= da; b -= db;
            ++(da > db ? q : w);
            cout << da << ":" << db << " ";
        }
        cout << "\n";
    }

    return 0;
}