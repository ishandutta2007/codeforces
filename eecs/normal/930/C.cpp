#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, ans, a[maxn], f[maxn], g[maxn], c1[maxn], c2[maxn];

void upd(int *c, int p, int v) {
    for (p++; p <= m + 1; p += p & -p) c[p] = max(c[p], v);
}

int query(int *c, int p) {
    int mx = 0;
    for (p++; p; p -= p & -p) mx = max(mx, c[p]);
    return mx;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, l, r; i <= n; i++) {
        scanf("%d %d", &l, &r);
        a[l]++, a[r + 1]--;
    }
    for (int i = 1; i <= m; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        f[i] = query(c1, a[i]) + 1;
        upd(c1, a[i], f[i]);
    }
    for (int i = m; i; i--) {
        g[i] = query(c2, a[i]) + 1;
        upd(c2, a[i], g[i]);
    }
    for (int i = 1; i <= m; i++) {
        ans = max(ans, f[i] + g[i] - 1);
    }
    printf("%d\n", ans);
    return 0;
}