#include <bits/stdc++.h>
using namespace std;
int rht[25][360], out[25][360];
int fa[25 * 360];
int gf(int a) { return fa[a] == a ? a : fa[a] = gf(fa[a]); }
int id(int x, int y) {
    return x * 360 + y;
}
void merge(int x, int y) {
    fa[gf(x)] = gf(y);
}
void rmain() {
    memset(rht, 0, sizeof rht);
    memset(out, 0, sizeof out);
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= 20; i++)
        for (int j = 0; j < 360; j++) fa[id(i, j)] = id(i, j);
    for (int i = 1; i <= n; i++) {
        char s[10];
        scanf("%s", s);
        if (s[0] == 'C') {
            int r, t1, t2;
            scanf("%d%d%d", &r, &t1, &t2);
            for (int i = t1; i != t2; i = (i + 1) % 360) {
                out[r - 1][i] = 1;
            }
        }
        else {
            int r1, r2, t;
            scanf("%d%d%d", &r1, &r2, &t);
            t = (t + 359) % 360;
            for (int i = r1; i < r2; i++) rht[i][t] = 1;
        }
    }
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 360; j++) if (!out[i][j]) merge(id(i, j), id(i + 1, j));
    for (int i = 0; i <= 20; i++)
        for (int j = 0; j < 360; j++) if (!rht[i][j]) merge(id(i, j), id(i, (j + 1) % 360));
    puts(gf(id(0, 0)) == gf(id(20, 0)) ? "YES" : "NO");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}