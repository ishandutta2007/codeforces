//2019.9.1 by ljz
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
const int B=250+10;
namespace MAIN{
    int n,m,lim;
    vector<int> G[N];
    int a[N],sz[N],fa[N],son[N];
    void dfs(res x){
        sz[x]=1;
        for(auto tox:G[x]){
            dfs(tox),sz[x]+=sz[tox],fa[tox]=x;
            if(sz[tox]>sz[son[x]])son[x]=tox;
        }
    }
    int dfn[N],idx,pos[N],top[N];
    void dfs(res x,res topx){
        top[pos[dfn[x]=++idx]=x]=topx;
        if(son[x])dfs(son[x],topx);
        else return;
        for(auto tox:G[x]){
            if(tox==son[x])continue;
            dfs(tox,tox);
        }
    }
    int f[B][N],suma[N],g[B],ans;
    inline void C0(const res &I){
        res x=I/lim;
        if(suma[I]<g[x])ans--;
        f[x][suma[I]]--,suma[I]+=inf;
    }
    inline void C1(const res &I){
        res x=I/lim;
        suma[I]-=inf,f[x][suma[I]]++;
        if(suma[I]<g[x])ans++;
    }
    inline void A0(const res &x){
        g[x]--,ans-=f[x][g[x]];
    }
    inline void A1(const res &I,const res &x){
        if(suma[x]>inf){suma[x]++;return;}
        f[I][suma[x]]--,suma[x]++,f[I][suma[x]]++;
        if(suma[x]==g[I])ans--;
    }
    inline void D0(const res &x){
        ans+=f[x][g[x]],g[x]++;
    }
    inline void D1(const res &I,const res &x){
        if(suma[x]>inf){suma[x]--;return;}
        f[I][suma[x]]--,suma[x]--,f[I][suma[x]]++;
        if(suma[x]==g[I]-1)ans++;
    }
    inline void F0(const res &l,const res &r){//Del
        res i=l/lim,j=r/lim;
        if(i==j){
            for(res k=l;k<=r;k++)D1(i,k);
            return;
        }
        for(res k=l;k<=n&&k<(i+1)*lim;k++)D1(i,k);
        for(res k=j*lim;k<=r&&k<=n;k++)D1(j,k);
        for(res k=i+1;k<j;k++)D0(k);
    }
    inline void F1(const res &l,const res &r){//Add
        res i=l/lim,j=r/lim;
        if(i==j){
            for(res k=l;k<=r;k++)A1(i,k);
            return;
        }
        for(res k=l;k<=n&&k<(i+1)*lim;k++)A1(i,k);
        for(res k=j*lim;k<=r&&k<=n;k++)A1(j,k);
        for(res k=i+1;k<j;k++)A0(k);
    }
    inline void MAIN(){
        n=read(),m=read(),lim=400;
        for(res i=2;i<=n;i++)G[read()].pb(i);
        for(res i=1;i<=n;i++)a[i]=read();
        dfs(1),dfs(1,1);
        for(res i=1;i<=n;i++)suma[i]=a[pos[i]]+n,f[i/lim][suma[i]]++;
        for(res i=0;i<=n/lim;i++)g[i]=n;
        while(m--){
            res x=read(),fl;
            if(x>0)fl=0;
            else x=-x,fl=1;
            fl?C1(dfn[x]):C0(dfn[x]);
            while(x){
                res y=top[x];
                fl?F1(dfn[y],dfn[x]):F0(dfn[y],dfn[x]);
                x=fa[y];
            }
            printf("%d ",ans);
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