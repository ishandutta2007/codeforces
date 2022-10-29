#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
const int S = 18;
int n, m;
int fa[N][S+1], dfnl[N], dfnr[N], deep[N], fu[N][S+1];
vector<int> g[N];
vector<int> w[N];
struct node{
    int sum;
    int son[2];
}tr[N * S * 4];
int tot_tr = 0;
int h[N];
void dfs(int x) {//
    static int tot = 0;
    deep[x] ++;
    dfnl[x] = ++tot;
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    for (auto u:g[x])
        if (u != fa[x][0]) {
            fa[u][0] = x;
            deep[u] = deep[x];
            dfs(u);
        }
    dfnr[x] = tot;
}
int up(int x, int y){
    for (int i = S; i >= 0; i --)
        if (y >= (1 << i))
            y -= (1 << i), x = fa[x][i];
    return x;
}
int getlca(int x, int y) {
    if (deep[x] < deep[y])
        swap(x, y);
    x = up(x, deep[x] - deep[y]);
    for (int i = S; i >= 0; i --)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return x != y ? fa[x][0] : x;
}
void upd(int&x, int y) {
    if (!x || deep[x] > deep[y]) x = y;
}
void dfs1(int x) {
    for (auto u:g[x]) {
        dfs1(u);
        if (fu[u][0] && deep[fu[u][0]] < deep[x]) upd(fu[x][0], fu[u][0]);
    }
}
int ins(int l, int r, int s, int ll) {
    int s1 = ++tot_tr;
    tr[s1] = tr[s];
    tr[s1].sum ++;
    if (l == r) return s1;
    if ((l+r)/ 2 >= ll) {
        tr[s1].son[0] = ins(l, (l+r)/2,tr[s].son[0],ll);
    } else {
        tr[s1].son[1] = ins((l+r)/2+1,r,tr[s].son[1],ll);
    }
    return s1;
}
bool have(int l, int r, int s, int s1, int ll, int rr) {
    if (!(tr[s1].sum - tr[s].sum) || r < ll || rr < l) return 0;
    if (ll <= l && r <= rr) return 1;
    return have(l, (l+r)/2,tr[s].son[0], tr[s1].son[0], ll, rr) || have((l+r)/2+1,r,tr[s].son[1], tr[s1].son[1],ll,rr);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++)
    {
        int x;
        scanf("%d", &x);
        g[x].push_back(i + 1);
    }
    dfs(1);
    scanf("%d", &m);
    while (m --) {
        int x, y;
        scanf("%d %d", &x, &y);
        int z = getlca(x, y);
        if (z != x) upd(fu[x][0], z);
        if (z != y) upd(fu[y][0], z);
        w[dfnl[x]].push_back(dfnl[y]);
        w[dfnl[y]].push_back(dfnl[x]);
    }
    dfs1(1);
    for (int i = 0; i < S; i ++)
        for (int j = 1; j <= n; j ++)
            if (fu[j][i] && fu[fu[j][i]][i])
                fu[j][i+1] = fu[fu[j][i]][i];
    for (int i = 1; i <= n; i ++){
        h[i] = h[i - 1];
        for (auto u:w[i])
            h[i] = ins(1, n , h[i], u);
    }
    scanf("%d", &m);
    while (m --) {
        int x, y;
        scanf("%d %d", &x, &y);
        int z = getlca(x, y);
        if (x == z || y == z) {
            if (y == z) swap(x, y);
            int ans = 0;
            for (int i = S; i >= 0; i --)
                while (fu[y][i] && deep[fu[y][i]] > deep[x]) {
                    y = fu[y][i];
                    ans += (1 << i);
                }
            if (fu[y][0]) printf("%d\n", ans + 1);
            else puts("-1");
            continue;
        }
        int ans = 0;
        for (int i = S; i >= 0; i --) {
            while (fu[y][i] && deep[fu[y][i]] > deep[z]) {
                y = fu[y][i];
                ans += (1 << i);
            }
            while (fu[x][i] && deep[fu[x][i]] > deep[z]) {
                x = fu[x][i];
                ans += (1 << i);
            }
        }
        if (!fu[x][0] || !fu[y][0]) {
            puts("-1");
            continue;
        }
        if (have(1, n, h[dfnl[x] - 1], h[dfnr[x]], dfnl[y], dfnr[y]))
            printf("%d\n", ans + 1);
        else
            printf("%d\n", ans + 2);
    }
    return 0;
}