#include <bits/stdc++.h>
using namespace std;

const int maxn = 131072, P = 1000000007;
int n, ans, cnt[maxn], fib[maxn], A[maxn], B[maxn], C[maxn];

void red(int &x) {
    x += x >> 31 & P;
}

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    while (n--) {
        int s; scanf("%d", &s);
        cnt[s]++;
    }
    fib[1] = 1;
    for (int i = 2; i < maxn; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % P;
    }
    for (int i = 0; i < maxn; i++) {
        int S = (maxn - 1) ^ i;
        for (int j = S; ; j = (j - 1) & S) {
            A[i | j] = (A[i | j] + 1LL * cnt[i] * cnt[j]) % P;
            if (!j) break;
        }
    }
    for (int i = 0; i < maxn; i++) {
        A[i] = 1LL * A[i] * fib[i] % P;
        B[i] = 1LL * cnt[i] * fib[i] % P;
        C[i] = cnt[i];
    }
    auto FWT = [&](int *a) {
        for (int i = 1; i < maxn; i <<= 1) {
            for (int j = 0; j < maxn; j += i << 1) {
                for (int k = 0; k < i; k++) {
                    int p = a[j + k], q = a[i + j + k];
                    red(a[j + k] = p + q - P), red(a[i + j + k] = p - q);
                }
            }
        }
    };
    FWT(C);
    for (int i = 0; i < maxn; i++) {
        C[i] = 1LL * C[i] * C[i] % P;
    }
    FWT(C);
    int tmp = qp(maxn, P - 2);
    for (int i = 0; i < maxn; i++) {
        C[i] = 1LL * fib[i] * C[i] % P * tmp % P;
    }
    auto FMT = [&](int *a, int op) {
        for (int i = 1; i < maxn; i <<= 1) {
            for (int j = 0; j < maxn; j++) if (!(i & j)) {
                if (op == 1) red(a[j] += a[i | j] - P);
                else red(a[j] -= a[i | j]);
            }
        }
    };
    FMT(A, 1), FMT(B, 1), FMT(C, 1);
    for (int i = 0; i < maxn; i++) {
        A[i] = 1LL * A[i] * B[i] % P * C[i] % P;
    }
    FMT(A, -1);
    for (int i = 1; i < maxn; i <<= 1) {
        red(ans += A[i] - P);
    }
    printf("%d\n", ans);
    return 0;
}