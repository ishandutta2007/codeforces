#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 66, maxm = 260;
int T, n, m, id[maxn][maxn], w[maxn][maxn], ans[maxm];
bool has[maxm];

struct st {
    int a[maxm];
    st() { memset(a, 0, sizeof(a)); }

    void operator += (const st &o) {
        for (int i = 1; i <= m + 1; i++) (a[i] += 3 - o.a[i]) %= 3;
    }
    void flip() {
        for (int i = 1; i <= m + 1; i++) a[i] = (3 - a[i]) % 3;
    }
} b[maxm];

int main() {
    scanf("%d", &T);
    auto ins = [&](st x) {
        for (int i = 1; i <= m + 1; i++) if (x.a[i]) {
            if (x.a[i] == 2) x.flip();
            if (has[i]) x += b[i];
            else { b[i] = x, has[i] = 1; break; }
        }
    };
    while (T--) {
        scanf("%d %d", &n, &m);
        memset(id, 0, sizeof(id));
        memset(w, -1, sizeof(w));
        memset(has, 0, sizeof(has));
        for (int i = 1, u, v, c; i <= m; i++) {
            scanf("%d %d %d", &u, &v, &c);
            id[u][v] = id[v][u] = i, w[u][v] = w[v][u] = c;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) if (id[i][j]) {
                for (int k = j + 1; k <= n; k++) if (id[i][k] && id[j][k]) {
                    st x;
                    x.a[id[i][j]] = x.a[id[i][k]] = x.a[id[j][k]] = 1;
                    ins(x);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) if (~w[i][j]) {
                st x;
                x.a[id[i][j]] = 1, x.a[m + 1] = (w[i][j] - 1) % 3;
                ins(x);
            }
        }
        if (has[m + 1]) { puts("-1"); continue; }
        for (int i = m; i; i--) {
            ans[i] = b[i].a[m + 1];
            for (int j = i + 1; j <= m; j++) {
                ans[i] = (ans[i] - b[i].a[j] * ans[j] % 3 + 3) % 3;
            }
        }
        for (int i = 1; i <= m; i++) {
            printf("%d ", ans[i] + 1);
        }
        putchar('\n');
    }
    return 0;
}