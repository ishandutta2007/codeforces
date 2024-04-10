//2020.3.7 by ljz
//#pragma GCC optimize(2)
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
#define eps 1e-9
#define RG register
#define db double
//#define pc(x) __builtin_popcount(x)
#define ct(x) __builtin_ctzll(x)
#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
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
//inline void print(res x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);sr[++C]='\n';
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
int kcz=998244353;
const int N=1e6+10;
namespace MAIN{
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
    inline int sqr(const res &x){
        return int(1LL*x*x%kcz);
    }
    inline int qpow(res x,res y){
        res ret=1;
        while(y){
            if(y&1)ret=mul(ret,x);
            x=mul(x,x),y>>=1;
        }
        return ret;
    }
    inline LL Qpow(RG LL x,res y){
        RG LL ret=1;
        while(y){
            if(y&1)ret*=x;
            x*=x,y>>=1;
        }
        return ret;
    }
    int n;
    char str[N];
    int s0[N],s1[N];
    inline void MAIN(){
        n=read(),scanf("%s",str+1);
        for(res i=1;i<=n;i++)s0[i]=s0[i-1]+(str[i]=='('),s1[i]=s1[i-1]+(str[i]==')');
        if(s0[n]!=s1[n]){puts("-1");return;}
        res c0=0,c1=0,ans=0,fl=0;
        for(res i=1;i<=n;i++){
            if(str[i]=='(')c0++;
            else c1++;
            if(c0+c1==1)fl=(c1==1);
            if(c0==c1)ans+=(c0+c1)*fl,c0=c1=0;
        }
        printf("%d\n",ans);
    }
}
int main(){
//    freopen("money.in","r",stdin);
//    freopen("money.out","w",stdout);
//    srand(19260817);
    MAIN::MAIN();
//    Ot();
    return 0;
}