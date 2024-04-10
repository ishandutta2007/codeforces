//2021.10.29 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res register int
#define LL long long
#define Inf 0x3f3f3f3f
#define sup 0x7fffffff
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
//#define unl __int128
#define eps 1e-5
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
//#define ctz(x) __builtin_ctz(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
//#define poly vector<int>
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
//inline void print(RG LL x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);
//}
template <typename T> inline void Read(T &x) {
    res c=gc();
    bool f=false;
    for(x=0;!isdigit(c);c=gc())if(c=='-')f=true;
    for(;isdigit(c);c=gc())x=x*10+c-'0';
    if(f)x=-x;
}
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
inline LL Read() {
    RG LL s=0;
    res ch=gc(),w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
//inline void write(RG unl x){
//    if(x>10)write(x/10);
//    putchar(int(x%10)+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
const int kcz=1000000007;
const int G=3,GI=332748118;
//inline void add(res &x,const res &y){
//    x+=y,x>=kcz?x-=kcz:1;
//}
//inline int Add(const res &x,const res &y){
//    return x+y>=kcz?x+y-kcz:x+y;
//}
inline int mul(const res &x,const res &y){
    return int(1ll*x*y%kcz);
}
#define add(x,y) (x+=y,x>=kcz?x-=kcz:1)
#define Add(x,y) (x+y>=kcz?x+y-kcz:x+y)
//#define mul(x,y) int(1ll*x*y%kcz)
#define Mul(x,y,d) int((ull)x*y/d%kcz)
inline int qpow(res x,res y=kcz-2){
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
inline int qpow(res x,res y,const res &ljc){
    res ret=1;
    while(y){
        if(y&1)ret=int(1ll*ret*x%ljc);
        x=int(1ll*x*x%ljc),y>>=1;
    }
    return ret;
}
//mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2021.10.29 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=5e3+10;
namespace MAIN{
    LL f[N][N];
    int a[N],b[N],c[N],d[N],x[N];
    inline void MAIN(){
        res n=read(),s=read(),t=read();
        for(res i=1;i<=n;i++)x[i]=read();
        for(res i=1;i<=n;i++)a[i]=read()+x[i];
        for(res i=1;i<=n;i++)b[i]=read()-x[i];
        for(res i=1;i<=n;i++)c[i]=read()+x[i];
        for(res i=1;i<=n;i++)d[i]=read()-x[i];
        memset(f,0x3f,sizeof(f));
        f[0][0]=0;
        for(res i=1;i<=n;i++){
            for(res j=0;j<i;j++){
                if(i!=s&&i!=t){
                    if(i<max(s,t)||j>1)f[i][j+1]=min(f[i][j+1],f[i-1][j]+b[i]+d[i]);
                    if(j>1)f[i][j-1]=min(f[i][j-1],f[i-1][j]+a[i]+c[i]);
                    if(j&&(j>1||i<t))f[i][j]=min(f[i][j],f[i-1][j]+a[i]+d[i]);
                    if(j&&(j>1||i<s))f[i][j]=min(f[i][j],f[i-1][j]+b[i]+c[i]);
                }
                else if(i==s){
                    f[i][j+1]=min(f[i][j+1],f[i-1][j]+d[i]);
                    if(j)f[i][j]=min(f[i][j],f[i-1][j]+c[i]);
                }
                else {
                    f[i][j+1]=min(f[i][j+1],f[i-1][j]+b[i]);
                    if(j)f[i][j]=min(f[i][j],f[i-1][j]+a[i]);
                }
            }
        }
        printf("%lld\n",f[n][1]);
    }
}
int main(){
//    srand(19260817);
//    freopen("data.in","r",stdin);
//    freopen("1.out","fw",stdout);
    res Case=1;
    while(Case--)MAIN::MAIN();
//    Ot();
    return 0;
}