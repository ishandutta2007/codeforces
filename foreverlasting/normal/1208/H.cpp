//2019.8.28 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define unl __int128
#define eps 5.6e-8
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define gc getchar
template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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
inline int read() {
    res s=0,ch=gc(),w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
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
const int N=2e5+10;
namespace MAIN{
    int n,k;
    vector<int> G[N];
    int col[N],sz[N],du[N],fa[N],son[N],top[N],dfn[N],idx,pos[N],low[N];
    Pair tr[N<<2];
    inline Pair operator + (const RG Pair &x,const RG Pair &y){
        return mp(min(x.se,max(x.fi,y.fi)),min(x.se,max(x.fi,y.se)));
    }
    Tree<Pair> T[N];
    decltype(begin(T[0])) D[N];
    inline int rankget(const RG Tree<Pair> &A,const res &x){
        return A.order_of_key(mp(x,inf));
    }
    inline bool ck(const res &x,const res &val,const RG bool &fl){
        res r=rankget(T[x],val)+fl,b=int(T[x].size())+1-r;
        return b-r<val;
    }
    inline void change(const res &x,res &val,const RG bool &fl){
        while(ck(x,val-1,fl))val--;
        while(!ck(x,val,fl))val++;
    }
    void modify(res rt,res l,res r,const res &p){
        if(l==r){
            res x=pos[l];
            if(du[x]==1&&x!=1)tr[rt]=(col[x]?mp(inf,inf):mp(-inf,-inf));
            else change(x,tr[rt].fi,1),change(x,tr[rt].se,0);
            return;
        }
        res mid=(l+r)>>1;
        if(p<=mid)modify(rt<<1,l,mid,p);
        else modify(rt<<1|1,mid+1,r,p);
        tr[rt]=tr[rt<<1]+tr[rt<<1|1];
    }
    Pair query(res rt,res l,res r,const res &L,const res &R){
        if(L<=l&&r<=R)return tr[rt];
        res mid=(l+r)>>1;
        if(L<=mid&&R>mid)return query(rt<<1,l,mid,L,R)+query(rt<<1|1,mid+1,r,L,R);
        if(L<=mid)return query(rt<<1,l,mid,L,R);
        return query(rt<<1|1,mid+1,r,L,R);
    }
    void dfs(res x,res fax){
        sz[x]=1;
        for(auto tox:G[x]){
            if(tox==fax)continue;
            dfs(tox,x),sz[x]+=sz[tox];
            if(sz[tox]>sz[son[x]])son[x]=tox;
        }
    }
    void dfs(res x,res fax,res topx){
        fa[x]=fax,top[x]=topx,dfn[x]=++idx,pos[idx]=x;
        if(son[x])dfs(son[x],x,topx),low[x]=low[son[x]];
        else low[x]=dfn[x];
        for(auto tox:G[x]){
            if(tox==fa[x]||tox==son[x])continue;
            dfs(tox,x,tox),D[tox]=T[x].insert(mp(query(1,1,n,dfn[tox],low[tox]).fi,x)).fi;
        }
        modify(1,1,n,dfn[x]);
    }
    inline void MAIN(){
        n=read(),k=read();
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            G[u].pb(v),G[v].pb(u),du[u]++,du[v]++;
        }
        for(res i=1;i<=n;i++)col[i]=read();
        dfs(1,0),dfs(1,0,1);
        res Q=read();
        while(Q--){
            res opt=read();
            if(opt==1){
                res x=read();
                puts(k>=query(1,1,n,dfn[x],low[x]).fi?"0":"1");
            }
            else if(opt==2){
                res x=read(),c=read();
                col[x]=c;
                while(233){
                    modify(1,1,n,dfn[x]),x=top[x];
                    if(x==1)break;
                    res Fa=fa[x];
                    T[Fa].erase(D[x]),D[x]=T[Fa].insert(mp(query(1,1,n,dfn[x],low[x]).fi,x)).fi,x=Fa;
                }
            }
            else k=read();
        }
    }
}
int main(){
//    srand(19260817);
//    freopen("signin.in","r",stdin);
//    freopen("signin.out","w",stdout);
    MAIN::MAIN();
    return 0;
}