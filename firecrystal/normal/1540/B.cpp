// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 205, P = 1e9 + 7;

int d[N];

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

int n, sz[N], dfn[N], dfncnt, fa[N], ans, f[N][N], h[N][N];

int di[N][N];

vector<int> g[N];

void dfs(int u) {
    sz[u] = 1, dfn[u] = ++dfncnt;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa[u]) continue;
        fa[v] = u, d[v] = d[u] + 1; 
        dfs(v);
        sz[u] += sz[v];
    }
}

int cnt;

bool vis[N], st[N];

int inline lca(int x, int y) {
    vis[x] = vis[y] = 1;
    while (x != y) {
        if (d[x] < d[y]) swap(x, y);
        x = fa[x]; vis[x] = 1;
    }
    return x;
}

int inline dis(int x, int y) {
    return d[x] + d[y] - 2 * d[lca(x, y)];
}

int inline getSZ(int x, int y) {
    int t = sz[x];
    if (dfn[x] <= dfn[y] && dfn[y] <= dfn[x] + sz[x] - 1) {
        int p = y;
        while (fa[p] != x) p = fa[p];
        t = n - sz[p];
    }
    return t;
}


int inv2 = power(2, P - 2);
void inline work(int n) {
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++) f[0][i] = 1;
    for (int l = n; l; l--) {
        for (int i = 1, j; (j = i + l - 1) <= n; i++) {
            f[i][j] = (LL)inv2 * (f[i - 1][j] + f[i][j + 1]) % P;
        }
    }
    for (int i = 1; i <= n; i++) {
        h[n][i] = f[i][i];
    }
}

void dfs2(int u) {
    st[u] = 1; ++cnt;
    for (int v: g[u]) {
        if (vis[v] || st[v]) continue;
        dfs2(v);
    }
}
 
int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        work(i);
    }
    for (int i = 1, u, v; i < n; i++) {
        read(u), read(v);
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            di[i][j] = dis(i, j);
        }
    }
    
    int invN = power(n, P - 2);
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y < x; y++) {
            memset(vis, 0, sizeof vis);
            memset(st, 0, sizeof st);
            int t = getSZ(x, y), t2 = getSZ(y, x);
            add(ans, (LL)invN * t % P);
            int D = dis(x, y);
            for (int i = 1; i <= n; i++) {
                if (i == x || i == y || !vis[i]) continue;
                cnt = 0;
                dfs2(i);
                add(ans, (LL)invN * cnt % P * h[D - 1][di[x][i]] % P);
            }
        }
    }
    print(ans);
	return 0;
}