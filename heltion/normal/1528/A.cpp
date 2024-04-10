#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
LL dp[maxn][2];
LL l[maxn], r[maxn];
vector<int> G[maxn];
void DFS(int u, int p = 0){
    dp[u][0] = dp[u][1] = 0;
    for(int v : G[u]) if(v != p){
        DFS(v, u);
        dp[u][0] += max(dp[v][0] + abs(l[u] - l[v]), dp[v][1] + abs(l[u] - r[v]));
        dp[u][1] += max(dp[v][0] + abs(r[u] - l[v]), dp[v][1] + abs(r[u] - r[v]));
    }
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1){
            cin >> l[i] >> r[i];
            G[i].clear();
        }
        for(int i = 1, u, v; i < n; i += 1){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        DFS(1);
        cout << max(dp[1][0], dp[1][1]) << "\n";
    }
    return 0;
}