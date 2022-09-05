#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 1000000007;
int n, q, a[maxn], cur[maxn], cur2[maxn], pre[maxn];
int sum[6][maxn], pw[6][maxn], binom[6][6], pwx[6], pwd[6];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pre[i] = (pre[i - 1] + a[i]) % P;
    }
    fill(cur, cur + n + 1, 1);
    fill(cur2, cur2 + n + 1, 1);
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= n; j++) {
            sum[i][j] = ((j ? sum[i][j - 1] : 0) + cur[j]) % P;
            pw[i][j] = ((j ? pw[i][j - 1] : 0) + cur2[j]) % P;
            cur[j] = 1LL * a[j] * cur[j] % P;
            cur2[j] = 1LL * j * cur2[j] % P;
        }
    }
    for (int i = 0; i <= 5; i++) {
        for (int j = binom[i][0] = 1; j <= i; j++) {
            binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
        }
    }
    while (q--) {
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d);
        int s = (pre[r] - pre[l - 1] + P) % P;
        s = (s - 1LL * (r - l + 1) * (r - l) / 2 % P * d % P + P) % P;
        int x = 1LL * s * qp(r - l + 1, P - 2) % P;
        bool flag = 1;
        for (int i = pwx[0] = pwd[0] = 1; i <= 5; i++) {
            pwx[i] = 1LL * x * pwx[i - 1] % P;
            pwd[i] = 1LL * d * pwd[i - 1] % P;
        }
        for (int i = 1; i <= 5; i++) {
            int val = 0;
            for (int j = 0; j <= i; j++) {
                val = (val + 1LL * binom[i][j] * pwx[j] % P * pwd[i - j] % P * pw[i - j][r - l]) % P;
            }
            if (val != (sum[i][r] - sum[i][l - 1] + P) % P) { flag = 0; break; }
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}