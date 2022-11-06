#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
vector<int> G[maxn + 1];
int sz[maxn + 1], p[maxn + 1], sn[maxn + 1], dep[maxn + 1];
void DFS(int u, int par = 0){
    p[u] = par;
    dep[u] = dep[par] + 1;
    sz[u] = 1;
    for(int v : G[u]) if(v != par){
        DFS(v, u);
        sz[u] += sz[v];
        sn[u] += 1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 1, u, v; i < n; i += 1){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS(1);
    priority_queue<pair<int, int>> q;
    for(int i = 1; i <= n; i += 1) if(not sn[i]) q.push({dep[i] - 1, i});
    LL ans = 0;
    for(int i = 0; i < k; i += 1){
        auto [w, u] = q.top();
        q.pop();
        ans += w;
        if(not --sn[p[u]]) q.push({dep[p[u]] - sz[p[u]], p[u]});
    }
    cout << ans;
    return 0;
}