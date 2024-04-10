#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000 + 1;
vector<int> G[maxn];
int c[maxn];
void DFS(int u){
    c[u] = 1;
    for(int v : G[u]) if(c[v] == 1) c[u] = 2;
    for(int v : G[u]) if(not c[v]) DFS(v);
}
int d[maxn];
void DFS2(int u){
    d[u] = 1;
    for(int v : G[u]) if(not d[v] and (c[u] == 1 or c[v] == 1)) DFS2(v);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i += 1){
            G[i].clear();
            c[i] = 0;
            d[i] = 0;
        }
        for(int i = 1, u, v; i <= m; i += 1){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        DFS(1);
        int ok = 1, k = 0;
        for(int i = 1; i <= n; i += 1) if(c[i] == 0) ok = 0;
        if(ok){
            cout << "YES\n";
            for(int i = 1; i <= n; i += 1) k += c[i] == 1;
            cout << k << "\n";
            for(int i = 1; i <= n; i += 1) if(c[i] == 1) cout << i << " ";
            cout << "\n";
            DFS2(1);
            for(int i = 1; i <= n; i += 1) assert(d[i]);
        }else cout << "NO\n";
    }
    return 0;
}