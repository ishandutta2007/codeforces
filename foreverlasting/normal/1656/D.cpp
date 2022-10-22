//2022.3.24 by ljz
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
#define INF 1000000000000000000
#define unl __int128
#define eps 1e-10
#define RG
#define db double
#define pc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define poly vector<int>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define uint unsigned int
#define lowbit(x) ((x)&-(x))
#define gc getchar
#define ld long db
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//inline int gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
//char sr[1<<21],z[20];
//int C=-1,Z=0;
//inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
//inline void print(RG LL x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);
//}
//template <typename T> inline void Read(T &x) {
//    res c=gc();
//    bool f=false;
//    for(x=0;!isdigit(c);c=gc())if(c=='-')f=true;
//    for(;isdigit(c);c=gc())x=x*10+c-'0';
//    if(f)x=-x;
//}
inline int read() {
    res s=0,ch=gc(),w=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        else if(ch==EOF)break;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
inline LL Read() {
    RG LL s=0;
    res ch=gc(),w=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        else if(ch==EOF)break;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
inline void write(RG __int128 x){
    if(x>10)write(x/10);
    putchar(int(x%10)+'0');
}
//const int kcz=1000000007;
//const int G=3,GI=332748118;
//inline void add(res &x,const res &y){
//    x+=y,x>=kcz?x-=kcz:1;
//}
//inline int Add(const res &x,const res &y){
//    return x+y>=kcz?x+y-kcz:x+y;
//}
//inline int mul(const res &x,const res &y){
//    return int(1ll*x*y%kcz);
//}
//#define add(x,y) ((x)+=(y),(x)>=kcz?(x)-=kcz:1)
//#define Add(x,y) ((x)+(y)>=kcz?(x)+(y)-kcz:(x)+(y))
//#define mul(x,y) (int)((LL)(x)*(y)%kcz)
//#define Mul(x,y,d) (int)((ull)(x)*(y)/(d)%kcz)
//inline int qpow(res x,res y=kcz-2){
//    res ret=1;
//    while(y){
//        if(y&1)ret=mul(ret,x);
//        x=mul(x,x),y>>=1;
//    }
//    return ret;
//}
//inline int qpow(res x,res y,const res &ljc){
//    res ret=1;
//    while(y){
//        if(y&1)ret=(int)(1ll*ret*x%ljc);
//        x=(int)(1ll*x*x%ljc),y>>=1;
//    }
//    return ret;
//}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2022.3.24 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=2e5+10;
const int base[]={2,3,5,7,11,13,17,19,23,29,31,37};
namespace MAIN{
    inline LL mul(const LL &x,const LL &y,const LL &kcz){
        LL tmp=x*y-((LL)((long double)x/kcz*y+0.5))*kcz;
        return tmp<0?tmp+kcz:tmp;
    }
    inline LL qpow(LL x,LL y,const LL &kcz){
        LL ret=1;
        while(y){
            if(y&1)ret=mul(ret,x,kcz);
            x=mul(x,x,kcz),y>>=1;
        }
        return ret;
    }
    inline bool Miller_Rabin(const LL &n){
        if(n==1)return 0;
        if(n==2)return 1;
        if(!(n&1))return 0;
        LL t=n-1;
        RG int now=0;
        while(!(t&1))t>>=1,now++;
        for(RG int i=0;i<=11;i++){
            if(base[i]==n)return 1;
            LL x=qpow(base[i],t,n),y=x;
            for(RG int j=1;j<=now;j++){
                x=mul(x,x,n);
                if(x==1&&!(y==1||y==n-1))return 0;
                y=x;
            }
            if(x!=1)return 0;
        }
        return 1;
    }
    int step=1<<9;
    inline LL Add(const LL &x,const LL &y,const LL &kcz){
        return x+y>=kcz?x+y-kcz:x+y;
    }
    inline LL Pollard_Rho(const LL &n,const LL &seed){
        LL x=2,y=2,z,g;
        for(RG int l=1;;l<<=1){
            x=y;
            for(RG int i=0;i<l;i++)y=Add(mul(y,y,n),seed,n);
            for(RG int k=0;k<l;k+=step){
                RG int e=min(step,l-k);
                g=1,z=y;
                for(RG int i=0;i<e;i++)y=Add(mul(y,y,n),seed,n),g=mul(g,y+n-x,n);
                g=gcd(g,n);
                if(g==1)continue;
                if(g==n)for(g=1,y=z;g==1;)y=Add(mul(y,y,n),seed,n),g=gcd(y+n-x,n);
                return g;
            }
        }
    }
    LL solve(const LL &n){
        if(n==2)return INF;
        if(Miller_Rabin(n))return n;
        RG int i=1;
        LL tmp;
        for(tmp=Pollard_Rho(n,i);tmp==n;i++,tmp=Pollard_Rho(n,i));
        return min(solve(tmp),solve(n/tmp));
    }
    inline void MAIN(const res &Case){
        LL n=Read();
        if(n&1)puts("2");
        else {
            LL m=1;
            while(n%m==0)m<<=1;
            if(m+1<=((ld)n*2)/m)printf("%lld\n",m);
            else if(n>=6&&n%3==0)puts("3");
            else {
                LL x=solve(n);
                if(x+1<=((ld)n*2)/x)printf("%lld\n",x);
                else puts("-1");
            }
        }
    }
}
int main(){
//    srand(time(0));
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    res Case=read();
    for(res T=1;T<=Case;T++)MAIN::MAIN(T);
//    Ot();
    return 0;
}