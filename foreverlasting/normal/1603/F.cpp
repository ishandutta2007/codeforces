//2021.12.5 by ljz
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
#define Inf 0x3f3f3f3f
#define sup 0x7fffffff
#define inf 0x3f3f3f3f
#define INF 2000000000000000000
//#define unl __int128
#define eps 1e-5
#define RG
#define db double
#define pc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
//#define poly vector<int>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define uint unsigned int
#define lowbit(x) ((x)&-(x))
#define gc getchar
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//inline int gc() {
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
const int kcz=998244353;
const int G=3,GI=332748118;
//inline void add(res &x,const res &y){
//    x+=y,x>=kcz?x-=kcz:1;
//}
//inline int Add(const res &x,const res &y){
//    return x+y>=kcz?x+y-kcz:x+y;
//}
//inline int mul(const res &x,const res &y){
//    return int(1ll*x*y%kcz);
//}
#define add(x,y) ((x)+=(y),(x)>=kcz?(x)-=kcz:1)
#define Add(x,y) ((x)+(y)>=kcz?(x)+(y)-kcz:(x)+(y))
#define mul(x,y) int(1ll*(x)*(y)%kcz)
#define Mul(x,y,d) int((ull)(x)*(y)/(d)%kcz)
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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2021.12.5 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=1e7+10;
int pw[N],fac[N],inv[N],INV[N];
namespace MAIN{
    int n,k,x;
    int f[N];
    inline void MAIN(){
        n=read(),k=read(),x=read();
        if(!x){
            if(n>k){puts("0");return;}
            res ret=1;
            for(res i=0;i<n;i++)ret=mul(ret,Add(pw[k],kcz-pw[i]));
            printf("%d\n",ret);
            return;
        }
        f[0]=1;
        res p=min(n,k),PW=qpow(2,n),inv2=qpow(2);
        for(res i=1;i<=p;i++)f[i]=mul(f[i-1],mul(Add(PW,kcz-1),INV[i])),PW=mul(PW,inv2);
        res A=1,ans=1;
        for(res r=1;r<=p;r++)A=mul(A,Add(pw[k],kcz-pw[r])),add(ans,mul(A,f[r]));
        printf("%d\n",ans);
    }
}
int main(){
//    srand(19260817);
//    freopen("data.in","r",stdin);
//    freopen("1.out","w",stdout);
    pw[0]=fac[0]=1;
    for(res i=1;i<=N-10;i++)pw[i]=Add(pw[i-1],pw[i-1]);
    for(res i=1;i<=N-10;i++)fac[i]=mul(fac[i-1],Add(pw[i],kcz-1));
    inv[N-10]=qpow(fac[N-10]),INV[N-10]=mul(inv[N-10],fac[N-11]);
    for(res i=N-11;i;i--)inv[i]=mul(inv[i+1],Add(pw[i+1],kcz-1)),INV[i]=mul(inv[i],fac[i-1]);
    res Case=read();
    while(Case--)MAIN::MAIN();
//    Ot();
    return 0;
}