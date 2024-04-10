#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 2000000;
int n, m, k;
int stid;
int tot, stx, sty;
int f[N], Next[N][2], Pre[N][2];
int id(int x, int y) {
    if (x > n || y > m || !x || !y) return 0;
    return (x - 1) * m + y;
}
int loc(int x, int y) {
    int outid = stid;
    while (--x) outid = Next[outid][0];
    while (--y) outid = Next[outid][1];
    return outid;
}
void dfs(int id, int x, int y) {
    if (y == m)
        printf("%d\n", f[id]);
    else {
        printf("%d ", f[id]);
        dfs(Next[id][1], x, y + 1);
        if (y == 1 && x < n)
            dfs(Next[id][0], x + 1, y);
    }
}
void link(int x, int y, bool sig) {
    if (!x) Pre[y][sig] = 0;
    else{
        if (!y) Next[x][sig] = 0;
        else
            Pre[y][sig] = x, Next[x][sig] = y;
    }
}
int main() {
    stid = 1;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <=n; i ++)
        for (int j = 1; j <= m; j ++) {
            scanf("%d", &f[id(i, j)]);
            Next[id(i, j)][0] = id(i+ 1,j);
            Next[id(i, j)][1] = id(i,j+1);
            Pre[id(i, j)][0] = id(i- 1,j);
            Pre[id(i, j)][1] = id(i,j-1);
        }
    while (k --) {
        int x, y, xx, yy, h, w;
        scanf("%d %d %d %d %d %d", &x, &y, &xx, &yy, &h, &w);
        int id1 = loc(x, y);
        int id2 = loc(xx, yy);
        x = id1;
        xx = id2;
        for (int i = 0; i < h; i ++)
        {
            int l = Pre[x][1], ll = Pre[xx][1];
            link(l, xx, 1), link(ll, x, 1);
            if (i != h - 1) {
                x = Next[x][0];
                xx = Next[xx][0];
            }
        }
        for (int i = 0; i < w; i ++) {
            int l = Next[x][0], ll = Next[xx][0];
            link(xx, l, 0), link(x, ll, 0);
            if (i != w - 1) {
                x = Next[x][1];
                xx = Next[xx][1];
            }
        }
        for (int i = 0; i < h; i ++)
        {
            int l = Next[x][1], ll = Next[xx][1];
            link(xx, l, 1), link(x, ll, 1);
            if (i != h - 1) {
                x = Pre[x][0];
                xx = Pre[xx][0];
            }
        }
        for (int i = 0; i < w; i ++) {
            int l = Pre[x][0], ll = Pre[xx][0];
            link(l, xx, 0), link(ll, x, 0);
            if (i != w - 1) {
                x = Pre[x][1];
                xx = Pre[xx][1];
            }
        }
        if (!Pre[x][0] && !Pre[x][1]) {
            stid = x;
        }

        if (!Pre[xx][0] && !Pre[xx][1]) {
            stid = xx;
        }
    }
    dfs(stid, 1, 1);
    return 0;
}