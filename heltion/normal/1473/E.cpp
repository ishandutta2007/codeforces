#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
LL d[maxn][4];
int done[maxn][4];
vector<pair<int, int>> G[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1)
        for(int j = 0; j < 4; j += 1)
            d[i][j] = 1E15;
    for(int i = 1, u, v, w; i <= m; i += 1){
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    using PLII = pair<LL, pair<int, int>>;
    priority_queue<PLII, vector<PLII>, greater<PLII>> pq;
    pq.push({d[1][0] = 0, {1, 0}});
    while(not pq.empty()){
        auto [u, s] = pq.top().second;
        pq.pop();
        if(done[u][s]) continue;
        done[u][s] = 1;
        //cout << u << " " << s << " " << d[u][s] << '\n';
        for(auto [v, w] : G[u])
            if(d[v][s] > d[u][s] + w)
                pq.push({d[v][s] = d[u][s] + w, {v, s}});
        if(s == 0) 
            for(auto [v, w] : G[u])
                if(d[v][3] > d[u][0] + w)
                    pq.push({d[v][3] = d[u][0] + w, {v, 3}});
        if((s & 1) == 0) 
            for(auto [v, w] : G[u])
                if(d[v][s | 1] > d[u][s] + 2 * w)
                    pq.push({d[v][s | 1] = d[u][s] + 2 * w, {v, s | 1}});
        if((s & 2) == 0) 
            for(auto [v, w] : G[u])
                if(d[v][s | 2] > d[u][s])
                    pq.push({d[v][s | 2] = d[u][s], {v, s | 2}});
    }
    for(int i = 2; i <= n; i += 1) cout << d[i][3] << " ";
    return 0;
}