#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010, P = 1000000007;
int n, K, a, b, ans, f[maxn], g[maxn];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d %d %d %d", &n, &a, &b, &K);
    f[a] = 1;
    while (K--) {
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= n; i++) if (f[i]) {
            int t = abs(i - b) - 1;
            red(g[max(1, i - t)] += f[i] - P);
            red(g[min(n + 1, i + t + 1)] -= f[i]);
            red(g[i] -= f[i]);
            red(g[i + 1] += f[i] - P);
        }
        for (int i = 1; i <= n; i++) {
            red(g[i] += g[i - 1] - P);
        }
        swap(f, g);
    }
    for (int i = 1; i <= n; i++) {
        red(ans += f[i] - P);
    }
    printf("%d\n", ans);
    return 0;
}