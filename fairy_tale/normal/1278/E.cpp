#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int maxn = 5e5 + 5;
const int mod = 1e9 + 7;

vector<int> g[maxn];
int sz[maxn];
P f[maxn];

void dfs(int u, int fa) {
    for(auto v:g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    sz[u]++;
}

void solve(int u, int fa, int l, int r) {
    int d = g[u].size() - (fa != 0);
    if(f[u].fi) {
        f[u].se = r - d;
        int sr = r - d;
        r = r - d - 1;
        for(auto v:g[u]) {
            if(v == fa) continue;
            f[v].se = ++sr;
            solve(v, u, r - sz[v] * 2 + 2, r);
            r = r - sz[v] * 2 + 1;
        }
    } else {
        f[u].fi = l + d;
        int sl = l + d;
        l = l + d + 1;
        for(auto v:g[u]) {
            if(v == fa) continue;
            f[v].fi = --sl;
            solve(v, u, l, l + sz[v] * 2 - 2);
            l = l + sz[v] * 2 - 1;
        }
    }
}

int main() {
    int n;
    LL d = 0;
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    f[1].fi = 1;
    solve(1, 0, 2, n * 2);
    for(int i = 1;i <= n; ++i) printf("%d %d\n", f[i].fi, f[i].se);
    return 0;
}