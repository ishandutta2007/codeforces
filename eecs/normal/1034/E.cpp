#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef unsigned char num;
int n;
num f[1 << 19], g[22][1 << 19], res[22][1 << 19];
num add[256][256], sub[256][256], mul[256][256];
num tr1[256], tr2[256], tr3[256], tr4[256], val[256][4];
char s[(1 << 21) + 10], t[(1 << 21) + 10];

int main() {
    scanf("%d %s %s", &n, s, t);
    if (!n) {
        putchar((s[0] - '0') * (t[0] - '0') % 4 + '0'), exit(0);
    }
    if (n == 1) {
        putchar((s[0] - '0') * (t[0] - '0') % 4 + '0');
        putchar(((s[0] - '0') * (t[1] - '0') + (s[1] - '0') * (t[0] - '0')) % 4 + '0');
        exit(0);
    }
    for (int i = 0; i < 1 << n; i++) {
        g[__builtin_popcount(i)][i >> 2] |= (t[i] - '0') << ((i & 3) << 1);
    }
    for (int i = 0; i < 256; i++) {
        int x = i;
        for (int j = 0; j < 4; j++) {
            val[i][j] = x & 3, x >>= 2;
        }
        for (int j = 0; j < 4; j++) {
            int v = val[i][j];
            if (j & 1) v += val[i][j ^ 1];
            tr1[i] |= (v & 3) << (j << 1);
            v = val[i][j];
            if (j & 2) v += val[i][j ^ 2];
            tr2[i] |= (v & 3) << (j << 1);
            v = val[i][j];
            if (j & 1) v -= val[i][j ^ 1];
            tr3[i] |= (v & 3) << (j << 1);
            v = val[i][j];
            if (j & 2) v -= val[i][j ^ 2];
            tr4[i] |= (v & 3) << (j << 1);
        }
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            for (int k = 0; k < 4; k++) {
                mul[i][j] |= ((val[i][k] * val[j][k]) & 3) << (k << 1);
                add[i][j] |= ((val[i][k] + val[j][k]) & 3) << (k << 1);
                sub[i][j] |= ((val[i][k] - val[j][k]) & 3) << (k << 1);
            }
        }
    }
    auto FWT = [&](num *a) {
        for (int i = 1; i < 1 << n; i <<= 1) {
            if (i >= 4) {
                int t = i >> 2;
                for (int j = 0; j < 1 << (n - 2); j += t << 1) {
                    for (int k = 0; k < t; k++) {
                        a[t + j + k] = add[a[t + j + k]][a[j + k]];
                    }
                }
            } else if (i == 1) {
                for (int j = 0; j < 1 << (n - 2); j++) a[j] = tr1[a[j]];
            } else {
                for (int j = 0; j < 1 << (n - 2); j++) a[j] = tr2[a[j]];
            }
        }
    };
    auto IFWT = [&](num *a) {
        for (int i = 1; i < 1 << n; i <<= 1) {
            if (i >= 4) {
                int t = i >> 2;
                for (int j = 0; j < 1 << (n - 2); j += t << 1) {
                    for (int k = 0; k < t; k++) {
                        a[t + j + k] = sub[a[t + j + k]][a[j + k]];
                    }
                }
            } else if (i == 1) {
                for (int j = 0; j < 1 << (n - 2); j++) a[j] = tr3[a[j]];
            } else {
                for (int j = 0; j < 1 << (n - 2); j++) a[j] = tr4[a[j]];
            }
        }
    };
    for (int i = 0; i <= n; i++) {
        FWT(g[i]);
    }
    for (int i = 0; i <= n; i++) {
        memset(f, 0, sizeof(f));
        for (int j = 0; j < 1 << n; j++) {
            if (i == __builtin_popcount(j)) f[j >> 2] |= (s[j] - '0') << ((j & 3) << 1);
        }
        FWT(f);
        for (int j = 0; i + j <= n; j++) {
            for (int k = 0; k < 1 << (n - 2); k++) {
                res[i + j][k] = add[res[i + j][k]][mul[f[k]][g[j][k]]];
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        IFWT(res[i]);
    }
    for (int i = 0; i < 1 << n; i++) {
        putchar(val[res[__builtin_popcount(i)][i >> 2]][i & 3] + '0');
    }
    return 0;
}