#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
constexpr int inf = 1E9 + 1;
int u[maxn], v[maxn], w[maxn], d[maxn + 1][51], done[maxn + 1][51];
vector<int> G[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i += 1){
        cin >> u[i] >> v[i] >> w[i];
        G[u[i]].push_back(i);
        G[v[i]].push_back(i);
    }
    for(int i = 1; i <= n; i += 1)
        for(int j = 0; j <= 50; j += 1) d[i][j] = inf;
    using PIII = pair<int, pair<int, int>>;
    priority_queue<PIII, vector<PIII>, greater<PIII>> q;
    q.push({d[1][0] = 0, {1, 0}});
    while(not q.empty()){
        auto [x, y] = q.top().second;
        q.pop();
        if(done[x][y]) continue;
        done[x][y] = 1;
        for(int i : G[x]){
            int z = u[i] ^ v[i] ^ x;
            if(y == 0){
                if(d[z][w[i]] > d[x][0]) q.push({d[z][w[i]] = d[x][0], {z, w[i]}});
            }
            else{
                int c = (w[i] + y) * (w[i] + y);
                if(d[z][0] > d[x][y] + c) q.push({d[z][0] = d[x][y] + c, {z, 0}});
            }
        }
    }
    for(int i = 1; i <= n; i += 1) if(d[i][0] == inf) cout << "-1 ";
    else cout << d[i][0] << " ";
    return 0;
}