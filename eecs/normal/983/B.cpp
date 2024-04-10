#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int n, q, a[maxn], f[maxn][maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), f[i][i] = a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = len; r <= n; l++, r++) {
            f[l][r] = f[l][r - 1] ^ f[l + 1][r];
        }
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = len; r <= n; l++, r++) {
            f[l][r] = max({f[l][r], f[l][r - 1], f[l + 1][r]});
        }
    }
    scanf("%d", &q);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", f[l][r]);
    }
    return 0;
}