#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010, P = 1000000007;
int n, D, ans, inv[maxn], f[maxn][maxn], g[maxn][maxn];
vector<int> G[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &D);
    for (int i = 1; i <= n + 1; i++) {
        inv[i] = qp(i, P - 2);
    }
    for (int i = 2, fa; i <= n; i++) {
        scanf("%d", &fa), G[fa].push_back(i);
    }
    function<void(int)> dfs = [&](int v) {
        fill(f[v] + 1, f[v] + n + 2, 1);
        for (int u : G[v]) {
            dfs(u);
            for (int i = 1; i <= n + 1; i++) f[v][i] = 1LL * f[v][i] * g[u][i] % P;
        }
        for (int i = 1; i <= n + 1; i++) g[v][i] = (g[v][i - 1] + f[v][i]) % P;
    };
    dfs(1);
    for (int i = 1, s = 0; i <= n + 1; i++) {
        (s += f[1][i]) %= P;
        int prod = 1;
        for (int j = 1; j <= n + 1; j++) if (i ^ j) {
            prod = 1LL * prod * (D - j + P) % P * (i > j ? inv[i - j] : P - inv[j - i]) % P;
        }
        ans = (ans + 1LL * s * prod) % P;
    }
    printf("%d\n", ans);
    return 0;
}