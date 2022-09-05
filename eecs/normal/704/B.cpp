#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5010;
int n, s, e, x[maxn], a[maxn], b[maxn], c[maxn], d[maxn], p[maxn];
ll f[maxn][maxn];

void chk(ll &x, ll y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d %d %d", &n, &s, &e);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] += x[i];
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]), b[i] -= x[i];
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]), c[i] += x[i];
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]), d[i] -= x[i];
    memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) if (f[i - 1][j] < 1e18) {
            if (i == s) {
                chk(f[i][j], f[i - 1][j] + c[i]);
                chk(f[i][j + 1], f[i - 1][j] + d[i]);
                continue;
            }
            if (i == e) {
                chk(f[i][j], f[i - 1][j] + a[i]);
                chk(f[i][j + 1], f[i - 1][j] + b[i]);
                continue;
            }
            if (j > 1 || i < e) chk(f[i][j], f[i - 1][j] + a[i] + d[i]);
            if (j > 1 || i < s) chk(f[i][j], f[i - 1][j] + b[i] + c[i]);
            if (j) chk(f[i][j - 1], f[i - 1][j] + a[i] + c[i]);
            if (j > 1 || i < s || i < e) chk(f[i][j + 1], f[i - 1][j] + b[i] + d[i]);
        }
        f[i][0] = 1e18;
    }
    printf("%lld\n", f[n][1]);
    return 0;
}