#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=4e5+6;
vector <int> h[maxn];
bool vis[maxn];
int dis[maxn],ans[maxn],n,k,pre[maxn],rt,st,mx,len;
void dfs0(int u,int fa,int o){
    ans[u]=o;
    for (auto v:h[u]){
        if (v==fa) continue;
        dfs0(v,u,o^1);
    }
}
void dfs(int u,int fa){
    mx=max(mx,dis[u]);
    for (auto v:h[u]){
        if (vis[v]) continue;
        if (v==fa) continue;
        dis[v]=dis[u]+1;
        pre[v]=u;
        dfs(v,u);
    }
}
void dfs2(int u,int fa){
    for (auto v:h[u]){
        if (vis[v]) continue;
        if (v==fa) continue;
        dis[v]=dis[u]-1;
        pre[v]=u;
        dfs2(v,u);
    }
}
void solve2(){
    dfs0(1,0,0);
    puts("Yes");
    for (int i=1;i<=n;i++) printf("%d ",ans[i]+1); puts("");
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        h[u].pb(v); h[v].pb(u);
    }
    if (k==2) {solve2();return 0;}
    dis[1]=0; dfs(1,0); rt=1;
    for (int i=2;i<=n;i++) if (dis[i]>dis[rt]) rt=i;
    dis[rt]=0; dfs(rt,0); st=1;
    for (int i=2;i<=n;i++) if (dis[i]>dis[st]) st=i;
    len=dis[st];
    if (len<k-1){
        puts("Yes");
        for (int i=1;i<=n;i++) printf("%d ",i%k+1); puts("");
        return 0;
    }
    for (int i=st;;i=pre[i]){
        vis[i]=1;
        if (i==rt) break;
    }
    for (int i=st;;i=pre[i]){
        mx=0; dfs(i,0); mx-=dis[i];
        bool fl,fr;
        if (mx!=0){
            fl=(mx+dis[i]>=k-1);
            fr=(mx+len-dis[i]>=k-1);
            if (fl&&fr){puts("No");return 0;}
            if (fl) dfs(i,0); else dfs2(i,0);
        }
        if (i==rt) break;
    }
    puts("Yes");
    for (int i=1;i<=n;i++) printf("%d ",dis[i]%k+1); puts("");
    return 0;
}