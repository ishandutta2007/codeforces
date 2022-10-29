#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 100001;
const int S = 16;
const int mod = 1e9 + 7;
vector<int> d,g[N];
int fa[N][S +1], deep[N];
bool isp[N];
int tag, bz[N], dfn[N], a[N];
int n, q;
vector<int> edge[N];
vector<int>tmp;
void dfs(int x) {
    static int cnt = 0;
    deep[x] ++;
    dfn[x] = ++cnt;
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    for (auto u:g[x])
        if (u != fa[x][0]) {
            fa[u][0] = x;
            deep[u] = deep[x];
            dfs(u);
        }
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
int k, m, r;
void update(int x) {
    if (bz[x] != tag) {
        edge[x].clear();
        bz[x] = tag;
        isp[x] = 0;
    }
}
void link(int x, int y) {
    update(x), update(y);
    edge[x].push_back(y), edge[y].push_back(x);
}
void add(int x) {//dfs
    if (d.empty()){
        d.push_back(x);
    } else {
        if (getlca(d[d.size() - 1], x) != d[d.size() - 1]) {
            int last = d[d.size() - 1];
            d.pop_back();
            while (!d.empty() && getlca(d[d.size() - 1], x) != d[d.size() - 1]) {
                link(d[d.size() - 1], last);
                last = d[d.size() - 1];
                d.pop_back();
            }
            if (d.empty() || getlca(last, x) != d[d.size() - 1] ) {
                int u = getlca(last, x);
                link(u, last);
                d.push_back(u);
            } else {
                link(d[d.size() - 1], last);
            }
        }
        d.push_back(x);
    }
}
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
void dfs(int x, int fa, int v) {
    if (isp[x])
        tmp.push_back(v);
    for (auto u:edge[x])
        if (u!=fa)
            dfs(u, x, v + isp[x]);
}
int f[2][301];
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    while (q --) {
        scanf("%d %d %d", &k, &m, &r);
        bool own = 0;
        ++tag;
        for (int i = 1; i <=k ; i ++) {
            scanf("%d", &a[i]);
            update(a[i]);
            isp[a[i]] = 1;
            if (a[i] == r) own = 1;
        }
        if (!own) {
            a[++k] =r;
            update(r);
        }
        sort(a+1,a+k+1,[](int x, int y){
            return dfn[x]<dfn[y];
        });
        d.clear();
        for (int i = 1; i <= k; i ++)
            add(a[i]);
        while (d.size() > 1) {
            link(d[d.size() - 2], d[d.size() - 1]);
            d.pop_back();
        }
        tmp.clear();
        dfs(r, 0, 0);
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i <= m; i ++)
            f[0][i] = f[1][i] = 0;
        bool bz = 0, bz1 = 1;
        f[0][0]= 1;
        for (auto u:tmp) {
            for (int j = 0; j <= m ;j ++)
                if (f[bz][j]) {
                    f[bz1][j] = add(f[bz1][j], mul(f[bz][j], max(j - u, 0)));
                    if (j != m)
                        f[bz1][j + 1] = add(f[bz1][j+1], f[bz][j]);
                    f[bz][j] = 0;
                }
            swap(bz, bz1);
        }
        int ans = 0;
        for (int i = 1; i <= m; i ++)
            ans = add(ans, f[bz][i]);
        printf("%d\n", ans);
    }
    return 0;
}