#include <bits/stdc++.h>
#define N 200005
using namespace std;
int n,m,color[N],ans,deg[N],c_c;
bool isans;
vector<int>g[N];
void dfs(int curr)
{
    if(deg[curr]!=2)
        isans=false;
    color[curr]=c_c;
    for(auto &it : g[curr]){
        if(!color[it])
            dfs(it);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i=1;i<=n;i++){
        if(!color[i]){
            c_c++;
            isans=true;
            dfs(i);
            if(isans)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}