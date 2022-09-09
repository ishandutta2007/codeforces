#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
int p[maxn], dep[maxn], dp[maxn], ans;
vector<int> G[maxn];
void DFS(int u){
    vector<int> w;
    for(int v : G[u]) if(v != p[u]){
        p[v] = u;
        dep[v] = dep[u] + 1;
        DFS(v);
        w.push_back(dp[v]);
    }
    if(w.empty()) dp[u] = dep[u];
    else{
        if(u != 1){
            ans = max(*max_element(w.begin(), w.end()) - dep[u] + 1, ans);
            dp[u] = *min_element(w.begin(), w.end());
        }
        else{
            sort(w.begin(), w.end());
            for(int i = 0; i + 1 < (int)w.size(); i += 1) ans = max(w[i] + 1, ans);
            ans = max(w.back(), ans);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1) G[i].clear();
        for(int i = 1, u, v; i < n; i += 1){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ans = 0;
        DFS(1);
        cout << ans << "\n";
    }
    return 0;
}