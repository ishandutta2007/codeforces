#include <bits/stdc++.h>
using namespace std;

const int maxn = 6010;
int n, x[maxn], y[maxn], cnt[4][4];
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        cnt[x[i] % 4][y[i] % 4]++;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int a = 0; a < 4; a++) {
                for (int b = 0; b < 4; b++) {
                    for (int x = 0; x < 4; x++) {
                        for (int y = 0; y < 4; y++) {
                            int d1 = __gcd(i - a + 4, j - b + 4);
                            int d2 = __gcd(i - x + 4, j - y + 4);
                            int d3 = __gcd(a - x + 4, b - y + 4);
                            if ((d1 + d2 + d3) % 4) continue;
                            if (i == a && j == b || i == x && j == y || a == x && b == y) continue;
                            ans += 1LL * cnt[i][j] * cnt[a][b] * cnt[x][y];
                        }
                    }
                }
            }
        }
    }
    ans /= 6;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int a = 0; a < 4; a++) {
                for (int b = 0; b < 4; b++) {
                    int d1 = __gcd(i - a + 4, j - b + 4);
                    int d2 = 0;
                    int d3 = d1;
                    if ((d1 + d2 + d3) % 4) continue;
                    if (i == a && j == b) continue;
                    ans += 1LL * cnt[i][j] * (cnt[i][j] - 1) / 2 * cnt[a][b];
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ans += 1LL * cnt[i][j] * (cnt[i][j] - 1) * (cnt[i][j] - 2) / 6;
        }
    }
    printf("%lld\n", ans);
    return 0;
}