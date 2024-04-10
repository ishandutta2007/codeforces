#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000;
int uu[maxn], vv[maxn], x[maxn], p[maxn], f[maxn], t[maxn];
int fp(int u) {
    return p[u] == u ? u : p[u] = fp(p[u]);
}
int dfn[maxn], sz[maxn], d[maxn], dft, par[maxn], bit[maxn];
vector<pair<int, int>> G[maxn];
vector<int> Q[maxn];
void DFS(int u) {
    p[u] = u;
    dfn[u] = dft += 1;
    sz[u] = 1;
    for (int i : Q[u]) {
        int v = uu[i] ^ vv[i] ^ u;
        if (dfn[v]) f[i] = fp(v);
    }
    for (auto [v, w] : G[u]) if (v != par[u]) {
        d[v] = d[u] ^ w;
        par[v] = u;
        DFS(v);
        sz[u] += sz[v];
        p[v] = u;
    }
}
void add(int x, int d) {
    for (; x < maxn; x += x & -x) bit[x] += d;
}
int sum(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += bit[x];
    return res;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i += 1) p[i] = i;
    for (int i = 0; i < q; i += 1) {
        cin >> uu[i] >> vv[i] >> x[i];
        int pu = fp(uu[i]), pv = fp(vv[i]);
        if (pu != pv) {
            t[i] = 1;
            p[pu] = pv;
            G[uu[i]].push_back({vv[i], x[i]});
            G[vv[i]].push_back({uu[i], x[i]});
        }
        Q[uu[i]].push_back(i);
        Q[vv[i]].push_back(i);
    }
    for (int i = 1; i <= n; i += 1) p[i] = i;
    for (int i = 1; i <= n; i += 1) if (dfn[i] == 0) DFS(i);
    for (int i = 0; i < q; i += 1) {
        if (t[i]) cout << "YES\n";
        else if ((d[uu[i]] ^ d[vv[i]] ^ x[i]) == 1 and sum(dfn[uu[i]]) == sum(dfn[f[i]]) and sum(dfn[vv[i]]) == sum(dfn[f[i]])) {
            cout << "YES\n";
            for (int p : {uu[i], vv[i]}) {
                while(p != f[i]) {
                    add(dfn[p], 1);
                    add(dfn[p] + sz[p], -1);
                    p = par[p];
                }
            }
        }
        else cout << "NO\n";
    }
    return 0;
}