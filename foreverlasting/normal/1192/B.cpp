//2019.11.6 by ljz
//#pragma GCC optimize(2)
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define unl __int128
#define eps 1e-9
#define RG register
#define db double
//#define pc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define lowbit(x) (x&-x)
#define gc getchar
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
//inline int read() {
//    res s=0,ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
//char sr[1<<21],z[20];
//int C=-1,Z=0;
//inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
//inline void print(res x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);sr[++C]='\n';
//}
inline int read() {
    res s=0,ch=gc(),w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
inline LL Read() {
    RG LL s=0;
    res ch=gc();
    while(ch<'0'||ch>'9')ch=gc();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s;
}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
//inline void write(RG unl x){
//    if(x>10)write(x/10);
//    putchar(int(x%10)+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
const int kcz=1000000007;
inline void add(res &x,const res &y){
    x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
}
inline int Add(const res &x,const res &y){
    return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
}
inline int mul(const res &x,const res &y){
    return int(1LL*x*y%kcz);
}
inline int mul(const res &x,const res &y,const res &d){
    return int(1LL*x*y/d%kcz);
}
inline int sqr(const res &x){
    return int(1LL*x*x%kcz);
}
inline int qpow(res x,res y){
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
inline LL Qpow(RG LL x,res y){
    RG LL ret=1;
    while(y){
        if(y&1)ret*=x;
        x*=x,y>>=1;
    }
    return ret;
}
const int N=2e5+10;
namespace MAIN{
    int n,q;
    struct E{
        int next,to;
        LL val;
        E() {}
        E(res next,res to,RG LL val):next(next),to(to),val(val) {}
    }edge[N];
    int head[N],cnt;
    inline void addedge(const res &u,const res &v,const RG LL &w){
        edge[++cnt]=E(head[u],v,w),head[u]=cnt;
        edge[++cnt]=E(head[v],u,w),head[v]=cnt;
    }
    int dfn[N],low[N],pos[N],idx,id[N];
    LL dis[N],w[N],val[N];
    void dfs(res x,res fax){
        pos[dfn[x]=++idx]=x;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            id[(i+1)>>1]=tox,w[tox]=edge[i].val,dis[tox]=dis[x]+edge[i].val,dfs(tox,x),pos[++idx]=x;
        }
        low[x]=idx;
    }
    LL mx[N<<2],mn[N<<2],lm[N<<2],rm[N<<2],ans[N<<2],laz[N<<2];
    inline void pushup(const res &rt){
        res ls=rt<<1,rs=rt<<1|1;
        mx[rt]=max(mx[ls],mx[rs]);
        mn[rt]=min(mn[ls],mn[rs]);
        lm[rt]=max({lm[ls],lm[rs],mx[ls]-mn[rs]*2});
        rm[rt]=max({rm[ls],rm[rs],mx[rs]-mn[ls]*2});
        ans[rt]=max({ans[ls],ans[rs],lm[ls]+mx[rs],rm[rs]+mx[ls]});
    }
    inline void change(const res &rt,const RG LL &val){
        mx[rt]+=val,mn[rt]+=val,lm[rt]-=val,rm[rt]-=val,laz[rt]+=val;
    }
    inline void pushdown(const res &rt){
        if(!laz[rt])return;
        change(rt<<1,laz[rt]),change(rt<<1|1,laz[rt]),laz[rt]=0;
    }
    void modify(res rt,res l,res r,const res &L,const res &R,const RG LL &val){
        if(L<=l&&r<=R){change(rt,val);return;}
        pushdown(rt);
        res mid=(l+r)>>1;
        if(L<=mid)modify(rt<<1,l,mid,L,R,val);
        if(R>mid)modify(rt<<1|1,mid+1,r,L,R,val);
        pushup(rt);
    }
    void build(res rt,res l,res r){
        if(l==r){change(rt,dis[pos[l]]);return;}
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r),pushup(rt);
    }
//    struct Matrix{
//        LL t[3][3];
//        Matrix() {for(res i=0;i<3;i++)for(res j=0;j<3;j++)t[i][j]=-INF;}
//        inline void init(const RG LL &g0,const RG LL &g1,const RG LL &w){
//            t[0][0]=t[2][2]=0,t[0][1]=g1,t[0][2]=g0,t[1][0]=t[2][0]=t[2][1]=-INF,t[1][1]=w,t[1][2]=g1+w;
//        }
//    }tr[N<<2];
//    inline Matrix operator * (const RG Matrix &x,const RG Matrix &y){
//        RG Matrix ret;
//        for(res i=0;i<3;i++)for(res j=0;j<3;j++)for(res k=0;k<3;k++)ret.t[i][j]=max(ret.t[i][j],x.t[i][k]+y.t[k][j]);
//        return ret;
//    }
//    int dfn[N],low[N],idx,dep[N],fa[N],sz[N],son[N],top[N],pos[N];
//    LL g[N][2],f[N][2],w[N];
//    void dfs(res x,res fax,res depx){
//        dep[x]=depx,fa[x]=fax,sz[x]=1;
//        for(res i=head[x];~i;i=edge[i].next){
//            res tox=edge[i].to;
//            if(tox==fax)continue;
//            w[tox]=edge[i].val,dfs(tox,x,depx+1),sz[x]+=sz[tox];
//            if(sz[tox]>sz[son[x]])son[x]=tox;
//        }
//    }
//    void dfs(res x,res topx){
//        top[pos[dfn[x]=++idx]=x]=topx;
//        if(son[x])dfs(son[x],topx);
//        for(res i=head[x];~i;i=edge[i].next){
//            res tox=edge[i].to;
//            if(tox==son[x]||tox==fa[x])continue;
//            dfs(tox,tox);
//        }
//        low[x]=idx;
//    }
//    void dfs(res x){
//        for(res i=head[x];~i;i=edge[i].next){
//            res tox=edge[i].to;
//            if(tox==fa[x])continue;
//            dfs(tox),f[x][0]=max({f[x][0],f[tox][0],f[x][1]+f[tox][1]+edge[i].val}),f[x][1]=max(f[x][1],f[tox][1]+edge[i].val);
//            if(tox==son[x])continue;
//            g[x][0]=max({f[x][0],f[tox][0],f[x][1]+f[tox][1]+edge[i].val}),g[x][1]=max(f[x][1],f[tox][1]+edge[i].val);
//        }
//    }
//    void build(res rt,res l,res r){
//        if(l==r){tr[rt].init(g[pos[l]][0],g[pos[l]][1],w[pos[l]]);return;}
//        res mid=(l+r)>>1;
//        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r),tr[rt]=tr[rt<<1]*tr[rt<<1|1];
//    }
    LL lastans,W;
    inline void MAIN(){
        n=read(),q=read(),W=Read();
        for(res i=1;i<=n;i++)head[i]=-1;
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            RG LL w=Read();
            addedge(u,v,w),val[i]=w;
        }
//        dfs(1,0,1),dfs(1,1);
        dfs(1,0),build(1,1,idx);
        while(q--){
            res d=(read()+int(lastans%(n-1)))%(n-1)+1;
            RG LL w=(Read()+lastans)%W;
            modify(1,1,idx,dfn[id[d]],low[id[d]],w-val[d]),val[d]=w,printf("%lld\n",lastans=ans[1]);
        }
    }
}
int main(){
//    freopen("money.in","r",stdin);
//    freopen("money.out","w",stdout);
//    srand(19260817);
    MAIN::MAIN();
//    Ot();
    return 0;
}