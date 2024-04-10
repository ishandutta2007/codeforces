#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e6+10;
int _,n,ans;
bool f[maxn];
vector<int> G[maxn];
void dfs(int u,int fa){
    int t=0;
    for (auto v:G[u]){
        if (fa==v) continue;
        dfs(v,u);
        t+=!f[v];
    }
    if (u==1){
        ans+=max(1,t);
    } else {
        if (t) ans+=t-1,f[u]=1; else f[u]=0;
    }
}
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=1;i<=n;i++) G[i].clear();
        for (int i=1;i<n;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].pb(v); G[v].pb(u);
        }
        ans=0;
        dfs(1,0);
        printf("%d\n",ans);
    }
}