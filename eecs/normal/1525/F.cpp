#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int n, m, K, x[maxn], y[maxn], pre[maxn][maxn], num[maxn];
long long f[maxn][maxn];
int C, lnk[maxn], vis[maxn], _lnk[maxn], chk[2][maxn];
vector<int> ans, G[maxn];

int main() {
    scanf("%d %d %d", &n, &m, &K);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }
    for (int i = 1; i <= K; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    function<int(int)> match = [&](int v) {
        for (int u : G[v]) if (!vis[u]) {
            vis[u] = 1;
            if (!lnk[u] || match(lnk[u])) { lnk[u] = v; return 1; }
        }
        return 0;
    };
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (match(i)) C++;
    }
    for (int i = 1; i <= n; i++) {
        if (lnk[i]) _lnk[lnk[i]] = i;
    }
    function<void(int)> dfs = [&](int v) {
        chk[0][v] = 1;
        for (int u : G[v]) if (!chk[1][u]) {
            chk[1][u] = 1, dfs(lnk[u]);
        }
    };
    for (int i = 1; i <= n; i++) {
        if (!_lnk[i]) dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        if (_lnk[i] && !chk[0][i]) ans.push_back(i);
        if (lnk[i] && chk[1][i]) ans.push_back(-i);
    }
    memset(f, -0x3f, sizeof(f)), f[0][0] = 0;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j <= C; j++) {
            for (int k = 0; j + k <= C; k++) if (C - j - k < n - i) {
                long long v = f[i - 1][j] + max(0LL, x[i] - 1LL * k * y[i]);
                if (v > f[i][j + k]) f[i][j + k] = v, pre[i][j + k] = k;
            }
        }
    }
    int cnt = K;
    for (int i = K, j = max_element(f[K], f[K] + C + 1) - f[K]; i; j -= pre[i--][j]) {
        cnt += num[i] = pre[i][j];
    }
    printf("%d\n", cnt);
    for (int i = 1, j = 0; i <= K; i++) {
        while (num[i]--) printf("%d ", ans[j++]);
        printf("0 ");
    }
    return 0;
}