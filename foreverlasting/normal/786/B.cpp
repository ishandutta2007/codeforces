//2019.1.27 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f3f3f3f
#define eps 1e-10
inline int read() {
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')w=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y) {
    x^=y^=x^=y;
}
inline int _abs(const res &x) {
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
const int N=1e5+10;
namespace MAIN {
    int n,q,s;
    int ls[N<<3],rs[N<<3],rt[2],tot;
    struct E{
        int next,to,val;
        E() {}
        E(res next,res to,res val):next(next),to(to),val(val) {}
    }edge[(N<<3)+N*20];
    int head[N<<3],cnt;
    inline void addedge(const res &u,const res &v,const res &w){
        edge[++cnt]=E(head[u],v,w),head[u]=cnt;
    }
    void build0(res &rt,const res &l,const res &r){
        if(l==r){rt=l;return;}
        rt=++tot;
        res mid=(l+r)>>1;
        build0(ls[rt],l,mid),build0(rs[rt],mid+1,r);
        addedge(rt,ls[rt],0),addedge(rt,rs[rt],0);
    }
    void build1(res &rt,const res &l,const res &r){
        if(l==r){rt=l;return;}
        rt=++tot;
        res mid=(l+r)>>1;
        build1(ls[rt],l,mid),build1(rs[rt],mid+1,r);
        addedge(ls[rt],rt,0),addedge(rs[rt],rt,0);
    }
    void update(const res &rt,const res &l,const res &r,const res &L,const res R,const res &p,const res &w,const res &opt){
        if(L<=l&&r<=R){
            if(opt==0)addedge(p,rt,w);
            else addedge(rt,p,w);
            return;
        }
        res mid=(l+r)>>1;
        if(L<=mid)update(ls[rt],l,mid,L,R,p,w,opt);
        if(R>mid)update(rs[rt],mid+1,r,L,R,p,w,opt);
    }
    typedef pair<LL,int> Pair;
#define mp make_pair
#define fi first
#define se second
    priority_queue<Pair,vector<Pair>,greater<Pair> >Q;
    LL dis[N<<3];
    bool vis[N<<3];
    inline void spfa(const res &S){
        for(res i=1;i<=tot;i++)dis[i]=inf;
        dis[S]=0,vis[S]=1;
        Q.push(mp(0,S));
        while(!Q.empty()){
            res u=Q.top().se;
            Q.pop(),vis[u]=0;
            for(res i=head[u];~i;i=edge[i].next){
                res tox=edge[i].to;
                if(dis[tox]>dis[u]+edge[i].val){
                    dis[tox]=dis[u]+edge[i].val;
                    if(!vis[tox])vis[tox]=1,Q.push(mp(dis[tox],tox));
                }
            }
        }
    }
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        n=read(),q=read(),s=read(),tot=n;
        build0(rt[0],1,n),build1(rt[1],1,n);
        for(res i=1;i<=q;i++){
            res opt=read();
            if(opt==1){
                res u=read(),v=read(),w=read();
                addedge(u,v,w);
            }
            else {
                res u=read(),l=read(),r=read(),w=read();
                update(rt[opt-2],1,n,l,r,u,w,opt-2);
            }
        }
        spfa(s);
        for(res i=1;i<=n;i++)printf("%lld ",dis[i]==inf?-1:dis[i]);
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}