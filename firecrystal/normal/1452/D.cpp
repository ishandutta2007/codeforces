#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 200005, P = 998244353;

int n, f[N][2];

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i][0] = f[i - 1][1];
        f[i][1] = (f[i - 1][0] + f[i - 1][1]) % P;
    }
    printf("%lld\n", (LL)f[n][1] * power(power(2, n), P - 2) % P);
    return 0;
}