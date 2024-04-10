#include <bits/stdc++.h>
using namespace std;

const int maxn = 2510, P = 1000000007;
int n, s, ans, a[maxn], f[100010];

int inv(int x) {
    return x <= 1 ? x : -1LL * P / x * inv(P % x) % P;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), s += a[i];
    }
    f[1] = 1LL * (s - 1) * (s - 1) % P * inv(s) % P;
    for (int i = 2; i <= 100000; i++) {
        f[i] = (2LL * f[i - 1] - f[i - 2] - 1LL * (s - 1) * inv(s - i + 1)) % P;
    }
    for (int i = 1; i <= n; i++) {
        (ans += f[a[i]]) %= P;
    }
    printf("%d\n", (ans + P) % P);
    return 0;
}