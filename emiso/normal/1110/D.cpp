#include <bits/stdc++.h>

using namespace std;

int n, m, f[1000100], rem[1000100], dp[1000100][7][7], ans, x;

int z(int pos, int quant) {
    if(pos < 1) return 0;
    return (quant + f[pos]) / 3;
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        f[x]++;
    }

    for(int i = 1; i <= m; i++) {
        rem[i] = min(f[i], 6);
        ans += max(f[i]-6, 0) / 3;
        f[i] = max(f[i]-6, 0) % 3;
    }

    for(int pos = m+1; pos > 0; pos--) {
        for(int l2 = 0; l2 <= 6; l2++) {
            for(int l1 = 0; l1 <= 6; l1++) {
                int &x = dp[pos][l2][l1], l0 = rem[pos];

                if(pos > m) x = z(pos-1, l1) + z(pos-2, l2);
                else {
                    x = dp[pos+1][l1][l0] + z(pos-2, l2);

                    if(l0 >= 3) x = max(x, dp[pos+1][l1][l0-3] + 1 + z(pos-2, l2));
                    if(l0 >= 6) x = max(x, dp[pos+1][l1][l0-6] + 2 + z(pos-2, l2));
                    for(int i = 1; i <= 6; i++) {
                        if(l0 >= i && l1 >= i && l2 >= i) {
                            x = max(x, dp[pos+1][l1-i][l0-i] + i + z(pos-2, l2-i));
                        } else break;
                    }

                }
            }
        }
    }

    printf("%d\n", ans + dp[1][0][0]);
    return 0;
}