#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, f[maxn][2], a[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 2, p; i <= n; i++) {
        scanf("%d", &p), G[++p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    function<void(int)> dfs = [&](int v) {
        f[v][a[v]] = 1;
        for (int u : G[v]) {
            dfs(u);
            int x = f[v][0], y = f[v][1], p = f[u][0], q = f[u][1];
            f[v][0] = 1LL * x * (p + q) % P;
            f[v][1] = (1LL * x * q + 1LL * y * (p + q)) % P;
        }
    };
    dfs(1), printf("%d\n", f[1][1]);
    return 0;
}