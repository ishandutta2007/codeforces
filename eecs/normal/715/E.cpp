#include <bits/stdc++.h>
using namespace std;

const int maxn = 255, P = 998244353;
int n, p[maxn], q[maxn], pre[maxn], nxt[maxn], vis[maxn];
int S[maxn][maxn], A[maxn][maxn], C[maxn][maxn], fact[maxn];
int f0[maxn], f[maxn], g0[maxn], g[maxn], h[maxn], tmp[maxn], ans[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = S[0][0] = fact[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        for (int j = 1; j <= i; j++) {
            S[i][j] = (S[i - 1][j - 1] + 1LL * (i - 1) * S[i - 1][j]) % P;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = C[i][0] = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
        }
    }
    fill(pre + 1, pre + n + 1, -1);
    fill(nxt + 1, nxt + n + 1, -1);
    int c00 = 0, c01 = 0, c10 = 0, cir = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &q[i]);
        nxt[p[i]] = q[i], pre[q[i]] = p[i];
        if (!p[i] && !q[i]) c00++;
    }
    for (int i = 1; i <= n; i++) if (~nxt[i] && !~pre[i]) {
        int j = i;
        while (j && ~nxt[j]) j = nxt[j];
        if (!j) c10++;
    }
    for (int i = 1; i <= n; i++) if (!~nxt[i] && ~pre[i]) {
        int j = i;
        while (j && ~pre[j]) j = pre[j];
        if (!j) c01++;
    }
    for (int i = 1; i <= n; i++) if (!pre[i]) {
        int j = i;
        while (j && ~nxt[j]) j = nxt[j];
        if (!j) c00++;
    }
    for (int i = 1; i <= n; i++) if (nxt[i] > 0 && !vis[i]) {
        int j = nxt[i]; vis[j] = 1;
        while (i ^ j && j && nxt[j] > 0) vis[j = nxt[j]] = 1;
        if (i == j) cir++;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            A[i][j] = 1LL * C[i][j] * fact[j] % P;
        }
    }
    for (int i = 0; i <= c01; i++) {
        for (int j = i; j <= c01; j++) {
            f0[i] = (f0[i] + 1LL * S[j][i] * C[c01][j] % P * A[c01 + c00 - j][c01 - j]) % P;
        }
    }
    for (int i = 0; i <= c01; i++) {
        for (int j = i; j <= c01; j++) {
            f[i] = (f[i] + 1LL * f0[j] * ((j - i) & 1 ? P - 1 : 1) % P * C[j][i]) % P;
        }
    }
    for (int i = 0; i <= c10; i++) {
        for (int j = i; j <= c10; j++) {
            g0[i] = (g0[i] + 1LL * S[j][i] * C[c10][j] % P * A[c10 + c00 - j][c10 - j]) % P;
        }
    }
    for (int i = 0; i <= c10; i++) {
        for (int j = i; j <= c10; j++) {
            g[i] = (g[i] + 1LL * g0[j] * ((j - i) & 1 ? P - 1 : 1) % P * C[j][i]) % P;
        }
    }
    for (int i = 0; i <= c00; i++) {
        h[i] = 1LL * fact[c00] * S[c00][i] % P;
    }
    for (int i = 0; i <= c01; i++) {
        for (int j = 0; j <= c10; j++) {
            tmp[i + j] = (tmp[i + j] + 1LL * f[i] * g[j]) % P;
        }
    }
    for (int i = 0; i <= c01 + c10; i++) {
        for (int j = 0; j <= c00; j++) {
            ans[i + j] = (ans[i + j] + 1LL * tmp[i] * h[j]) % P;
        }
    }
    for (int k = 0; k < n; k++) {
        int i = n - k - cir;
        printf("%d ", i < 0 ? 0 : ans[i]);
    }
    return 0;
}