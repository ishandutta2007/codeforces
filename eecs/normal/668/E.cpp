#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, m1, m2;

struct {
    int flag, ans[maxn];
    bitset<maxn> b[maxn];

    void dfs(int v) {
        ans[v] = 1, ans[v ^ 1] = 0;
        for (int i = 0; i < n << 1; i++) {
            if (b[v][i] && !~ans[i]) dfs(i);
        }
    }
    void init(int m) {
        for (int i = 0; i < n << 1; i++) {
            b[i][i] = 1;
        }
        while (m--) {
            int u, v; scanf("%d %d", &u, &v);
            u = (abs(u) - 1) << 1 | (u > 0);
            v = (abs(v) - 1) << 1 | (v > 0);
            b[u ^ 1][v] = b[v ^ 1][u] = 1;
        }
        for (int i = 0; i < n << 1; i++) {
            for (int j = 0; j < n << 1; j++) {
                if (b[j][i]) b[j] |= b[i];
            }
        }
        memset(ans, -1, sizeof(ans));
        for (int i = 0; i < n; i++) {
            int x = i << 1, y = i << 1 | 1;
            if (b[x][y] && b[y][x]) { flag = 1; return; }
            if (~ans[x]) continue;
            if (b[x][y]) dfs(y);
            if (b[y][x]) dfs(x);
        }
    }
    void print(int x = -1, int y = -1) {
        if (~x) dfs(x);
        if (~y) dfs(y);
        for (int i = 0; i < n << 1; i++) {
            if (!~ans[i]) dfs(i);
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i << 1 | 1]);
        }
        exit(0);
    }
} G1, G2;

int main() {
    scanf("%d %d %d", &n, &m1, &m2);
    G1.init(m1), G2.init(m2);
    if (G1.flag && G2.flag) puts("SIMILAR"), exit(0);
    if (G1.flag) G2.print();
    if (G2.flag) G1.print();
    for (int i = 0; i < n << 1; i++) {
        if (G1.ans[i] == 1 && !G2.ans[i]) G1.print(i);
        if (G2.ans[i] == 1 && !G1.ans[i]) G2.print(i);
    }
    for (int i = 0; i < n << 1; i++) {
        for (int j = 0; j < n << 1; j++) {
            if (!~G2.ans[i] && !~G2.ans[j] && G1.b[i][j] && !G2.b[i][j]) G2.print(i, j ^ 1);
            if (!~G1.ans[i] && !~G1.ans[j] && G2.b[i][j] && !G1.b[i][j]) G1.print(i, j ^ 1);
        }
    }
    puts("SIMILAR");
    return 0;
}