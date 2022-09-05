#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 1000000007;
int n, ans, a[40];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x), a[__builtin_ctz(x)]++;
    }
    for (int i = 1; i < 40; i++) if (a[i]) {
        int sum = qp(2, a[i] - 1);
        for (int j = i + 1; j < 40; j++) sum = 1LL * sum * qp(2, a[j]) % P;
        (ans += sum) %= P;
    }
    ans = (qp(2, n) - ans + P) % P;
    printf("%d\n", (ans + P - 1) % P);
    return 0;
}