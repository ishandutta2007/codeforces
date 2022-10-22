#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 7;
vector <int> g[N];
vector <int> top;
int cnt[N];
int par[N];
void dfs(int u) {
    cnt[u] = 1;
    for (int v : g[u]) {
        dfs(v);
        cnt[u] += cnt[v];
    }
    top.push_back(u);
}   
int ans[N];
int max_son[N];
int dsu[N];
int root(int u) {
    if (dsu[u] == u) return u;
    else return dsu[u] = root(dsu[u]);
}   
int get(int u, int sz) {
    u = root(u);
    if (cnt[max_son[par[u]]] * 2 <= sz) {
        return dsu[get(par[u], sz)];
    }
    else {
        return u;
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i);
        par[i] = p;
    }   
    dfs(0);
    for (int u = 0; u < n; ++u) {
        int mx = -1;
        for (int v : g[u]) {
            if (mx == -1 || cnt[mx] < cnt[v]) mx = v;
        }   
        max_son[u] = mx;
    }   
    for (int i = 0; i < n; ++i) {
        dsu[i] = i;
    }   
    for (int u : top) {
        if (cnt[max_son[u]] * 2 <= cnt[u]) {
            ans[u] = u;
        }   
        else {
            int v = ans[max_son[u]];            
            ans[u] = get(v, cnt[u]);
        }   
    }   
    for (int i = 0; i < q; ++i) {
        int u;
        cin >> u; --u;
        cout << ans[u] + 1 << '\n';
    }   
}