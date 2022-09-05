#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, l[maxn], r[maxn];
vector<int> G[maxn];
long long f[maxn][2];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &l[i], &r[i]), G[i].clear();
            f[i][0] = f[i][1] = 0;
        }
        for (int i = 1, u, v; i < n; i++) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v), G[v].push_back(u);
        }
        function<void(int, int)> dfs = [&](int v, int fa) {
            for (int u : G[v]) if (u ^ fa) {
                dfs(u, v);
                f[v][0] += max(f[u][0] + abs(l[u] - l[v]), f[u][1] + abs(r[u] - l[v]));
                f[v][1] += max(f[u][0] + abs(l[u] - r[v]), f[u][1] + abs(r[u] - r[v]));
            }
        };
        dfs(1, 0);
        printf("%lld\n", max(f[1][0], f[1][1]));
    }
    return 0;
}