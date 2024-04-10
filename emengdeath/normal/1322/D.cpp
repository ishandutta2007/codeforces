#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 4001;
long long f[N + N][N];
int r[N + N];
int n, m;
int v[N], c[N], p[N + N];
bool bz, bz1;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &v[i]), r[v[i]] ++;
    for (int i = 1; i < n + m; i ++)
        r[i + 1] += (r[i] / 2);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n + m; i ++)
        scanf("%d", &p[i]);
    for (int i = 0; i <= n + m; i ++)
        for (int j = 1; j <= n; j ++)
            f[i][j] = -1e18;
    for (int i = n; i >= 1; i --) {
        for (int k = r[v[i]] - 1; k >= 0; k --)
            if (f[v[i]][k] != -1e18)
            f[v[i]][k + 1] = max(f[v[i]][k + 1], f[v[i]][k] - c[i] + p[v[i]]);
        for (int j = 0; j < n + m; j ++)
            for (int k = 0; k <= r[j]; k ++)
                if (f[j][k] != -1e18)
                f[j + 1][k / 2] = max(f[j + 1][k / 2], f[j][k] + 1ll * k / 2 * p[j + 1]);
    }
    long long ans = 0;
    for (int i = 0; i <= n + m; i ++)
        ans = max(ans, f[i][0]);
    printf("%lld\n", ans);
    return 0;
}