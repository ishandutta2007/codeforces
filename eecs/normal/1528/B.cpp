#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000010, P = 998244353;
int n, f[maxn], sum, d[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) if (i % 2 == 0) {
        for (int j = i; j <= 2 * n; j += i) {
            if (j / 2 >= i) d[j / 2]++;
        }
    }
    f[0] = f[1] = 1, sum = 2;
    for (int i = 2; i <= n; i++) {
        f[i] = d[i];
        (f[i] += sum) %= P;
        (sum += f[i]) %= P;
    }
    printf("%d\n", f[n]);
    return 0;
}