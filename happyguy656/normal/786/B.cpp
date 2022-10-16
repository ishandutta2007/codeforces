#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(int i=first[x];i;i=nxt[i])
#define uu unsigned
#define fi first
#define se second
#define ran() ((unsigned)rand())
#define lam(z,k) [&](const z &a,const z &b){ return k; }
#define od(x) ((x)&1)
#define ev(x) (od(x)^1)
#define scanf a1234=scanf
#define pb push_back
int a1234;
inline void xxx(){for(;;);}

const int mxn=1e5+3;int n,Q,st,N;
const long long inf=0x3f3f3f3f3f3f3f3f;


long long dis[mxn*8];bool vis[mxn*8];
struct nod{
    int x;long long w;
};
inline bool operator <(const nod &a,const nod &b){return a.w>b.w;}
priority_queue<nod>q;
vector<nod>g[mxn*8];
int pos[mxn];
inline void gadd(int x,int y,int w){g[x].push_back((nod){y,w});}
#define mid ((l+r)>>1)
class segt{
    public:
    inline void build(int x,int l,int r){
        if(l==r)return pos[l]=x,gadd(x,x+N,0),gadd(x+N,x,0),void();
        gadd(x,x*2,0),gadd(x,x*2+1,0);
        gadd(x*2+N,x+N,0),gadd(x*2+1+N,x+N,0);
        build(x*2,l,mid),build(x*2+1,mid+1,r);
    }
    inline void lklr(int u,int w,int x,int l,int r,int lc,int rc){
        if(lc<=l&&r<=rc)return gadd(pos[u],x,w),void();
        if(lc<=mid)lklr(u,w,x*2,l,mid,lc,rc);
        if(rc>mid)lklr(u,w,x*2+1,mid+1,r,lc,rc);
    }
    inline void lrlk(int v,int w,int x,int l,int r,int lc,int rc){
        if(lc<=l&&r<=rc)return gadd(x+N,pos[v],w),void();
        if(lc<=mid)lrlk(v,w,x*2,l,mid,lc,rc);
        if(rc>mid)lrlk(v,w,x*2+1,mid+1,r,lc,rc);
    }
}seg;
#undef mid
inline void dijk(){
    memset(dis,0x3f,sizeof(dis));
    q.push({pos[st],0});
    dis[pos[st]]=0;
    static nod tp;
    while(q.size()){
        tp=q.top();q.pop();
        const int x=tp.x;
        if(vis[x])continue;vis[x]=1;
        if(tp.w!=dis[x])xxx(),puts("em");
        for(auto &it:g[x])if(dis[it.x]>dis[x]+it.w)dis[it.x]=dis[x]+it.w,q.push({it.x,dis[it.x]});
    }
}
int main(){
    scanf("%d%d%d",&n,&Q,&st);N=n*4;
    seg.build(1,1,n);
 //   for(int i=1;i<=n;++i)printf("%d ",pos[i]);puts("");return 3;
    while(Q--){
        int o,u,v,l,r,w;scanf("%d",&o);
        if(o==1){
            scanf("%d%d%d",&u,&v,&w);
            gadd(pos[u],pos[v],w);
        }else if(o==2){
            scanf("%d%d%d%d",&u,&l,&r,&w);
            seg.lklr(u,w,1,1,n,l,r);
        }else if(o==3){
            scanf("%d%d%d%d",&v,&l,&r,&w);
            seg.lrlk(v,w,1,1,n,l,r);
        }
    }
    dijk();
    for(int i=1;i<=n;++i)printf("%lld ",dis[pos[i]]==inf?-1:dis[pos[i]]);
    puts("");
    return 0;
}