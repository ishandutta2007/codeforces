#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int P = 1051131;
int m, s, xors, cnt[26], ctz[1 << 25], a[1 << 25], coef[1 << 25];
long long T;

int inv(int x) {
    for (int i = 0; i < P; i++) {
        if (1LL * i * x % P == 1) return i;
    }
    assert(0);
}

struct mat {
    int a[26][26];
    mat() { memset(a, 0, sizeof(a)); }

    mat operator * (const mat &o) const {
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
    scanf("%d %lld %d", &m, &T, &s);
    for (int i = 0; i < s; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = s; i < 1 << m; i++) {
        a[i] = (101LL * a[i - s] + 10007) % P;
    }
    for (int i = 0; i < 1 << m; i++) {
        ctz[i] = __builtin_ctz(i);
        cnt[i ? ctz[i] + 1 : 0]++;
    }
    for (int i = 0; i < 1 << m; i++) {
        if (!i) { ++B.a[0][0] %= P; continue; }
        (B.a[0][ctz[i] + 1] += (1 << ctz[i])) %= P;
    }
    for (int i = 1; i <= m; i++) {
        (B.a[i][0] += (1 << (i - 1))) %= P;
        for (int j = 1; j <= m; j++) if (i ^ j) {
            B.a[i][j] = (B.a[i][j] + 1LL * cnt[j] * (1 << min(i - 1, j - 1))) % P;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 1 << m; j++) if (ctz[j] == i - 1) {
            for (int k = 0; k < 1 << m; k++) if (ctz[k] == i - 1) {
                if (j == k) ++B.a[i][i] %= P;
                else (B.a[i][i] += (1 << ctz[abs(j - k)])) %= P;
            }
            break;
        }
    }
    A.a[0][0] = 1;
    for (; T; T >>= 1, B = B * B) {
        if (T & 1) A = A * B;
    }
    for (int i = 0; i <= m; i++) {
        A.a[0][i] = 1LL * A.a[0][i] * inv(cnt[i]) % P;
    }
    for (int i = 0; i < 1 << m; i++) {
        coef[i] = A.a[0][i ? ctz[i] + 1 : 0];
    }
    auto FWT = [&](int *c) {
        for (int i = 1; i < 1 << m; i <<= 1) {
            for (int j = 0; j < 1 << m; j += i << 1) {
                for (int k = 0; k < i; k++) {
                    int p = c[j + k], q = c[i + j + k];
                    if ((c[j + k] = p + q) >= P) c[j + k] -= P;
                    if ((c[i + j + k] = p - q) < 0) c[i + j + k] += P;
                }
            }
        }
    };
    FWT(a), FWT(coef);
    for (int i = 0; i < 1 << m; i++) {
        a[i] = 1LL * a[i] * coef[i] % P;
    }
    FWT(a);
    for (int i = 0, t = inv(1 << m); i < 1 << m; i++) {
        xors ^= 1LL * t * a[i] % P;
    }
    printf("%d\n", xors);
    return 0;
}