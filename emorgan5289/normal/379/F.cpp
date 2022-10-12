#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 500005;
int a[maxn], d[maxn];
vector<vector<int>> adj;

int l, n, timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    n = 4+2*q;
    adj.resize(4+2*q);
    adj[0] = {1, 2, 3};
    d[0] = 0;
    d[1] = d[2] = d[3] = 1;
    for (int p = 3, i = 0; i < q; i++) {
        cin >> a[i]; a[i]--;
        adj[a[i]].pb(++p);
        adj[a[i]].pb(++p);
        d[p] = d[p-1] = d[a[i]]+1;
    }
    preprocess(0);
    int u = 1, v = 2, r = 2;
    for (int i = 4; i < 4+2*q; i++) {
        if (d[i]+d[u]-2*d[lca(i, u)] > r)
            r++, v = i;
        if (d[i]+d[v]-2*d[lca(i, v)] > r)
            r++, u = i;
        if (i&1) cout << r << "\n";
    }
}