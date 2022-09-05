#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 4010;
int n, m, tot;
ll a[maxn], f[maxn][maxn];

void chk(ll &x, ll y) {
    if (x < y) x = y;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    memset(f, -0x3f, sizeof(f)), f[0][0] = 0;
    function<int(int, int)> solve = [&](int l, int r) {
        if (l > r) return 0;
        int k = ++tot, p = min_element(a + l, a + r + 1) - a;
        int ls = solve(l, p - 1), rs = solve(p + 1, r);
        for (int i = 0; i <= p - l; i++) {
            for (int j = 0; j <= r - p; j++) {
                chk(f[k][i + j], f[ls][i] + f[rs][j] - a[p] * i * j * 2);
                chk(f[k][i + j + 1], f[ls][i] + f[rs][j] + a[p] * (m - 2 * (i + 1) * (j + 1) + 1));
            }
        }
        return k;
    };
    printf("%lld\n", f[solve(1, n)][m]);
    return 0;
}