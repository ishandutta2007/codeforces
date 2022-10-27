#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const int inf = 100000;

int d[3005][3005];
bool vis[3005];
vector<int> g[3005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int u,v,n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            d[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        queue<int> q;
        for(int j = 1; j <= n; j++){
            vis[j] = false;
        }
        q.push(i);
        vis[i] = true;
        d[i][i] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto u : g[v]){
                if(!vis[u]){
                    q.push(u);
                    vis[u] = true;
                    d[i][u] = d[i][v] + 1;
                }
            }
        }
    }
    int s0, s1, t0, t1, l0, l1;
    cin>>s0>>t0>>l0;
    cin>>s1>>t1>>l1;
    if(d[s0][t0] > l0 || d[s1][t1] > l1){
        cout<<-1<<endl;
        return 0;
    }
    int ans = d[s0][t0] + d[s1][t1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int d0 = min(d[s0][i] + d[j][t0], d[t0][i] + d[j][s0]) + d[i][j];
            int d1 = min(d[s1][i] + d[j][t1], d[t1][i] + d[j][s1]) + d[i][j];
            if(d0 <= l0 && d1 <= l1){
                ans = min(ans, d0 + d1 - d[i][j]);
            }
        }
    }
    if(ans > m){
        cout<<-1<<endl;
    }else{
        cout<<m-ans<<endl;
    }
}