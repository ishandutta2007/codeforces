//2019.7.18 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define eps 1e-10
#define RG register
#define db long double
#define lb long db
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
//inline void write(RG __int128 x){
//    if(x>10)write(x/10);
//    putchar(x%10+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=5e5+10;
namespace MAIN{
    int n;
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
    int sz[N];
    void dfs(res x,res fax){
        sz[x]=1;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            dfs(tox,x),sz[x]+=sz[tox];
        }
    }
    LL ans[N];
    void Dfs(res x,res fax){
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            ans[tox]=ans[x]+1LL*(sz[x]-sz[tox])*sz[tox],Dfs(tox,x);
        }
    }
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)head[i]=-1;
        for(res i=1;i<n;i++)addedge(read(),read());
        dfs(1,0),ans[1]=1LL*n*(n-1)/2,Dfs(1,0);
        res id=2;
        for(res i=3;i<=n;i++)if(ans[i]>ans[id])id=i;
        dfs(id,0),ans[id]=1LL*n*(n-1)/2,Dfs(id,0);
        RG LL ret=0;
        for(res i=1;i<=n;i++)if(i!=id)ret=max(ret,ans[i]);
        printf("%lld\n",ret);
    }
}
int main() {
//    srand((unsigned)time(NULL));
//    freopen("route.in","r",stdin);
//    freopen("route.out","w",stdout);
    MAIN::MAIN();
    return 0;
}