#include <stdio.h>
using namespace std;
const int MOD = 1e9 + 7, M_SIZE = 16;

struct Matrix {
    long long M[M_SIZE][M_SIZE];
    long long* operator[] (int i) const { return (long long*) M[i]; }
    Matrix () {}
    Matrix (int c, int d) {
        for (int i = 0; i < M_SIZE; ++i)
            for (int j = 0; j < M_SIZE; ++j)
                M[i][j] = i < c && j < c && (i - j) * (i - j) <= d;
    }
} ONE (M_SIZE, 0);

Matrix operator * (Matrix A, Matrix B) {
    Matrix C (-1, -1);
    for (int i = 0; i < M_SIZE; ++i)
        for (int j = 0; j < M_SIZE; ++j)
            for (int k = 0; k < M_SIZE; ++k)
                (C[i][j] += A[i][k] * B[k][j]) %= MOD;
    return C;
}

Matrix power (Matrix A, long long k) {
    if (k == 0) return ONE;
    if (k == 1) return A;
    Matrix tmp = power(A, k / 2);
    return (tmp * tmp * (k & 1 ? A : ONE));
}

int main() {
    Matrix A (1, 1);
    int n; long long k;
    scanf("%d%I64d", &n, &k);
    while (n--) {
        long long a, b; int c;
        scanf("%I64d%I64d%d", &a, &b, &c);
        Matrix tmp (c + 1, 1);
        A = A * power (tmp, (n ? b : k) - a);
    }
    printf("%I64d", A[0][0]);
    return 0;
}