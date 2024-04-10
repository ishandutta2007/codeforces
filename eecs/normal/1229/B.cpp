#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010, P = 1000000007;
int n, fa[maxn][20], dep[maxn];
ll ans, x[maxn], f[maxn][20];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x[i]);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs = [&](int v) {
        dep[v] = dep[fa[v][0]] + 1;
        f[v][0] = __gcd(x[v], x[fa[v][0]]);
        for (int i = 1; 1 << i < dep[v]; i++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
            f[v][i] = __gcd(f[v][i - 1], f[fa[v][i - 1]][i - 1]);
        }
        for (int u : G[v]) if (u ^ fa[v][0]) {
            fa[u][0] = v, dfs(u);
        }
        int u = v;
        ll cur = x[v];
        while (u) {
            int o = u;
            for (int i = 19; ~i; i--) {
                if (fa[u][i] && (!f[u][i] || cur && !(f[u][i] % cur))) u = fa[u][i];
            }
            (ans += cur % P * (dep[o] - dep[u] + 1)) %= P;
            u = fa[u][0], cur = __gcd(cur, x[u]);
        }
    };
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}