//2018.10.16 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register LL
#define LL long long
#define inf 0x3f3f3f3f3f3f3f
#define eps 1e-15
inline LL read(){
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
inline LL _abs(const res &x){
    return x>0?x:-x;
}
inline LL _max(const res &x,const res &y){
    return x>y?x:y;
}
inline LL _min(const res &x,const res &y){
    return x<y?x:y;
}
const LL N=2e5+10;
namespace MAIN{
    LL n,m,Q;
    struct E{
        LL next,to,val;
        E() {}
        E(res next,res to,res val):next(next),to(to),val(val) {}
    }edge[N];
    LL head[N],cnt;
    inline void addedge(const res &u,const res &v,const res &w){
        edge[++cnt]=E(head[u],v,w),head[u]=cnt;
    }
    LL a[N],b[N];
    LL laz[N<<2],sum[N<<2];
    inline void pushup(const res &rt){
        sum[rt]=_min(sum[rt<<1],sum[rt<<1|1]);
    }
    void build(const res &rt,const res &l,const res &r){
        sum[rt]=inf,laz[rt]=0;
        if(l==r){sum[rt]=b[l];return;}
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    inline void change(const res &rt,const res &va){
        laz[rt]+=va,sum[rt]+=va;
    }
    inline void pushdown(const res &rt){
        if(!laz[rt])return;
        change(rt<<1,laz[rt]),change(rt<<1|1,laz[rt]);
        laz[rt]=0;
    }
    void update(const res &rt,const res &l,const res &r,const res &L,const res &R,const res &va){
        if(L<=l&&r<=R){change(rt,va);return;}
        pushdown(rt);
        res mid=(l+r)>>1;
        if(L<=mid)update(rt<<1,l,mid,L,R,va);
        if(R>mid)update(rt<<1|1,mid+1,r,L,R,va);
        pushup(rt);
    }
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        n=read(),m=read(),Q=read();
        for(res i=1;i<n;i++)a[i]=read(),b[i+1]=read();
        build(1,1,n);
        for(res i=1;i<=m;i++){
            res u=read(),v=read(),w=read();
            addedge(u,v,w);
        }
        for(res x=1;x<=n;x++){
            for(res i=head[x];~i;i=edge[i].next){
                res tox=edge[i].to;
                update(1,1,n,1,tox,edge[i].val);
            }
            b[x]=sum[1]+a[x];
        }
        build(1,1,n);
        printf("%lld\n",sum[1]);
        while(Q--){
            res x=read(),y=read();
            update(1,1,n,x,x,y-a[x]);
            a[x]=y;
            printf("%lld\n",sum[1]);
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}