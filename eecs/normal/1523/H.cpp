#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 20010, K = 31;
int n, q, a[maxn], lg[maxn], f[15][maxn][K], g[K], h[K];
pair<int, int> st[15][maxn];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        st[0][i] = make_pair(min(i + a[i], n), i);
        if (i > 1) lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 1; i < 15; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    auto opt = [&](int l, int r) {
        int k = lg[r - l + 1];
        return max(st[k][l], st[k][r - (1 << k) + 1]).second;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < K; j++) f[0][i][j] = min(i + a[i] + j, n);
    }
    for (int i = 1; i < 15; i++) for (int j = 1; j <= n; j++) {
        for (int k = 0; k < K; k++) for (int l = 0; l <= k; l++) {
            f[i][j][k] = max(f[i][j][k], f[i - 1][opt(j, f[i - 1][j][l])][k - l]);
        }
    }
    while (q--) {
        int l, r, k, ans = 0;
        scanf("%d %d %d", &l, &r, &k);
        fill(g, g + k + 1, l);
        for (int i = 14; ~i; i--) {
            copy(g, g + k + 1, h);
            for (int j = k; ~j; j--) {
                for (int a = k - j, p = opt(l, g[j]); ~a; a--) {
                    g[j + a] = max(g[j + a], f[i][p][a]);
                }
            }
            if (g[k] >= r) copy(h, h + k + 1, g);
            else ans |= 1 << i;
        }
        printf("%d\n", ans + (l != r));
    }
    return 0;
}