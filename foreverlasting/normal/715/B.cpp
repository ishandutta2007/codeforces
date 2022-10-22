//2018.10.18 by ljz
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
const LL N=1e6+10,M=1e6+10;
namespace MAIN{
    struct ED{
        LL u,v,w;
        ED() {}
        ED(res u,res v,res w):u(u),v(v),w(w) {}
    }ed[M];
    LL mark[N];
    struct E{
        LL next,to,val;
        E() {}
        E(res next,res to,res val):next(next),to(to),val(val) {}
    }edge[M];
    LL head[N],cnt=1;
    inline void addedge(const res &u,const res &v,res w){
        if(!w)w=1,mark[cnt+1]=mark[cnt+2]=1;
        edge[++cnt]=E(head[u],v,w),head[u]=cnt;
        edge[++cnt]=E(head[v],u,w),head[v]=cnt;
        ed[cnt>>1]=ED(u,v,w);
    }
    LL n,m,L,S,T;
    LL dis[N],pre[N];
    bool vis[N];
    typedef pair<LL,LL> Pair;
#define mp make_pair
    priority_queue<Pair,vector<Pair>,greater<Pair> >Q;
    inline LL spfa(){
        memset(dis,inf,sizeof(dis));
        dis[S]=0,vis[S]=1,Q.push(mp(0,S));
        while(!Q.empty()){
            res u=Q.top().second;
            Q.pop();
            vis[u]=0;
            for(res i=head[u];~i;i=edge[i].next){
                if(mark[i])continue;
                res tox=edge[i].to;
                if(dis[tox]>dis[u]+edge[i].val){
                    dis[tox]=dis[u]+edge[i].val;
                    if(!vis[tox])vis[tox]=1,Q.push(mp(dis[tox],tox));
                }
            }
        }
        return dis[T];
    }
    inline LL Spfa(){
        memset(dis,inf,sizeof(dis));
        dis[S]=0,vis[S]=1,Q.push(mp(0,S));
        while(!Q.empty()){
            res u=Q.top().second;
            Q.pop();
            vis[u]=0;
            for(res i=head[u];~i;i=edge[i].next){
                res tox=edge[i].to;
                if(dis[tox]>dis[u]+edge[i].val){
                    dis[tox]=dis[u]+edge[i].val;
                    pre[tox]=i;
                    if(!vis[tox])vis[tox]=1,Q.push(mp(dis[tox],tox));
                }
            }
        }
        return dis[T];
    }
    inline void Print(){
        puts("YES");
        for(res i=1;i<=m;i++)printf("%lld %lld %lld\n",ed[i].u-1,ed[i].v-1,ed[i].w);
    }
    LL chose[N];
    vector<LL> vec;
#define pb push_back
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        n=read(),m=read(),L=read(),S=read()+1,T=read()+1;
        for(res i=1;i<=m;i++){
            res u=read()+1,v=read()+1,w=read();
            addedge(u,v,w);
        }
        if(spfa()<L){puts("NO");return;}
        if(Spfa()>L){puts("NO");return;}
        if(dis[T]==L){Print();return;}
        res now=T;
        while(now!=S){
            if(mark[pre[now]])chose[pre[now]>>1]=1,vec.pb(pre[now]>>1);
            now=(ed[pre[now]>>1].u!=edge[pre[now]].to?ed[pre[now]>>1].u:ed[pre[now]>>1].v);
        }
        for(res i=1;i<=m;i++)if(mark[i<<1]&&!chose[i])ed[i].w=inf,edge[i<<1].val=edge[i<<1|1].val=inf;
        for(res i=0,siz=vec.size();i<siz;i++){
            res now=vec[i],delta=L-dis[T]+1;
            ed[now].w=delta,edge[now<<1].val=edge[now<<1|1].val=delta;
            if(Spfa()==L)break;
        }
        Print();
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}