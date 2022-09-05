#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 998244353;
int n, ans, x[maxn], y[maxn], type[maxn], f[maxn], g[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &type[i]);
        g[i] = (f[i - 1] - f[max(0, int(lower_bound(x, x + i, y[i]) - x - 1))] + P) % P;
        g[i] = (g[i] + x[i] - y[i]) % P;
        f[i] = (f[i - 1] + g[i]) % P;
        if (type[i]) (ans += g[i]) %= P;
    }
    printf("%d\n", (ans + x[n] + 1) % P);
    return 0;
}