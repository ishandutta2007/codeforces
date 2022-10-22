//2018.10.24 by ljz
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
const int N=4e5+10;
namespace MAIN{
    int n,m;
    int dfn[N],low[N],tim,pos[N];
    struct E{
        int next,to;
        E() {}
        E(res next,res to):next(next),to(to) {}
    }edge[N<<1];
    int head[N],cnt;
    inline void addedge(const res &u,const res &v){
        edge[++cnt]=E(head[u],v),head[u]=cnt;
        edge[++cnt]=E(head[v],u),head[v]=cnt;
    }
    int c[N];
    void dfs(const res &x,const res &fax){
        dfn[x]=++tim,pos[tim]=x;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            dfs(tox,x);
        }
        low[x]=tim;
    }
    LL laz[N<<2],sum[N<<2];
    inline void pushup(const res &rt){
        sum[rt]=sum[rt<<1]|sum[rt<<1|1];
    }
    void build(const res &rt,const res &l,const res &r){
        if(l==r){sum[rt]=1LL<<(c[pos[l]]-1);return;}
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    inline void change(const res &rt,const LL &va){
        laz[rt]=sum[rt]=va;
    }
    inline void pushdown(const res &rt){
        if(!laz[rt])return;
        change(rt<<1,laz[rt]),change(rt<<1|1,laz[rt]);
        laz[rt]=0;
    }
    void update(const res &rt,const res &l,const res &r,const res &L,const res &R,const res &va){
        if(L<=l&&r<=R){change(rt,1LL<<(va-1));return;}
        pushdown(rt);
        res mid=(l+r)>>1;
        if(L<=mid)update(rt<<1,l,mid,L,R,va);
        if(R>mid)update(rt<<1|1,mid+1,r,L,R,va);
        pushup(rt);
    }
    LL query(const res &rt,const res &l,const res &r,const res &L,const res &R){
        if(L<=l&&r<=R)return sum[rt];
        pushdown(rt);
        res mid=(l+r)>>1;
        LL ret=0;
        if(L<=mid)ret|=query(rt<<1,l,mid,L,R);
        if(R>mid)ret|=query(rt<<1|1,mid+1,r,L,R);
        return ret;
    }
    inline int count(LL x){
        res ret=0;
        while(x)ret+=x&1,x>>=1;
        return ret;
    }
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        n=read(),m=read();
        for(res i=1;i<=n;i++)c[i]=read();
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            addedge(u,v);
        }
        dfs(1,0);
        build(1,1,n);
        while(m--){
            res opt=read();
            if(opt==1){
                res u=read(),x=read();
                update(1,1,n,dfn[u],low[u],x);
            }
            else {
                res u=read();
                printf("%d\n",count(query(1,1,n,dfn[u],low[u])));
            }
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}