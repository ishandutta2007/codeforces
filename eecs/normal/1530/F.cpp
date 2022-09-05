#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;

const int P = 31607;
int n, ans, a[21][21], mark[21][21], inv[P], f[21];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = x * x % P) {
        if (y & 1) z = z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    int inv10000 = qp(10000, P - 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            a[i][j] = a[i][j] * inv10000 % P;
        }
    }
    for (int i = 1; i < P; i++) {
        inv[i] = qp(i, P - 2);
    }
    for (int main : {0, 1}) for (int anti : {0, 1}) {
        memset(mark, 0, sizeof(mark));
        int prod = P - 1;
        if (main) {
            prod = P - prod;
            for (int i = 0; i < n; i++) {
                if (!mark[i][i]++) prod = 1LL * prod * a[i][i] % P;
            }
        }
        if (anti) {
            prod = P - prod;
            for (int i = 0; i < n; i++) {
                if (!mark[i][n - i - 1]++) prod = prod * a[i][n - i - 1] % P;
            }
        }
        for (int i = 0; i < n; i++) {
            f[i] = 1;
            for (int j = 0; j < n; j++) {
                if (!mark[j][i]) f[i] = f[i] * a[j][i] % P;
            }
        }
        function<void(int, int)> dfs = [&](int cur, int coef) {
            if (cur == n) {
                int sum = coef;
                for (int i = 0; i < n; i++) {
                    sum = sum * (P + 1 - f[i]) % P;
                }
                (ans += sum) %= P; return;
            }
            dfs(cur + 1, coef);
            for (int i = 0; i < n; i++) if (!mark[cur][i]++) {
                coef = 1LL * coef * a[cur][i] % P;
                f[i] = 1LL * f[i] * inv[a[cur][i]] % P;
            }
            dfs(cur + 1, P - coef);
            for (int i = 0; i < n; i++) if (!--mark[cur][i]) {
                f[i] = 1LL * f[i] * a[cur][i] % P;
            }
        };
        dfs(0, prod);
    }
    printf("%d\n", (ans + 1) % P);
    return 0;
}