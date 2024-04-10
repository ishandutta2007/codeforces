#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
LL h[maxn], p[maxn], up[maxn], sz[maxn];
int par[maxn];
vector<int> G[maxn], order;
void DFS(int u){
    sz[u] = p[u];
    for(int v : G[u]) if(v != par[u]){
        par[v] = u;
        DFS(v);
        sz[u] += sz[v];
    }
    h[u] = sz[u] - h[u];
    order.push_back(u);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i += 1) cin >> p[i];
        for(int i = 1; i <= n; i += 1) cin >> h[i];
        for(int i = 1; i <= n; i += 1) G[i].clear();
        for(int i = 1; i <= n; i += 1) up[i] = 0;
        for(int i = 1, x, y; i < n; i += 1){
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        order.clear();
        DFS(1);
        int ans = 1;
        for(int u : order)
            if(h[u] < 0 or (h[u] & 1)) ans = 0;
            else if(h[u] / 2 > up[u] + p[u]) ans = 0;
            else up[par[u]] += h[u] / 2;
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}