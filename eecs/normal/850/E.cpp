#include <bits/stdc++.h>
using namespace std;

const int maxn = 1048576, P = 1000000007;
int n, ans, A[maxn];
char s[maxn];

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
    scanf("%d %s", &n, s);
    for (int i = 0; i < 1 << n; i++) {
        if (s[i] == '1') A[i]++;
    }
    for (int i = 1; i < 1 << n; i <<= 1) {
        for (int j = 0; j < 1 << n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                int p = A[j + k], q = A[i + j + k];
                red(A[j + k] = p + q - P), red(A[i + j + k] = p - q);
            }
        }
    }
    for (int i = 0; i < 1 << n; i++) {
        A[i] = 1LL * A[i] * A[i] % P;
    }
    for (int i = 1; i < 1 << n; i <<= 1) {
        for (int j = 0; j < 1 << n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                int p = A[j + k], q = A[i + j + k];
                red(A[j + k] = p + q - P), red(A[i + j + k] = p - q);
            }
        }
    }
    for (int i = 0; i < 1 << n; i++) if (A[i]) {
        ans = (ans + 1LL * A[i] * (1 << (n - __builtin_popcount(i)))) % P;
    }
    printf("%lld\n", 3LL * ans % P * qp(2, P - 1 - n) % P);
    return 0;
}