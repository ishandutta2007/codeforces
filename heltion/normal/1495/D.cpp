#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 400 + 1;
constexpr LL mod = 998244353;
vector<int> G[maxn];
int d[maxn][maxn];
LL ans[maxn][maxn];
int f[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    for(int i = 1, a, b; i <= m; i += 1){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= n; i += 1){
        for(int j = 1; j <= n; j += 1) d[i][j] = -1;
        queue<int> q;
        d[i][i] = 0;
        f[i][i] = 1;
        q.push(i);
        while(not q.empty()){
            int u = q.front();
            q.pop();
            for(int v : G[u]){
                if(d[i][v] == -1){
                    d[i][v] = d[i][u] + 1;
                    q.push(v);
                }
                if(d[i][v] == d[i][u] + 1) f[i][v] = min(2, f[i][v] + f[i][u]);
            }
        }
    }
    for(int i = 1; i <= n; i += 1)
        for(int j = i; j <= n; j += 1) if(f[i][j] == 1){
            ans[i][j] = 1;
            vector<int> vis(n + 1);
            int u = j;
            while(u != i){
                vis[u] = 1;
                for(int v : G[u]) if(d[i][v] + 1 == d[i][u]) u = v;
            }
            vis[i] = 1;
            for(int k = 1; k <= n; k += 1) if(not vis[k]){
                int cnt = 0;
                for(int x : G[k]) if(d[i][x] + 1 == d[i][k] and d[j][x] + 1 == d[j][k]) cnt += 1;
                ans[i][j] = ans[i][j] * cnt % mod;
            }
            ans[j][i] = ans[i][j];
        }
    for(int i = 1; i <= n; i += 1){
        for(int j = 1; j <= n; j += 1)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}