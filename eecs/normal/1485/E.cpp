#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int T, n, fa[maxn], dep[maxn], a[maxn];
ll f[maxn], g[maxn];
vector<int> G[maxn], H[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            G[i].clear(), H[i].clear(), f[i] = g[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            scanf("%d", &fa[i]), G[fa[i]].push_back(i);
        }
        for (int i = 2; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        function<void(int)> dfs = [&](int v) {
            H[dep[v]].push_back(v);
            for (int u : G[v]) dep[u] = dep[v] + 1, dfs(u);
        };
        dfs(1);
        int d = *max_element(dep + 1, dep + n + 1);
        for (int i = d; ~i; i--) {
            sort(H[i].begin(), H[i].end(), [&](int u, int v) { return a[u] < a[v]; });
            if (i == d) {
                for (int v : H[i]) {
                    f[v] = max(a[v] - a[H[i][0]], a[H[i].back()] - a[v]);
                }
            } else {
                for (int j : H[i]) for (int k : G[j]) {
                    g[j] = max(g[j], f[k]);
                }
                ll mx = -1e18;
                for (int j = 0; j < H[i].size(); j++) {
                    mx = max(mx, g[H[i][j]] - a[H[i][j]]);
                    f[H[i][j]] = max(f[H[i][j]], mx + a[H[i][j]]);
                }
                mx = -1e18;
                for (int j = H[i].size() - 1; ~j; j--) {
                    mx = max(mx, g[H[i][j]] + a[H[i][j]]);
                    f[H[i][j]] = max(f[H[i][j]], mx - a[H[i][j]]);
                }
                for (int j : H[i]) for (int k : G[j]) {
                    f[j] = max(f[j], f[k] + max(a[j] - a[H[i][0]], a[H[i].back()] - a[j]));
                }
            }
        }
        printf("%lld\n", f[1]);
    }
    return 0;
}