#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll P = 1000000007;
ll n, m;
struct mat { ll a[110][110]; };

mat operator * (mat A, mat B) {
    mat C; memset(C.a, 0, sizeof(C.a));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                (C.a[i][k] += A.a[i][j] * B.a[j][k]) %= P;
            }
        }
    }
    return C;
}

mat power(mat A, ll k) {
    mat B; memset(B.a, 0, sizeof(B.a));
    for (int i = 0; i < m; i++) {
        B.a[i][i] = 1;
    }
    for (; k; k >>= 1, A = A * A) {
        if (k & 1) B = B * A;
    }
    return B;
}

int main() {
    scanf("%lld %lld", &n, &m);
    mat A; memset(A.a, 0, sizeof(A.a));
    for (int i = 0; i < m - 1; i++) {
        A.a[i][i + 1] = 1;
    }
    A.a[0][0] = A.a[m - 1][0] = 1;
    A = power(A, n);
    printf("%lld\n", A.a[0][0]);
    return 0;
}