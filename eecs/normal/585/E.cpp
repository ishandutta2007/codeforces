#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000010, A = 10000000, P = 1000000007;
int n, a[maxn], f[maxn], g[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x), a[x]++;
    }
    for (int i = A; i; i--) {
        int s = 0;
        for (int j = i; j <= A; j += i) s += a[j];
        f[i] = qp(2, g[i] = s) - 1;
        for (int j = i + i; j <= A; j += i) red(f[i] -= f[j]);
    }
    f[1] = 0;
    for (int i = A; i; i--) {
        int s1 = g[i], s2 = 0;
        for (int j = i; j <= A; j += i) red(s2 += f[j] - P);
        g[i] = 1LL * s1 * s2 % P;
        for (int j = i + i; j <= A; j += i) red(g[i] -= g[j]);
    }
    printf("%d\n", g[1]);
    return 0;
}