#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e7;
const int S = 17;
int fa[N][S + 1], deep[N];
int n, m;
vector<int>g[N], e[N];
vector<int> w[N * 10];
vector<pair<pair<int, int>, int> > q[N * 10];
int a[M + 1], p[M + 1], ans[N], v[N], dfn[N], uf[N];
int tto[M + 1], ov[N * 10], cnt;
void dfs(int x) {//
    static int cnt = 0;
    deep[x] ++;
    dfn[x] =++cnt;
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
vector<int> d;
void link(int x, int y ){
    e[x].push_back(y);
}
void add(int x) {
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
void dfs(int x, int vv) {
    uf[x] += (v[x] % vv == 0);
    for (auto u:e[x])
    {
        uf[u] = uf[x];
        dfs(u, vv);
    }
    e[x].clear();
}
int mod = 1e9 + 7;
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

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n ; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 2; i <= M; i ++) {
        if (!a[i])
            p[a[i] = ++ p[0]] = i;
        for (int j = 1; 1ll * p[j] * i <= M && j <= a[i]; j ++)
            a[p[j] * i] = j;
    }
    for (int i = 1; i <= n; i ++)
        scanf("%d", &v[i]);
    dfs(1);
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        ans[i] = 1;
        while (z != 1) {
            int zz = p[a[z]];
            int zzz = 1;
            while (z % zz == 0) {
                zzz *= zz;
                z /= zz;
                if (!tto[zzz]) {
                    ov[tto[zzz] = ++cnt] = zzz;
                }
                q[tto[zzz]].push_back({{x, y}, i});
                w[tto[zzz]].push_back(x);
                w[tto[zzz]].push_back(y);
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        int z = v[i];
        while (z != 1) {
            int zz = p[a[z]];
            int zzz = 1;
            while (z % zz == 0) {
                zzz *= zz;
                z /= zz;
                if (!tto[zzz]) continue;
                w[tto[zzz]].push_back(i);
            }
        }
    }
    for (int i = 1; i <= cnt; i ++)
        if (q[i].size()) {
            sort(w[i].begin(), w[i].end(), [](int a, int b) {
                return dfn[a] < dfn[b];
            });
            d.clear();
            for (int j = 0; j < w[i].size(); j ++)
                if (!j || w[i][j] != w[i][j  - 1])
                    add(w[i][j]);
            for (int j = 0; j + 1 < d.size();  j++)
                link(d[j], d[j + 1]);
            uf[d[0]] = 0;
            dfs(d[0], ov[i]);
            for (auto u:q[i]) {
                int lca = getlca(u.first.first, u.first.second);
                ans[u.second] = mul(ans[u.second], calc(p[a[ov[i]]], uf[u.first.first] + uf[u.first.second] - uf[lca] * 2 + (v[lca] % ov[i] == 0)));
            }
        }
    for (int i  =1; i <= m; i ++)
        printf("%d\n", ans[i]);
    return 0;
}