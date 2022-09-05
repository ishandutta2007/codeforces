#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int K;
struct mat { int a[2][2]; } A, B;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

mat operator * (const mat &A, const mat &B) {
    mat C; memset(C.a, 0, sizeof(C.a));
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
            C.a[i][k] = (C.a[i][k] + 1LL * A.a[i][j] * B.a[j][k]) % P;
        }
    }
    return C;
}

mat qp(mat A, long long K) {
    mat B = A;
    for (K--; K; K >>= 1, A = A * A) {
        if (K & 1) B = B * A;
    }
    return B;
}

int main() {
    scanf("%d", &K);
    A.a[0][0] = 1, A.a[0][1] = 0;
    B.a[1][0] = 1, B.a[0][1] = 2, B.a[1][1] = 1;
    bool flag = 0;
    long long T = 1;
    while (K--) {
        long long n; scanf("%lld", &n);
        T = n % (P - 1) * T % (P - 1);
        if (n > 1) B = qp(B, n), flag = 1;
    }
    if (!flag) puts("0/1"), exit(0);
    A = A * B;
    int p = 1LL * (P + 1) / 2 * A.a[0][0] % P;
    int q = qp(2, T + P - 2);
    printf("%d/%d\n", p, q);
    return 0;
}