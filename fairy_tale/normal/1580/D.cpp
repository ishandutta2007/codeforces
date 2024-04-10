#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int a[4005], sz[4005];
LL f[4005][4005], tmp[4005];
vector<P> g[4005];

int build(int l, int r)
{
    if (l == r) {
        return l;
    }

    int u = l, v;
    for (int i = l; i <= r; i++) {
        if (a[i] < a[u]) u = i;
    }

    if (u != l) {
        v = build(l, u - 1);
        g[u].push_back(P(v, a[v] - a[u]));
    }

    if (u != r) {
        v = build(u + 1, r);
        g[u].push_back(P(v, a[v] - a[u]));
    }

    return u;
}

void dfs(int u, int m)
{
    sz[u] = 1;
    for (auto e:g[u]) {
        int v = e.fi;
        dfs(v, m);

        for (int i = 0; i <= sz[u] + sz[v]; i++) tmp[i] = 0;

        for (int i = 0; i <= sz[u]; i++) {
            for (int j = 0; j <= sz[v]; j++) {
                tmp[i + j] = max(tmp[i + j], f[u][i] + f[v][j] + 1LL * (m - j) * j * e.se);
            }
        }

        sz[u] += sz[v];
        for (int i = 0; i <= sz[u]; i++) f[u][i] = tmp[i];
    }
}

void solve()
{
    int n, m, rt;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    rt = build(1, n);
    dfs(rt, m);

    cout << f[rt][m] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) solve();
    return 0;
}