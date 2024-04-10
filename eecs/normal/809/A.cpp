#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010, P = 1000000007;
int n, ans, x[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; i++) {
        ans = (ans + 1LL * x[i] * qp(2, i - 1)) % P;
        ans = (ans + 1LL * (P - x[i]) * qp(2, n - i)) % P;
    }
    printf("%d\n", ans);
    return 0;
}