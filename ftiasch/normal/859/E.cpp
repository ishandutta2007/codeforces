#include <cstdio>

const int N = 200000;
const int MOD = (int)1e9 + 7;

int par[N], sz[N];

int find(int u)
{
    if (par[u] != u) {
        par[u] = find(par[u]);
    }
    return par[u];
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("E.in", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n << 1; ++ i) {
            par[i] = i, sz[i] = 1;
        }
        int result = 1;
        for (int i = 0, aa, bb; i < n; ++ i) {
            scanf("%d%d", &aa, &bb);
            int a = find(aa - 1);
            int b = find(bb - 1);
            if (a == b) {
                if (aa != bb) {
                    result = 2 * result % MOD;
                }
                sz[a] = 0;
            } else {
                if (sz[a] && sz[b]) {
                    sz[a] += sz[b];
                } else {
                    sz[a] = 0;
                }
                par[b] = a;
            }
        }
        for (int i = 0; i < n << 1; ++ i) {
            if (par[i] == i && sz[i]) {
                result = 1LL * result * sz[i] % MOD;
            }
        }
        printf("%d\n", result);
    }
}