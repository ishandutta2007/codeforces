//2019.6.7 by ljz
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
//inline void add(res &x,const res &y,const res &kcz){
//    x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
//}
//inline int Add(const res &x,const res &y,const res &kcz){
//    return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
//}
//inline int mul(const res &x,const res &y,const res &kcz){
//    return int(1LL*x*y%kcz);
//}
//inline int qpow(res x,res y,const res &kcz){
//    res ret=1;
//    while(y){
//        if(y&1)ret=mul(ret,x,kcz);
//        y>>=1,x=mul(x,x,kcz);
//    }
//    return ret;
//}
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
//inline void swap(res &x,res &y) {
//    x^=y^=x^=y;
//}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5+10;
const int kcz=998244353;
namespace MAIN {
    int n;
    struct E{
        int next,to;
        E() {}
        E(res next,res to):next(next),to(to) {}
    }edge[N<<1];
    int head[N],cnt,du[N];
    inline void addedge(const res &u,const res &v){
        edge[++cnt]=E(head[u],v),head[u]=cnt,du[u]++;
        edge[++cnt]=E(head[v],u),head[v]=cnt,du[v]++;
    }
    int ans=1,fac[N];
    inline int mul(const res &x,const res &y,const res &kcz){
        return int(1LL*x*y%kcz);
    }
    inline void MAIN(){
        n=read(),fac[0]=1;
        for(res i=1;i<=n+1;i++)head[i]=-1,fac[i]=mul(fac[i-1],i,kcz);
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            addedge(u,v);
        }
        for(res x=1;x<=n;x++)ans=mul(ans,fac[du[x]],kcz);
        printf("%d\n",mul(ans,n,kcz));
    }
}
int main() {
//    srand((unsigned)time(NULL));
    // freopen("zao.in","r",stdin);
    // freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}