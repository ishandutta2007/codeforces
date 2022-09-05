#include <bits/stdc++.h>
using namespace std;

int n, m, K;
long long ans;

int main() {
    scanf("%d %d %d", &n, &m, &K);
    if (n + m - 2 < K) puts("-1"), exit(0);
    for (int i = 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        if (i - 1 <= K) ans = max(ans, 1LL * n / i * (m / (K - i + 2)));
        int o = K + 1;
        if (o >= i && o <= j) ans = max(ans, 1LL * n / o * (m / (K - o + 2)));
        o = K + 2 - m;
        if (o >= i && o <= j) ans = max(ans, 1LL * n / o * (m / (K - o + 2)));
        if (j - 1 <= K) ans = max(ans, 1LL * n / j * (m / (K - j + 2)));
    }
    printf("%lld\n", ans);
    return 0;
}