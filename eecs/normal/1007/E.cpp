#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 210;
int n, T, K, a[maxn];
ll b[maxn], sa[maxn], sb[maxn], c[maxn], f[maxn][maxn][2], g[maxn][maxn][2];

void chk(ll &x, ll y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d %d %d", &n, &T, &K), n++;
    for (int i = 1; i <= n; i++) {
        if (i < n) scanf("%d %lld %lld", &a[i], &b[i], &c[i]);
        else a[i] = b[i] = INT_MAX, c[i] = 1e18;
        sa[i] = sa[i - 1] + a[i], sb[i] = sb[i - 1] + b[i];
    }
    memset(f, 0x3f, sizeof(f)), memset(f[0], 0, sizeof(f[0]));
    memset(g, 0x3f, sizeof(g)), memset(g[0], 0, sizeof(g[0]));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= T; j++) for (int z : {0, 1}) {
            if (f[i - 1][j][z] < 1e18 && z * a[i] + j * b[i] <= c[i]) {
                chk(f[i][j][z], f[i - 1][j][z]);
                ll num = (z * sa[i - 1] + j * sb[i - 1] + K - 1) / K;
                if (num * K <= z * sa[i] + j * sb[i]) chk(g[i][j][z], num);
            }
            for (int r = 0; r < j; r++) if (g[i][r][z] < 1e18) {
                ll rem = z * sa[i] + r * sb[i] - K * g[i][r][z];
                ll need = (max(0LL, rem + (j - r) * b[i] - c[i]) + K - 1) / K;
                if (need * K > rem || f[i - 1][j - r][0] > 1e18) continue;
                chk(f[i][j][z], g[i][r][z] + need + f[i - 1][j - r][0]);
                ll num = ((j - r) * sb[i - 1] + K - 1) / K;
                if (num * K <= rem + (j - r) * sb[i] - need * K) chk(g[i][j][z], g[i][r][z] + need + num);
            }
        }
    }
    printf("%lld\n", f[n][T][1]);
    return 0;
}