#include<bits/stdc++.h>
using namespace std;
int n,a,h[200005],top;
struct Edge{
    int v,nxt;
    Edge(){}
    Edge(int _v,int _nxt){v=_v,nxt=_nxt;}
}e[200005];
inline void add(int u,int v){
    e[++top]=Edge(v,h[u]),h[u]=top;
}
long long ans,t[200005],cnt[200005];
void dfs(int x,int f){
    int z=0;
    for(int i=h[x];i;i=e[i].nxt)if(e[i].v!=f)z++,dfs(e[i].v,x),cnt[x]+=cnt[e[i].v],t[x]+=t[e[i].v];
    if(!z)cnt[x]=1;
    ans=max(ans,(t[x]+cnt[x]-1)/cnt[x]);
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++)scanf("%d",&a),add(a,i);
    for(int i=1;i<=n;i++)scanf("%d",&t[i]);
    dfs(1,0);
    printf("%lld",ans);
    return 0;
}