//2021.7.25 by ljz
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
#define INF 0x8000000000000000ll
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
int kcz=998244353;
inline void add(res &x,const res &y){
    x+=y,x>=kcz?x-=kcz:1;
}
inline int Add(const res &x,const res &y){
    return x+y>=kcz?x+y-kcz:x+y;
}
inline int mul(const res &x,const res &y){
    return int(1LL*x*y%kcz);
}
inline int mul(const res &x,const res &y,const res &d){
    return int(1LL*x*y/d%kcz);
}
inline int sqr(const res &x){
    return mul(x,x);
}
inline int dou(const res &x){
    return Add(x,x);
}
inline int qpow(res x,res y=kcz-2){
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
//2021.7.25 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=1e6+10;
namespace MAIN{
    int pw[N],f[N],n;
    struct P{
        int x,y,s;
        P() {}
        P(res x,res y,res s):x(x),y(y),s(s) {}
    }a[N];
    int tr[N];
    inline void modify(const res &x,const res &y){
        for(res i=x;i<=N-10;i+=lowbit(i))add(tr[i],y);
    }
    inline int query(const res &x){
        res ret=0;
        for(res i=x;i;i-=lowbit(i))add(ret,tr[i]);
        return ret;
    }
    int o[N*2];
    inline void MAIN(){
        n=read();
        pw[0]=1;
        for(res i=1;i<=n;i++)pw[i]=Add(pw[i-1],pw[i-1]);
        res xx=0;
        for(res i=1;i<=n;i++){
            res x=read(),y=read(),s=read();
            a[i]=P(x,y,s),o[++xx]=x,o[++xx]=y;
        }
        sort(o+1,o+xx+1),xx=unique(o+1,o+xx+1)-o-1;
        for(res i=1;i<=n;i++)a[i].x=lower_bound(o+1,o+xx+1,a[i].x)-o,a[i].y=lower_bound(o+1,o+xx+1,a[i].y)-o;
        for(res i=n;i;i--){
            if(a[i].s==0)f[i]=(2*query(a[i].x)+1)/2;
            else f[i]=(2*query(a[i].x)+1)/2+1;
            modify(a[i].y,f[i]);
//            printf("%d\n",f[i]);
        }
        res ans=0;
        for(res i=1;i<=n;i++)add(ans,mul(f[i],o[a[i].x]-o[a[i].y]));
        printf("%d\n",Add(ans,Add(o[a[n].x],1)));
    }
}
int main(){
//    srand(19260817);
//     freopen("1.out","r",stdin);
//    freopen("tracing.out","w",stdout);
    MAIN::MAIN();
//    Ot();
    return 0;
}