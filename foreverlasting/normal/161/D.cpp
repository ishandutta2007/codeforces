//2018.11.30 by ljz
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
const int N=5e4+10;
namespace MAIN{
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
    int n,k;
    int siz[N],rt,w[N];
    bool vis[N];
    void dfs_siz(const res &x,const res &fax,res sum){
        siz[x]=1,w[x]=0;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax||vis[tox])continue;
            dfs_siz(tox,x,sum);
            siz[x]+=siz[tox],w[x]=_max(w[x],siz[tox]);
        }
        w[x]=_max(w[x],sum-siz[x]);
        if(w[x]<w[rt])rt=x;
    }
    int vec[N],tot;
    int pos[N];
    LL ans;
    int dis[N];
    inline void dfs_dis(const res &x,const res &fax){
        vec[++tot]=dis[x],pos[dis[x]]++;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax||vis[tox])continue;
            dis[tox]=dis[x]+edge[i].val;
            dfs_dis(tox,x);
        }
    }
    inline void calc(const res &x,const res &d0,const res &flag){
        tot=0,dis[x]=d0;
        dfs_dis(x,0);
        for(res i=1;i<=tot;i++){
            if(k>=vec[i])ans+=(vec[i]*2!=k)?1LL*flag*pos[vec[i]]*pos[k-vec[i]]:1LL*flag*pos[vec[i]]*(pos[vec[i]]-1)/2;
            pos[vec[i]]=pos[k-vec[i]]=0;
        }
    }
    void solve(const res &x){
        calc(x,0,1),vis[x]=1;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(vis[tox])continue;
            calc(tox,edge[i].val,-1);
            rt=0,dfs_siz(tox,0,siz[tox]),solve(rt);
        }
    }
    inline void MAIN(){
        memset(head,-1,sizeof(head)),w[0]=inf;
        n=read(),k=read();
        for(res i=1;i<n;i++){
            res u=read(),v=read(),w=1;
            addedge(u,v,w);
        }
        dfs_siz(1,0,n),solve(rt);
        printf("%lld\n",ans);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}