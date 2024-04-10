#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int m, P, a[1 << 20], popcnt[1 << 20], b[50], cnt[21], foo[21];
int sum[21][1 << 20], ans[1 << 20], res[1 << 20], coef[21], binom[21][21];
ll T;

void red(int &x) {
    x += x >> 31 & P;
}

struct mat {
    int a[21][21];
    mat() { memset(a, 0, sizeof(a)); }

    mat operator * (const mat &o) {
        mat ans;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= m; k++) {
                    ans.a[i][k] = (ans.a[i][k] + 1LL * a[i][j] * o.a[j][k]) % P;
                }
            }
        }
        return ans;
    }
} A, B;

int main() {
    scanf("%d %lld %d", &m, &T, &P);
    memset(foo, -1, sizeof(foo));
    for (int i = 0; i < 1 << m; i++) {
        scanf("%d", &a[i]), a[i] %= P;
        int c = popcnt[i] = __builtin_popcount(i);
        cnt[c]++;
        if (!~foo[c]) foo[c] = i;
    }
    for (int i = 0; i <= m; i++) {
        for (int j = binom[i][0] = 1; j <= i; j++) {
            binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
        }
    }
    for (int i = 0; i <= m; i++) {
        scanf("%d", &b[i]), b[i] %= P;
    }
    for (int i = 0; i < 1 << m; i++) {
        for (int j = 0; j <= m; j++) {
            red(B.a[popcnt[i]][j] += b[__builtin_popcount(i ^ foo[j])] - P);
        }
    }
    A.a[0][0] = 1;
    for (; T; T >>= 1, B = B * B) {
        if (T & 1) A = A * B;
    }
    for (int i = 0; i <= m; i++) {
        b[i] = A.a[0][i];
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < 1 << m; j++) {
            if (i == popcnt[j]) sum[i][j] = a[j];
        }
        for (int k = 0; k < m; k++) {
            for (int S = 0; S < 1 << m; S++) {
                if (S >> k & 1) red(sum[i][S ^ (1 << k)] += sum[i][S] - P);
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        memset(ans, 0, sizeof(ans));
        for (int j = 0; j <= m; j++) {
            memset(coef, 0, sizeof(coef));
            for (int k = 0; k <= min(i, j); k++) {
                coef[k] = b[i + j - 2 * k];
                for (int l = 0; l < k; l++) {
                    coef[k] = (coef[k] - 1LL * coef[l] * binom[k][l] % P + P) % P;
                }
            }
            for (int S = 0; S < 1 << m; S++) {
                ans[S] = (ans[S] + 1LL * coef[popcnt[S]] * sum[j][S]) % P;
            }
        }
        for (int k = 0; k < m; k++) {
            for (int S = 0; S < 1 << m; S++) {
                if (S >> k & 1) red(ans[S] += ans[S ^ (1 << k)] - P);
            }
        }
        for (int j = 0; j < 1 << m; j++) {
            if (i == popcnt[j]) res[j] = ans[j];
        }
    }
    for (int i = 0; i < 1 << m; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}