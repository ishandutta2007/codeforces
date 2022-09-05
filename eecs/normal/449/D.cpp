#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int n, ans, a[1048576];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x), a[x]++;
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 1 << 20; j++) if (j >> i & 1) {
            a[j ^ (1 << i)] += a[j];
        }
    }
    for (int i = 0; i < 1 << 20; i++) if (a[i]) {
        a[i] = qp(2, a[i]) - 1;
        if (__builtin_popcount(i) & 1) ans = (ans - a[i] + P) % P;
        else (ans += a[i]) %= P;
    }
    printf("%d\n", ans);
    return 0;
}