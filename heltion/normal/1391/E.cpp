#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000 + 1;
vector<int> G[maxn];
int vis[maxn], dep[maxn], k;
vector<int> path;
vector<int> a[maxn];
void DFS(int u){
    vis[u] = 1;
    a[dep[u]].push_back(u);
    if(path.size() != k) path.push_back(u);
    for(int v : G[u]) if(not vis[v]){
        dep[v] = dep[u] + 1;
        DFS(v);
    }
    if(path.size() != k) path.pop_back();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i += 1){
            vis[i] = 0;
            a[i].clear();
            G[i].clear();
        }
        for(int i = 0, u, v; i < m; i += 1){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        k = (n + 1) / 2;
        path.clear();
        DFS(1);
        if(path.size() == k){
            cout << "PATH\n";
            cout << k << "\n";
            for(int x : path) cout << x << " ";
            cout << "\n";
        }
        else{
            cout << "PAIRING\n";
            k = (k + 1) / 2;
            cout << k << "\n";
            for(int i = 1; i <= n and k; i += 1){
                while(k and (int)a[i].size() >= 2){
                    cout << a[i].back() << " ";
                    a[i].pop_back();
                    cout << a[i].back() << "\n";
                    a[i].pop_back();
                    k -= 1;
                }
            }
        }
    }
    return 0;
}