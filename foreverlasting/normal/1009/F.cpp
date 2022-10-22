//2018.9.12 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int N=1e6+10;
namespace MAIN{
    int n;
    struct E{
        int next,to;
        E() {}
        E(res next,res to):next(next),to(to) {}
    }edge[N<<1];
    int head[N],cnt;
    inline void addedge(res u,res v){
        edge[++cnt]=E(head[u],v),head[u]=cnt;
        edge[++cnt]=E(head[v],u),head[v]=cnt;
    }
    int fa[N],maxdep[N],dep[N],son[N];
    void dfs(res x,res fax,res depx){
        fa[x]=fax,maxdep[x]=dep[x]=depx;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            dfs(tox,x,depx+1);
            maxdep[x]=_max(maxdep[x],maxdep[tox]);
            if(maxdep[tox]>maxdep[son[x]])son[x]=tox;
        }
    }
    int ans[N];
    int *dp[N],tmp[N<<5],*now=tmp+1;
    inline void Dp(res x){
        dp[x]=now,now+=maxdep[x]-dep[x]+1;
    }
    void DP(res x){
        if(son[x])dp[son[x]]=dp[x]+1,DP(son[x]),ans[x]=ans[son[x]]+1;
        dp[x][0]=1;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fa[x]||tox==son[x])continue;
            Dp(tox);
            DP(tox);
            for(res j=0;j<=maxdep[tox]-dep[tox];j++){
                dp[x][j+1]+=dp[tox][j];
                if(dp[x][j+1]>dp[x][ans[x]]||(dp[x][j+1]==dp[x][ans[x]]&&ans[x]>j+1))ans[x]=j+1;
            }
        }
        if(dp[x][ans[x]]==1)ans[x]=0;
    }
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        n=read();
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            addedge(u,v);
        }
        dfs(1,0,1);
        Dp(1);
        DP(1);
        for(res i=1;i<=n;i++)printf("%d\n",ans[i]);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}