#include <bits/stdc++.h>
using namespace std;

const int maxn = 410, P = 1000000007;
int n, f[maxn][maxn];

int F(int n, int k) {
    if (~f[n][k]) return f[n][k];
    if (!k) return 1;
    if (n == 1) return k == 1;
    int s = 0;
    for (int i = 0; i <= k + 1; i++) {
        if (i <= k) s = (s + 1LL * F(n - 1, i) * F(n - 1, k - i)) % P;
        if (i < k) s = (s + 1LL * F(n - 1, i) * F(n - 1, k - i - 1)) % P;
        if (i <= k) s = (s + 1LL * F(n - 1, i) * F(n - 1, k - i) % P * (2 * k)) % P;
        s = (s + 1LL * F(n - 1, i) * F(n - 1, k - i + 1) % P * (k * (k + 1))) % P;
    }
    return f[n][k] = s;
}

int main() {
    scanf("%d", &n);
    memset(f, -1, sizeof(f));
    printf("%d\n", F(n, 1));
    return 0;
}