#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 300000;
vector<int> G[maxn + 1];
int par[maxn + 1], sz[maxn + 1], hk[maxn + 1], top[maxn + 1], dfn[maxn + 1], dfc;
char ss[maxn + 1], s[maxn * 2 + 1];
void DFS1(int u){
    sz[u] = 1;
    for(int v : G[u]) if(v != par[u]){
        par[v] = u;
        DFS1(v);
        sz[u] += sz[v];
        if(sz[v] > sz[hk[u]]) hk[u] = v;
    }
}
void DFS2(int u){
    s[dfn[u] = dfc ++] = ss[u];
    if(hk[u]){
        top[hk[u]] = top[u];
        DFS2(hk[u]);
    }
    for(int v : G[u]) if(v != par[u] and v != hk[u])
        DFS2(top[v] = v);
}
int p[maxn * 2 + 1], c[maxn * 2 + 1], cnt[maxn * 2 + 1], pn[maxn * 2 + 1], cn[maxn * 2 + 1];
int rk[maxn * 2 + 1], lcp[maxn * 2];
int rmq[maxn * 2][20], LOG[maxn * 2 + 1];
void Suffix_Array(int n){
    s[n ++] = '$';
    for(int i = 0; i < n; i += 1) cnt[s[i]] += 1;
    for(int i = 1; i < max(n, 256); i += 1) cnt[i] += cnt[i - 1];
    for(int i = 0; i < n; i += 1) p[--cnt[s[i]]] = i;
    int k = c[p[0]] = 0;
    for(int i = 1; i < n; i += 1){
        if(s[p[i]] != s[p[i - 1]]) k += 1;
        c[p[i]] = k;
    }
    for(int h = 1; h < n; h <<= 1){
        for(int i = 0; i < n; i += 1){
            pn[i] = p[i] - h;
            if(pn[i] < 0) pn[i] += n;
        }
        for(int i = 0; i <= k; i += 1) cnt[i] = 0;
        for(int i = 0; i < n; i += 1) cnt[c[pn[i]]] += 1;
        for(int i = 1; i <= k; i += 1) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i -= 1) p[cnt[c[pn[i]]] -= 1] = pn[i];
        for(int i = 0; i < n; i += 1){
            pn[i] = p[i] + h;
            if(pn[i] > n) pn[i] -= n;
        }
        k = cn[pn[0]] = 0;
        for(int i = 1; i < n; i += 1){
            if(c[p[i]] != c[p[i - 1]] or c[pn[i]] != c[pn[i - 1]]) k += 1;
            cn[p[i]] = k;
        }
        for(int i = 0; i < n; i += 1) c[i] = cn[i];
    }
    for(int i = 1; i <= n; i += 1) p[i - 1] = p[i];
    n -= 1;
    for(int i = 0; i < n; i += 1) rk[p[i]] = i;
    k = 0;
    for(int i = 0; i < n; i += 1)
        if(rk[i] == n - 1) k = 0;
        else{
            for(int j = p[rk[i] + 1]; i + k < n and j + k < n and s[i + k] == s[j + k]; k += 1);
            lcp[rk[i]] = k;
            if(k) k -= 1;
        }
    for(int i = 2; i <= n; i += 1) LOG[i] = LOG[i >> 1] + 1;
    for(int j = 0; j < 20; j += 1)
    for(int i = 0; i + (1 << j) < n; i += 1)
            rmq[i][j] = j ? min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]) : lcp[i];
}
int query(int u, int v){
    if(u == v) return INT_MAX;
    int l = rk[u], r = rk[v];
    if(l > r) swap(l, r);
    int k = LOG[r - l];
    return min(rmq[l][k], rmq[r - (1 << k)][k]);
}
int abn, cdn;
pair<int, int> ab[maxn], cd[maxn];
int LCA(int a, int b){
    for(;top[a] != top[b]; a = par[top[a]]) if(dfn[a] < dfn[b]) swap(a, b);
    if(dfn[a] < dfn[b]) swap(a, b);
    return b;
}
int dcp(int a, int b, pair<int, int>* ab, int k){
    int m = 0;
    int u = LCA(a, b);
    for(;top[a] != top[u]; a = par[top[a]]) ab[m ++] = {k - dfn[a], k - dfn[top[a]]};
    if(a != u) ab[m ++] = {k - dfn[a], k - dfn[u] - 1};
    int n = m;
    for(;top[b] != top[u]; b = par[top[b]]) ab[n ++] = {dfn[top[b]], dfn[b]};
    ab[n ++] = {dfn[u], dfn[b]};
    reverse(ab + m, ab + n);
    return n;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n >> (ss + 1);
    for(int i = 1, u, v; i < n; i += 1){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS1(1);
    DFS2(top[1] = 1);
    copy(s, s + n, s + n);
    reverse(s + n, s + 2 * n);
    Suffix_Array(2 * n);
    int m;
    cin >> m;
    for(int i = 0; i < m; i += 1){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        abn = dcp(a, b, ab, 2 * n - 1);
        cdn = dcp(c, d, cd, 2 * n - 1);
        int p = 0, q = 0, ans = 0;
        while(p < abn and q < cdn){
            int x = ab[p].second - ab[p].first + 1, y = cd[q].second - cd[q].first + 1;
            int z = min({x, y, query(ab[p].first, cd[q].first)});
            ans += z;
            if(z < x and z < y) break;
            if(z == x) p += 1; else ab[p].first += z;
            if(z == y) q += 1; else cd[q].first += z;
        }
        cout << ans << "\n";
    }
    return 0;
}