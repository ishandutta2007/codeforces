#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 610;
int n, m, e[maxn][maxn], pre[maxn][maxn], f[maxn][maxn], perm[maxn];

int read() {
    int x = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x;
}

mt19937 rnd(time(0));

int main() {
    n = read(), m = read();
    // n = 600, m = n * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            e[i][j] = pre[i][j] = f[i][j] = 2e9;
        }
    }
    while (m--) {
        int a = read(), b = read(), c = read();
        // int a = rand() % n, b = rand() % n, c = rand() * rand() % 1000000000 + 1;
        e[a][b] = c;
    }
    for (int i = 0; i < n; i++) {
        f[i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) pre[i][j] = pre[i][j - 1];
            pre[i][j] = min(pre[i][j], e[i][j] - j);
            for (int k = 0; k < n; k++) {
                f[i][j] = min(f[i][j], (j - k + n) % n + e[i][k]);
            }
        }
    }
    while (1) {
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                int foo = f[i][k];
                for (int j = 0; j < n; j++) if (f[i][j] > foo) {
                    int r = foo % n, bar = INT_MAX;
                    if (j >= r) bar = min(bar, j - r + pre[k][j - r]);
                    else bar = min(bar, 2 * n + j - r + pre[k][min(n - 1, j + 2 * n - r)]);
                    bar = min(bar, n + j - r + pre[k][min(n - 1, j + n - r)]);
                    if (foo + bar < f[i][j]) f[i][j] = foo + bar, flag = 1;
                }
            }
        }
        if (!flag) break;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%c", f[i][j], " \n"[j == n - 1]);
        }
    }
    return 0;
}