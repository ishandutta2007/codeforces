//2021.6.23 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
//#define unl __int128
#define eps 5.6e-8
#define RG
#define db double
//#define pc(x) __builtin_popcount(x)
//#define ctz(x) __builtin_ctz(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define lowbit(x) (x&-x)
#define gc getchar
#define kcz 998244353
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
// }
//inline int read() {
//    res s=0,ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
// char sr[1<<21],z[20];
// int C=-1,Z=0;
// inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
// inline void print(res x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);
// }
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
inline int qpow(res x,res y){
    if(y<=0)return 1;
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2021.6.23 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=1e5+10;
namespace MAIN{
    int n,m;
    int k[N],al[N],ar[N],bl[N],br[N];
    int L[N][2],R[N][2];
    inline bool ck(const res &i,const res &x,const res &y){
        return al[i]<=x&&x<=bl[i]&&ar[i]<=y&&y<=br[i];
    }
    inline bool Ck(const res &i,const res &x,const res &y){
        return (L[i][0]<=x&&x<=L[i][1])||(R[i][0]<=y&&y<=R[i][1]);
    }
//    int dp[N][N];
//    void dfs(res x){
//        if(x==1)return;
//        dfs(x-1);
//        for(res i=0;i<=x-2;i++){
//            if(dp[x-1][i]){
//                if(ck(x,x,i))dp[x][i]=1;
//                if(ck(x,x-1,x))dp[x-1][x]=1;
//            }
//        }
//        for(res i=0;i<=x-2;i++){
//            if(dp[i][x-1]){
//                if(ck(x,i,x))dp[i][x]=1;
//                if(ck(x,x,x-1))dp[x][x-1]=1;
//            }
//        }
//    }
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=n;i++)k[i]=read(),al[i]=read(),bl[i]=read(),ar[i]=read(),br[i]=read();
//        if(ck(1,1,0))dp[1][0]=1;
//        if(ck(1,0,1))dp[0][1]=1;
//        dfs(n);
        L[n+1][0]=0,L[n+1][1]=m,R[n+1][0]=0,R[n+1][1]=m;
        for(res i=n;i>=1;i--){
            L[i][0]=m+1,L[i][1]=-1,R[i][0]=m+1,R[i][1]=-1;
            if(al[i]<=k[i]&&k[i]<=bl[i]){
                if(L[i+1][0]<=k[i]&&k[i]<=L[i+1][1])R[i][0]=ar[i],R[i][1]=br[i];
                else R[i][0]=max(R[i+1][0],ar[i]),R[i][1]=min(R[i+1][1],br[i]);
            }
            if(ar[i]<=k[i]&&k[i]<=br[i]){
                if(R[i+1][0]<=k[i]&&k[i]<=R[i+1][1])L[i][0]=al[i],L[i][1]=bl[i];
                else L[i][0]=max(L[i+1][0],al[i]),L[i][1]=min(L[i+1][1],bl[i]);
            }
        }
        if(Ck(1,0,0)){
            puts("Yes");
            res y=0;
            for(res i=1;i<=n;i++){
                if(ck(i,k[i],y)&&Ck(i+1,k[i],y))printf("%d ",0);
                else y=k[i],printf("%d ",1);
            }
        }
        else puts("No");
    }
}
int main(){
//    srand(19260817);
    // freopen("tracing.in","r",stdin);
    // freopen("tracing.out","w",stdout);
    MAIN::MAIN();
//    Ot();
    return 0;
}