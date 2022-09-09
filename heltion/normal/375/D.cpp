#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 1;
int c[maxn], ans[maxn], v[maxn], k[maxn], p[maxn];
vector<int> G[maxn], Q[maxn], order;
map<int, int> cn[maxn], mp[maxn];
void DFS(int u){
    for(int v : G[u]) if(v != p[u]){
        p[v] = u;
        DFS(v);
    }
    order.push_back(u);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1) cin >> c[i];
    for(int i = 1, a, b; i < n; i += 1){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < m; i += 1){
        cin >> v[i] >> k[i];
        Q[v[i]].push_back(i);
    }
    DFS(1);
    for(auto u : order){
        mp[u][cn[u][c[u]] += 1] += 1;
        for(int i : Q[u]){
            auto it = mp[u].lower_bound(k[i]);
            ans[i] = it == mp[u].end() ? 0 : it->second;
        }
        if(mp[u].size() > mp[p[u]].size()){
            swap(cn[u], cn[p[u]]);
            swap(mp[u], mp[p[u]]);
        }
        for(auto [c, n] : cn[u]) for(int i = 0; i < n; i += 1) mp[p[u]][cn[p[u]][c] += 1] += 1;
    }
    for(int i = 0; i < m; i += 1) cout << ans[i] << "\n";
    return 0;
}