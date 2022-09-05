#include <bits/stdc++.h>
using namespace std;

const int maxn = 52;
int n, h, m, f[maxn][maxn][maxn];
struct node { int l, r, x, c; } a[maxn];

int main() {
    scanf("%d %d %d", &n, &h, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &a[i].l, &a[i].r, &a[i].x, &a[i].c);
    }
    memset(f, -1, sizeof(f));
    function<int(int, int, int)> solve = [&](int l, int r, int h) {
        if (l > r || h < 0) return 0;
        if (~f[l][r][h]) return f[l][r][h];
        int ans = solve(l, r, h - 1);
        for (int i = l; i <= r; i++) {
            int mx = h * h + solve(l, i - 1, h - 1) + solve(i + 1, r, h);
            for (int j = 1; j <= m; j++) {
                if (a[j].l >= l && a[j].l <= i && a[j].r <= r && a[j].r >= i && h > a[j].x) mx -= a[j].c;
            }
            ans = max(ans, mx);
        }
        return f[l][r][h] = ans;
    };
    printf("%d\n", solve(1, n, h));
    return 0;
}