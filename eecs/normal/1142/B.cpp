#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, q, pos[maxn], p[maxn], mp[maxn], a[maxn], lst[maxn], L[20][maxn];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]), mp[p[i]] = i - 1;
    }
    for (int i = 1, x; i <= m; i++) {
        scanf("%d", &x), a[i] = mp[x];
        L[0][i] = lst[(a[i] - 1 + n) % n], lst[a[i]] = i;
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= m; j++) {
            L[i][j] = L[i - 1][L[i - 1][j]];
        }
    }
    for (int i = 1; i <= m; i++) {
        int j = i;
        for (int k = 0; k < 20; k++) {
            if ((n - 1) >> k & 1) j = L[k][j];
        }
        pos[i] = max(pos[i - 1], j);
    }
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        putchar(pos[r] >= l ? '1' : '0');
    }
    return 0;
}