//2019.7.2 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define eps 1e-10
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define gc getchar
//inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
inline int read() {
    res s=0,ch=gc();
    while(ch<'0'||ch>'9')ch=gc();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s;
}
//inline int read() {
//    res s=0,ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e4+10;
namespace MAIN{
    int n,m;
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
    int sz[N],son[N],fa[N],dep[N];
    void dfs(res x,res fax,res depx){
        sz[x]=1,fa[x]=fax,dep[x]=depx;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            dfs(tox,x,depx+1),sz[x]+=sz[tox];
            if(sz[tox]>sz[son[x]])son[x]=tox;
        }
    }
    int top[N],dfn[N],low[N],idx,pos[N];
    void dfs(res x,res topx){
        top[x]=topx,dfn[x]=++idx,pos[idx]=x;
        if(son[x])dfs(son[x],topx),low[x]=low[son[x]];
        else low[x]=idx;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fa[x]||tox==son[x])continue;
            dfs(tox,tox);
        }
    }
#define Edgid(i) i
#define Topid(i) i+n
#define Segid(i) i+n*2
#define Queid(i) i+n*4
    struct Dinic{
        struct E{
            int next,to,val;
            E() {}
            E(res next,res to,res val):next(next),to(to),val(val) {}
        }edge[N*100];
        int head[N*50],cnt,cur[N*50];
        Dinic() {memset(head,-1,sizeof(head)),cnt=-1;}
        inline void addedge(const res &u,const res &v,const res &w){
            edge[++cnt]=E(head[u],v,w),head[u]=cnt;
            edge[++cnt]=E(head[v],u,0),head[v]=cnt;
        }
        int Q[N*50],he,ta,S,T,dep[N*50];
        inline bool bfs(){
            for(res i=S;i<=T;i++)dep[i]=0;
            Q[he=ta=1]=S,dep[S]=1;
            while(he<=ta){
                res u=Q[he++];
                for(res i=head[u];~i;i=edge[i].next){
                    res tox=edge[i].to;
                    if(edge[i].val&&!dep[tox])dep[Q[++ta]=tox]=dep[u]+1;
                }
            }
            return dep[T]!=0;
        }
        int dfs(res x,res lim){
            if(x==T)return lim;
            for(res &i=cur[x];~i;i=edge[i].next){
                res tox=edge[i].to;
                if(dep[tox]==dep[x]+1&&edge[i].val){
                    res f=dfs(tox,min(lim,edge[i].val));
                    if(f>0){
                        edge[i].val-=f,edge[i^1].val+=f;
                        return f;
                    }
                }
            }
            return 0;
        }
        inline int dinic(){
            res ans=0;
            while(bfs()){
                memcpy(cur,head,sizeof(cur));
                while(int f=dfs(S,inf))ans+=f;
            }
            return ans;
        }
        bool vis[N*50];
        void Dfs(res x){
            vis[x]=1;
            for(res i=head[x];~i;i=edge[i].next){
                res tox=edge[i].to;
                if(!vis[tox]&&edge[i].val)Dfs(tox);
            }
        }
    }A;
    struct Seg{
        int ls[N<<2],rs[N<<2],tot,rt;
        void build(res &rt,res l,res r){
            rt=++tot;
            if(l==r){A.addedge(Segid(rt),Edgid(pos[l]),inf);return;}
            res mid=(l+r)>>1;
            build(ls[rt],l,mid),build(rs[rt],mid+1,r);
            A.addedge(Segid(rt),Segid(ls[rt]),inf),A.addedge(Segid(rt),Segid(rs[rt]),inf);
        }
        void connect(res rt,res l,res r,const res &L,const res &R,const res &I){
            if(L>R)return;
            if(L<=l&&r<=R){A.addedge(I,Segid(rt),inf);return;}
            res mid=(l+r)>>1;
            if(L<=mid)connect(ls[rt],l,mid,L,R,I);
            if(R>mid)connect(rs[rt],mid+1,r,L,R,I);
        }
    }B;
    inline void jump(res u,res v,const res &I){
        A.addedge(A.S,I,1);
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            A.addedge(I,Topid(u),inf),u=fa[top[u]];
        }
        if(dep[u]<dep[v])swap(u,v);
        B.connect(1,2,n,dfn[v]+1,dfn[u],I);
    }
    int ans1[N],ans2[N],ans1x,ans2x;
    inline void MAIN(){
        n=read(),m=read(),A.S=0,A.T=m+n*4+1;
        for(res i=1;i<=n;i++)head[i]=-1;
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            addedge(u,v);
        }
        dfs(1,0,1),dfs(1,1),B.build(B.rt,2,n);
        for(res t=1;t<=m;t++){
            res u=read(),v=read();
            jump(u,v,Queid(t));
        }
        for(res i=2;i<=n;i++){
            A.addedge(Edgid(i),A.T,1),A.addedge(Topid(i),Edgid(i),inf);
            if(i!=top[i]&&i!=son[1])A.addedge(Topid(i),Topid(fa[i]),inf);
        }
        printf("%d\n",A.dinic()),A.Dfs(A.S);
        for(res i=1;i<=m;i++)if(!A.vis[Queid(i)])ans1[++ans1x]=i;
        for(res i=1;i<n;i++){
            res u=edge[i*2].to,v=edge[i*2-1].to;
            if(fa[u]==v)swap(u,v);
            if(A.vis[Edgid(v)])ans2[++ans2x]=i;
        }
        printf("%d ",ans1x);
        for(res i=1;i<=ans1x;i++)printf("%d ",ans1[i]);
        printf("\n%d ",ans2x);
        for(res i=1;i<=ans2x;i++)printf("%d ",ans2[i]);
    }
}
int main() {
//    srand((unsigned)time(NULL));
    // freopen("zao.in","r",stdin);
    // freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}