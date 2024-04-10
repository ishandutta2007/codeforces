#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
vector<pair<int, int>> G[maxn];
vector<int> GT[maxn];
int MT[45][45], ST[10];
int n, m, k, ans = 0;
void DFS(int i){
    if(i > k){
        ans += 1;
        return;
    }
    for(int j = i * (i - 1) / 2; j < i * (i + 1) / 2; j += 1){
        ST[i] = j;
        int ok = 1;
        for(int k = 1; k <= i; k += 1) if(MT[j][ST[k]]) ok = 0;
        if(ok) DFS(i + 1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for(int i = 0, u, v, w; i < m; i += 1){
        cin >> u >> v >> w;
        G[u].push_back({w, v});
    }
    for(int i = 1; i <= n; i += 1){
        sort(G[i].begin(), G[i].end());
        int x = G[i].size();
        for(int y = 0; y < x; y += 1) GT[G[i][y].second].push_back(x * (x - 1) / 2 + y);
    }
    for(int i = 1; i <= n; i += 1){
        vector<int> s(45);
        for(int u : GT[i]){
            for(int j = 0; j < 45; j += 1) if(s[j]) MT[u][j] = MT[j][u] = 1;
            s[u] = 1;
        }
    }
    DFS(1);
    cout << ans;
    return 0;
}