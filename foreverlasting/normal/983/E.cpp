//2019.9.2 by ljz
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
const int N=2e5+10;
namespace MAIN{
    int n,m;
    vector<int> G[N];
    int fa[N],F[N][21],dfn[N],idx,low[N],dep[N];
    void dfs(res x,res depx){
        F[x][0]=fa[x],dep[x]=depx,dfn[x]=++idx;
        for(res i=1;i<=20;i++)F[x][i]=F[F[x][i-1]][i-1];
        for(auto tox:G[x])dfs(tox,depx+1);
        low[x]=idx;
    }
    inline int getlca(res x,res y){
        if(dep[x]<dep[y])swap(x,y);
        res pos=dep[x]-dep[y];
        for(res i=20;~i;i--)if(pos&(1<<i))x=F[x][i];
        if(x==y)return x;
        for(res i=20;~i;i--)if(F[x][i]!=F[y][i])x=F[x][i],y=F[y][i];
        return F[y][0];
    }
    vector<int> E[N];
    int A[N][21];
    void dfs(res x){
        for(auto tox:G[x])dfs(tox),A[x][0]=min(A[tox][0],A[x][0]);
    }
    inline int get(res x,const res &rt){
        if(x==rt)return 0;
        res ans=0;
        for(res i=20;~i;i--)if(A[x][i]>rt)x=A[x][i],ans|=1<<i;
        if(A[x][0]>rt)return inf;
        return ans+1;
    }
    inline int jump(res x,const res &pos){
        for(res i=20;~i;i--)if(pos&(1<<i))x=A[x][i];
        return x;
    }
    vector<Pair> B[N];
    vector<int> sum[N];
    int ans[N];
#define lowbit(x) (x&-x)
    int tr[N];
    inline void modify(const res &x,const res &y){
        for(res i=x;i<=n;i+=lowbit(i))tr[i]+=y;
    }
    inline int query(const res &x){
        res ret=0;
        for(res i=x;i;i-=lowbit(i))ret+=tr[i];
        return ret;
    }
    void Dfs(res x){
        for(auto y:B[x])sum[x].pb(query(low[y.fi])-query(dfn[y.fi]-1));
        for(auto y:E[x])modify(dfn[y],1);
        for(auto tox:G[x])Dfs(tox);
        for(res i=0,sz=int(B[x].size()-1);i<=sz;i++)if(sum[x][i]!=query(low[B[x][i].fi])-query(dfn[B[x][i].fi]-1))ans[B[x][i].se]--;
    }
    inline void MAIN(){
        n=read();
        for(res i=2;i<=n;i++)fa[i]=read(),G[fa[i]].pb(i),A[i][0]=i;
        dfs(1,1),m=read();
        for(res i=1;i<=m;i++){
            res u=read(),v=read(),lca=getlca(u,v);
            E[u].pb(v),E[v].pb(u),A[u][0]=min(A[u][0],lca),A[v][0]=min(A[v][0],lca);
        }
        dfs(1);
        for(res j=1;j<=20;j++)
            for(res i=1;i<=n;i++)
                A[i][j]=A[A[i][j-1]][j-1];
        res q=read();
        for(res Q=1;Q<=q;Q++){
            res u=read(),v=read(),lca=getlca(u,v);
            if(lca==u)ans[Q]=get(v,lca);
            else if(lca==v)ans[Q]=get(u,lca);
            else {
                res a=get(u,lca),b=get(v,lca),x=jump(u,a-1),y=jump(v,b-1);
                ans[Q]=a+b,B[x].pb(mp(y,Q));
            }
        }
        Dfs(1);
        for(res i=1;i<=q;i++)printf("%d\n",ans[i]>=inf?-1:ans[i]);
    }
}
int main(){
//    srand(19260817);
//    freopen("signin.in","r",stdin);
//    freopen("signin.out","w",stdout);
    MAIN::MAIN();
    return 0;
}