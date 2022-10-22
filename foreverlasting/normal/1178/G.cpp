//2019.8.31 by ljz
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
    int n,m;
    vector<int> G[N];
    int a[N],b[N];
    int dfn[N],low[N],idx,pos[N];
    void dfs(res x){
        pos[dfn[x]=idx++]=x;
        for(auto tox:G[x])a[tox]+=a[x],b[tox]+=b[x],dfs(tox);
        low[x]=idx;
    }
    struct TR{
        int k,b,laz;
        LL mn;
        TR() {}
        TR(res k,res b,res laz,RG LL mn):k(k),b(b),laz(laz),mn(mn) {}
        inline void change(const res &va){
            b+=va,mn-=va,laz+=va;
        }
    }tr[N<<3];
    inline void pushdown(const res &rt){
        if(!tr[rt].laz)return;
        tr[rt<<1].change(tr[rt].laz),tr[rt<<1|1].change(tr[rt].laz),tr[rt].laz=0;
    }
    inline void pushup(const res &rt){
        res ls=rt<<1,rs=rt<<1|1;
        res k=tr[ls].k,b=tr[ls].b,K=tr[rs].k,B=tr[rs].b;
        RG LL r0=1LL*k*b,r1=1LL*K*B;
        if(r0>r1||(r0==r1&&k>K))swap(k,K),swap(b,B),swap(r0,r1);
        tr[rt]=TR(K,B,0,min(tr[ls].mn,tr[rs].mn));
        if(k>K)tr[rt].mn=min(tr[rt].mn,(r1-r0)/(k-K));
    }
    void build(res rt,res l,res r){
        if(l+1==r){
            res p=pos[l>>1];
            tr[rt]=TR(l&1?b[p]:-b[p],a[p],0,INF);
            return;
        }
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid,r),pushup(rt);
    }
    void modify(res rt,res l,res r,const res &L,const res &R,const res &va){
        if(r<=L||R<=l)return;
        if(L<=l&&r<=R&&tr[rt].mn>=tr[rt].laz+va){tr[rt].change(va);return;}
        pushdown(rt);
        res mid=(l+r)>>1;
        modify(rt<<1,l,mid,L,R,va),modify(rt<<1|1,mid,r,L,R,va),pushup(rt);
    }
    LL query(res rt,res l,res r,const res &L,const res &R){
        if(r<=L||R<=l)return -INF;
        if(L<=l&&r<=R)return 1LL*tr[rt].k*tr[rt].b;
        pushdown(rt);
        res mid=(l+r)>>1;
        return max(query(rt<<1,l,mid,L,R),query(rt<<1|1,mid,r,L,R));
    }
    inline void MAIN(){
        n=read(),m=read();
        for(res i=2;i<=n;i++)G[read()].pb(i);
        for(res i=1;i<=n;i++)a[i]=read();
        for(res i=1;i<=n;i++)b[i]=read();
        dfs(1),build(1,0,2*n);
        while(m--){
            res opt=read();
            if(opt==1){
                res x=read(),va=read();
                modify(1,0,2*n,dfn[x]<<1,low[x]<<1,va);
            }
            else {
                res x=read();
                printf("%lld\n",query(1,0,2*n,dfn[x]<<1,low[x]<<1));
            }
        }
    }
}
int main(){
//    srand(19260817);
//    freopen("zao.in","r",stdin);
//    freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}