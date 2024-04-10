#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
const int S = 40;
const int mod = 1e9 + 7;
const int N = 1e5 + 1;
struct node{
    int v, sum;
}f[N], w[N][S];
int fa[N], fson[N][S], dis[N][S], ni[N];
int n;
long long ans, v;
vector<int>q[100002], g[100001];
bool bz[100001];
int deep[N];
int all;
int d[100001], sz[100001], mxsz[100001], c[S];
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
    for (auto u:g[x])
        if (u!=fa && !bz[u]) {
            dis[u][cnt] = dis[x][cnt] + 1;
            dfs(u, x, cnt);
        }
}
int dfs(int x, int cnt) {
    x = root(x);
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
int up(int x) {
    long long v = f[x].v;
    int y = fa[x];
    for (int i = deep[x] - 1; i >= 0; i --, y = fa[y]) {
        int z = fson[x][i];
        v = (v + 1ll * (f[y].sum - w[z][i].sum) * dis[x][i] % mod + (f[y].v - w[z][i].v)) % mod;
    }
    return (v + mod) % mod;
}
void did_up(int x, int v) {
    int y = fa[x];
    (f[x].sum += v) %= mod;
    for (int i = deep[x] - 1; i >= 0; i --, y = fa[y]) {
        int z = fson[x][i];
        (w[z][i].sum += v) %= mod;
        (w[z][i].v += 1ll * v * dis[x][i] % mod) %= mod;
        (f[y].sum += v) %= mod;
        (f[y].v += 1ll * v * dis[x][i] % mod) %= mod;
    }
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = 1ll * z * x%mod;
        x = 1ll *x * x % mod, y /= 2;
    }
    return z;
}
int main() {
    scanf("%d", &n);
    all = 1;
    for (int i = 1;i <= n; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        q[x].push_back(i);
        q[y + 1].push_back(-i);
        all = 1ll * all * (y - x + 1) % mod;
        ni[i] = calc(y - x + 1, mod - 2);
    }
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= 100000; i ++, (ans += v) %= mod)
        for (auto u:q[i]) {
            if (u > 0) {
                (v += 1ll * up(u) * all % mod * ni[u] % mod) %= mod;
                did_up(u, ni[u]);
            } else {
                did_up(-u, mod - ni[-u]);
                (v += mod - 1ll * up(-u) * all % mod * ni[-u] % mod) %= mod;
            }
        }
    printf("%lld\n", ans);
    return 0;
}