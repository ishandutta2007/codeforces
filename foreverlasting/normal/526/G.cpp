//2019.3.6 by ljz
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
const int N=1e5+10;
namespace MAIN{
    int n,q;
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
    int lastans;
    int dis[N];
    int RT,mxdep[N];
    int pos[N],dfn[N],low[N],idx;
    void dfs(const res &x,const res &fax){
        if(dis[RT]<dis[x])RT=x;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            dis[tox]=dis[x]+edge[i].val,dfs(tox,x);
        }
    }
    int F[N][21];
    void Dfs(const res &x,const res &fax){
        dfn[x]=++idx,pos[idx]=x,mxdep[x]=dis[x],F[x][0]=fax;
        for(res i=1;i<=20;i++)F[x][i]=F[F[x][i-1]][i-1];
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            dis[tox]=dis[x]+edge[i].val,Dfs(tox,x),mxdep[x]=_max(mxdep[x],mxdep[tox]);
        }
        low[x]=idx;
    }
    int ans[N],id[N];
    typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
    Pair mx[N<<2];
    int laz[N<<2];
    inline void pushup(const res &rt){
        mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
    }
    void build(const res &rt,const res &l,const res &r){
        if(l==r){mx[rt]=mp(dis[pos[l]],pos[l]);return;}
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    inline void change(const res &rt,const res &va){
        laz[rt]+=va,mx[rt].fi+=va;
    }
    inline void pushdown(const res &rt){
        if(laz[rt])change(rt<<1,laz[rt]),change(rt<<1|1,laz[rt]),laz[rt]=0;
    }
    void modify(const res &rt,const res &l,const res &r,const res &L,const res &R,const res &va){
        if(L<=l&&r<=R){change(rt,va);return;}
        pushdown(rt);
        res mid=(l+r)>>1;
        if(L<=mid)modify(rt<<1,l,mid,L,R,va);
        if(R>mid)modify(rt<<1|1,mid+1,r,L,R,va);
        pushup(rt);
    }
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        n=read(),q=read();
        for(res i=1;i<n;i++){
            res u=read(),v=read(),w=read();
            addedge(u,v,w);
        }
        dfs(1,0),dis[RT]=0,Dfs(RT,0),build(1,1,n);
        for(res i=2;i<=n;i++){
            ans[i]=ans[i-1]+mx[1].fi;
//            printf("%d\n",ans[i]);
            for(res j=mx[1].se;!id[j]&&j;j=F[j][0])
                id[j]=i,modify(1,1,n,dfn[j],low[j],dis[F[j][0]]-dis[j]);
        }
        while(q--){
            res x=(read()+lastans-1)%n+1,y=_min(((read()+lastans-1)%n+1)<<1,n),X=x;
            if(id[x]<=y)printf("%d\n",lastans=ans[y]);
            else {
                for(res j=20;~j;j--)if(id[F[x][j]]>y)x=F[x][j];
                x=F[x][0];
                printf("%d\n",lastans=ans[y]+mxdep[X]-dis[x]-min({dis[x],ans[y]-ans[y-1],mxdep[x]-dis[x]}));
            }
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}