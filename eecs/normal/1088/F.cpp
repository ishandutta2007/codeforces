#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, a[maxn], fa[maxn][20];
long long ans;
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    int rt = min_element(a + 1, a + n + 1) - a;
    function<void(int)> dfs = [&](int u) {
        for (int i = 1; i < 20; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        if (u ^ rt) {
            long long mn = LLONG_MAX;
            for (int i = 0; i < 20; i++) {
                mn = min(mn, a[u] + 1LL * (i + 1) * a[fa[u][i]]);
            }
            ans += mn;
        }
        for (int v : G[u]) if (v ^ fa[u][0]) {
            fa[v][0] = u, dfs(v);
        }
    };
    dfs(fa[rt][0] = rt);
    printf("%lld\n", ans);
    return 0;
}