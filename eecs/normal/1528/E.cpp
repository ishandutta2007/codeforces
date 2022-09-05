#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 998244353;
const int inv2 = (P + 1) / 2, inv6 = (P + 1) / 6;
int n, f[maxn], pre[maxn];

int main() {
    scanf("%d", &n);
    auto calc = [&](int n, int m) {
        if (m == 2) return 1LL * n * (n + 1) % P * inv2 % P;
        return 1LL * n * (n + 1) % P * (n + 2) % P * inv6 % P;
    };
    for (int i = f[0] = pre[0] = 1; i <= n; i++) {
        f[i] = (f[i - 1] + 1LL * f[i - 1] * (i > 1 ? pre[i - 2] : 0) + calc(f[i - 1], 2)) % P;
        pre[i] = (pre[i - 1] + f[i]) % P;
    }
    int t = n > 1 ? pre[n - 2] : 0;
    int ans = (f[n] + 1LL * f[n - 1] * calc(t, 2) + 1LL * t * calc(f[n - 1], 2) + calc(f[n - 1], 3)) % P;
    ans = (2LL * ans + P - 1) % P;
    for (int i = 0; i < n - 1; i++) {
        ans = (ans + 1LL * (f[i] + P - 1) * (f[n - i - 1] - f[n - i - 2] + P)) % P;
    }
    printf("%d\n", ans);
    return 0;
}