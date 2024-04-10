#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3e5 * 2 + 10;
int e[N][3];
int sig[N];
int sum[N * 2];
int fa[N * 2];
bool active[N];
int ans;
int n, m;
char s[N];
int gg[N], Next[N* 6][2];
int f[N];
int tot;
void add(int x, int y) {
    Next[++tot][0] = y;
    Next[tot][1] = gg[x];
    gg[x] = tot;
}
void addf(int x, int y) {
    Next[++tot][0] = y;
    Next[tot][1] = f[x];
    f[x] = tot;
}
int getfa(int x) {
    return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}
int rev(int x) {
    if (x <= m) return x + m;
    else
        return x;
}
void did(int x, int v) {
    ans += v * min(sum[getfa(x)], sum[getfa(rev(x))]);
}
int ffa;
int d[N];
void dfs1(int x) {
    if (sig[x]) return;
    d[0] = 1;
    d[1] = x;
    sig[x] = ((getfa(x) == ffa) ^ 1) + 1;
    ans += (getfa(x) == ffa);
    for (int i = 1; i <= d[0]; i ++) {
        for (int j = gg[d[i]]; j; j = Next[j][1]) {
            if (!sig[Next[j][0]]) {
                d[++d[0]] = Next[j][0];
                sig[Next[j][0]] = ((getfa(Next[j][0]) == ffa) ^ 1) + 1;
                ans += (getfa(Next[j][0]) == ffa);
            }
        }
        if (getfa(d[i]) == ffa)
            for (int j = f[d[i]]; j; j = Next[j][1])
                s[Next[j][0]] ^= 1;
    }
}
void merge(int x, int y) {
    x = getfa(x);
    y = getfa(y);
    if (x != y) {
        fa[x] = y;
        sum[y] += sum[x];
        sum[x] = 0;
    }
}
int main() {
    scanf("%d %d", &n, &m);
    scanf("%s", s+1);
    for (int i= 1; i <= n; i ++) s[i] -= '0';
    for (int i = 1; i <= m; i ++) {
        int k;
        scanf("%d", &k);
        while (k --) {
            int x;
            scanf("%d", &x);
            addf(i, x);
            e[x][e[x][2] ++] = i;
        }
    }
    for (int i = 1; i<=m ; i ++) fa[i] = i, fa[m+ i] = m + i, sum[i] = 1;
    //  if (n == 285025) return 0;
    for (int i = 1; i <= n; i ++, printf("%d\n", ans)) {
        if (e[i][2]) {
            if (e[i][2] == 2) {
                int x = getfa(e[i][0]), y = getfa(e[i][1]);
                int xx = getfa(rev(e[i][0])), yy = getfa(rev(e[i][1]));
                if ((sig[e[i][0]] > 0) ^ (sig[e[i][1]] > 0) ) {
                    if (active[e[i][0]] && !sig[e[i][0]])
                        did(e[i][0], -1);
                    if (active[e[i][1]] && !sig[e[i][1]])
                        did(e[i][1], -1);
                    if (sig[e[i][0]]) {
                        if ((sig[e[i][0]] == 1) ^ (s[i])) {
                            merge(x, y);
                            merge(xx, yy);
                        } else {
                            merge(x, yy);
                            merge(xx, y);
                        }
                        ffa = getfa((sig[e[i][0]] - 1) * m + e[i][0]);
                        dfs1(e[i][1]);
                    } else {
                        if ((sig[e[i][1]] == 1) ^ (s[i])) {
                            merge(x, y);
                            merge(xx, yy);
                        } else {
                            merge(x, yy);
                            merge(xx, y);
                        }
                        ffa = getfa((sig[e[i][1]] - 1) * m + e[i][1]);
                        dfs1(e[i][0]);
                    }
                } else if (!sig[e[i][0]]) {
                    if (active[e[i][0]] && !sig[e[i][0]])
                        did(e[i][0], -1);
                    if (active[e[i][1]] && x != y && x != yy &&!sig[e[i][1]])
                        did(e[i][1], -1);
                    if (s[i]) {
                        merge(x, y);
                        merge(xx, yy);
                    } else {
                        merge(x, yy);
                        merge(xx, y);
                    }
                    add(e[i][0], e[i][1]);
                    add(e[i][1], e[i][0]);
                    did(e[i][0], 1);
                }
            } else {
                if (active[e[i][0]] && !sig[e[i][0]])
                    did(e[i][0], -1);
                if (!s[i]) {
                    ffa = getfa(e[i][0]);
                    dfs1(e[i][0]);
                } else {
                    ffa = getfa(e[i][0] + m);
                    dfs1(e[i][0]);
                }
            }
        }
        for (int j = 0; j < e[i][2]; j ++)
            active[e[i][j]] = 1;
    }
    return 0;
}