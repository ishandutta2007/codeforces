#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
vector<int> G[maxn];
int d[maxn], dp[maxn], p[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i += 1){
            G[i].clear();
            d[i] = n;
            p[i] = i;
        }
        d[1] = 0;
        for(int i = 0, u, v; i < m; i += 1){
            cin >> u >> v;
            G[u].push_back(v);
        }
        queue<int> q;
        q.push(1);
        while(not q.empty()){
            int u = q.front();
            q.pop();
            for(int v : G[u]) if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        sort(p + 1, p + n + 1, [&](const int& x, const int& y){
            return d[x] > d[y];
        });
        for(int i = 1; i <= n; i += 1){
            int u = p[i];
            dp[u] = d[u];
            for(int v : G[u]) dp[u] = min(dp[u], d[v]);
            for(int v : G[u]) if(d[v] > d[u]) dp[u] = min(dp[u], dp[v]);
        }
        for(int i = 1; i <= n; i += 1) cout << dp[i] << " ";
        cout << "\n";
    }
    return 0;
}