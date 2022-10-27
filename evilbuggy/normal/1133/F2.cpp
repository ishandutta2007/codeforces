#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int par[200005];
int vis[200005];
vector<int> g[200005];

void dfs(int v, int p){
    if(vis[v])return;
    par[v] = p;
    vis[v] = 1;
    for(auto u : g[v]){
        dfs(u, v);
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, m, d, u, v;
    cin>>n>>m>>d;
    memset(par, 0, sizeof(par));
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(g[1].size() < d){
        cout<<"NO"<<endl;
        exit(0);
    }
    dfs(1, 0);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(par[i] == 1)cnt++;
    }
    if(cnt > d){
        cout<<"NO"<<endl;
        exit(0);
    }
    for(auto u : g[1]){
        if(par[u] != 1 && cnt < d){
            par[u] = 1;
            cnt++;
        }
    }
    cout<<"YES"<<endl;
    for(int i = 2; i <= n; i++){
        cout<<i<<" "<<par[i]<<endl;
    }
}