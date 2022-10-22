//2019.4.8 by ljz
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
inline void swap(res &x,res &y){
    x^=y^=x^=y;
}
const int N=1e5+10;
namespace MAIN{
    int n,q;
    set<int> S;
    set<int>::iterator it,pre,nxt;
    LL dis[N];
    struct E{
        int next,to,val;
        E() {}
        E(res next,res to,res val):next(next),to(to),val(val) {}
    }edge[N<<1];
    int head[N],cnt;
    inline void addedge(const res &u,const res &v,const res &w){
        edge[++cnt]=E(head[u],v,w),head[u]=cnt;
        edge[++cnt]=E(head[v],u,w),head[v]=cnt;
    }
    int dfn[N],idx,pos[N];
    int F[N][21],dep[N];
    void dfs(res x,res fax,res depx){
        F[x][0]=fax,dep[x]=depx,dfn[x]=++idx,pos[idx]=x;
        for(res i=1;i<=20;i++)F[x][i]=F[F[x][i-1]][i-1];
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            dis[tox]=dis[x]+edge[i].val,dfs(tox,x,depx+1);
        }
    }
    inline int get_lca(res x,res y){
        if(dep[x]<dep[y])swap(x,y);
        res pos=dep[x]-dep[y];
        for(res i=20;~i;i--)if(pos&(1<<i))x=F[x][i];
        if(x==y)return x;
        for(res i=20;~i;i--)if(F[x][i]!=F[y][i])x=F[x][i],y=F[y][i];
        return F[y][0];
    }
    inline LL get_dis(const res &x,const res &y){
        return dis[x]+dis[y]-2*dis[get_lca(x,y)];
    }
    LL ans;
    char opt[2];
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)head[i]=-1;
        for(res i=1;i<n;i++){
            res u=read(),v=read(),w=read();
            addedge(u,v,w);
        }
        dfs(1,0,1);
        q=read();
        while(q--){
            scanf("%s",opt);
            if(opt[0]=='+'){
                res x=read();
                S.insert(dfn[x]);
                if(S.size()==2)ans+=get_dis(pos[*S.begin()],pos[*(--S.end())])*2;
                else if(S.size()>=3){
                        pre=nxt=it=S.find(dfn[x]);
                        if(it==S.begin())nxt++,pre=S.end(),pre--;
                        else if(it==(--S.end()))pre--,nxt=S.begin();
                        else pre--,nxt++;
                        ans+=get_dis(pos[*it],pos[*nxt])+get_dis(pos[*it],pos[*pre])-get_dis(pos[*pre],pos[*nxt]);
                    }
            }
            else if(opt[0]=='-'){
                res x=read();
                if(S.size()==2)ans-=get_dis(pos[*S.begin()],pos[*(--S.end())])*2;
                else if(S.size()>=3){
                    pre=nxt=it=S.find(dfn[x]);
                    if(it==S.begin())nxt++,pre=S.end(),pre--;
                    else if(it==(--S.end()))pre--,nxt=S.begin();
                    else pre--,nxt++;
                    ans-=get_dis(pos[*it],pos[*nxt])+get_dis(pos[*it],pos[*pre])-get_dis(pos[*pre],pos[*nxt]);
                }
                S.erase(dfn[x]);
            }
            else printf("%lld\n",ans/2);
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}