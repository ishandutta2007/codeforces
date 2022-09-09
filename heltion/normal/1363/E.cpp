#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
LL a[maxn], ans;
int b[maxn], c[maxn];
vector<int> G[maxn + 1];
int DFS(int u, int par = 0){
    int p = 0, n = 0;
    for(int v : G[u]) if(v != par){
        a[v] = min(a[u], a[v]);
        int r = DFS(v, u);
        if(r > 0) p += r;
        if(r < 0) n += -r;
    }
    if(b[u] != c[u]) (b[u] ? p : n) += 1;
    ans += min(p, n) * a[u];
    return p - n; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> a[i] >> b[i] >> c[i];
    for(int i = 1, u, v; i < n; i += 1){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(DFS(1)) cout << -1 << "\n";
    else cout << ans * 2 << "\n";
    return 0;
}