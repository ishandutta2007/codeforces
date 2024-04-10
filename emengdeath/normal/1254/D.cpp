#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 2e5;
int deep[N], sz[N], mxsz[N], d[N];
vector<int>g[N];
bool bz[N];
int fsz[N][20], fson[N][20], c[20], w[N][20], v[N], all[N], allsz[N];
int fa[N];
int n, q;
int ff[20][N * 4], l[N][20], r[N][20], dfn[20];
const int mod = 998244353;
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}

void dfs1(int x, int fa){
    sz[x] = 1;
    d[++d[0]] = x;
    mxsz[x] = 0;
    for (auto u:g[x])
        if (!bz[u] && u != fa) {
            dfs1(u, x);
            sz[x] += sz[u];
            mxsz[x] = max(mxsz[x], sz[u]);
        }
}
int did(int x) {
    return max(mxsz[x], d[0] - sz[x]);
}
int root(int x) {
    d[0] = 0;
    dfs1(x, 0);
    for (int i = 1; i <= d[0]; i ++)
        if (did(d[i]) < did(x)) x = d[i];
    return x;
}
void dfs(int x, int fa, int cnt) {
    fsz[x][cnt] = 1;
    l[x][cnt] = ++dfn[cnt];
    for (auto u:g[x])
        if (u!=fa && !bz[u]) {
            dfs(u, x, cnt);
            fsz[x][cnt] += fsz[u][cnt];
        }
    r[x][cnt] = dfn[cnt];
}
int dfs(int x, int cnt) {
    x = root(x);
    allsz[x] = d[0];
    deep[x] = cnt;
    for (int i = 0; i < cnt; i ++)
        fson[x][i] = c[i];
    dfs(x, 0, cnt);
    bz[x] = 1;
    for (auto u:g[x])
        if (!bz[u]) {
            c[cnt] = u;
            fa[dfs(u, cnt + 1)] = x;
        }
    return x;
}
void ins(int l, int r ,int s, int *f, int ll, int rr ,int v) {
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr)
    {
        f[s] = add(f[s], v);
        return;
    }
    ins(l, (l + r )/ 2 , s + s, f, ll, rr, v);
    ins((l +r)/ 2 + 1, r, s + s + 1, f, ll, rr, v);
}
int get(int l, int r ,int s, int *f, int ll) {
    int v = 0;
    while (1) {
        v = add(v, f[s]);
        if (l == r)return v;
        if ((l + r) / 2 >= ll) r = (l + r )/ 2, s += s;
        else
            l = (l + r) / 2 + 1, s += s + 1;
    }
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; i ++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    int invn = calc(n, mod - 2);
    while (q --) {
        int sig, x;
        scanf("%d %d", &sig, &x);
        if (sig == 1) {
            int y;
            scanf("%d", &y);
            v[x] = add(v[x], mul(y, invn));
            int z = fa[x];
            for (int i = deep[x] - 1; i >= 0; i --) {
                int tmp = mul(invn, mul(fsz[x][i], y));
                w[fson[x][i]][i] = add(w[fson[x][i]][i], tmp);
                all[z] = add(all[z], tmp);
                tmp = mul(invn, mul(sub(allsz[z], fsz[fson[x][i]][i]), y));
                ins(1, dfn[i], 1, ff[i], l[x][i], r[x][i], tmp);
                z = fa[z];
            }
        } else {
            int ans = add(mul(v[x], allsz[x]), all[x]);
            int z = fa[x];
            for (int i = deep[x] - 1; i >= 0; i --, z= fa[z])
                ans = add(add(add(ans, sub(all[z], w[fson[x][i]][i])), get(1, dfn[i], 1, ff[i], l[x][i])), mul(v[z], allsz[z] - fsz[fson[x][i]][i]));
            printf("%d\n", ans);
        }
    }
    return 0;
}