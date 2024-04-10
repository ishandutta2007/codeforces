#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+3;
int to[maxn][26],id[maxn],tot,n,q,a[maxn],dp[maxn];
bool vis[maxn];
void dfs0(int u){
    if (vis[u]) id[u]=++tot;
    for (int i=0;i<26;i++){
        int v=to[u][i];
        if (v) dfs0(v);
    }
}
void dfs(int u,int w){
    int nw=max(w,tot-dp[u]);
    if (vis[u]) ++tot;
    for (int i=0;i<26;i++){
        int v=to[u][i];
        if (!v) continue;
        dp[v]=dp[u]+1;
        if (vis[v]) dp[v]=min(dp[v],id[v]-w);
        dfs(v,nw);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int x; char s[2];
        scanf("%d%s",&x,s);
        to[x][s[0]-'a']=i;
    }
    scanf("%d",&q);
    for (int i=1;i<=q;i++){
        scanf("%d",&a[i]);
        vis[a[i]]=1;
    }
    tot=0; dfs0(0);
    tot=0; dfs(0,0);
    for (int i=1;i<=q;i++) printf("%d ",dp[a[i]]); puts("");
    return 0;
}