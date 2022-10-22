//2019.8.27 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;
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
const int N=1e6+10;
namespace MAIN{
    int n,w;
    LL ans[N],Ans[N];
    int a[N];
    int mx[N<<2];
    void build(res rt,res l,res r){
        if(l==r){mx[rt]=a[l];return;}
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r),mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
    }
    int querymx(res rt,res l,res r,const res &L,const res &R){
        if(L<=l&&r<=R)return mx[rt];
        res mid=(l+r)>>1;
        if(L<=mid&&R>mid)return max(querymx(rt<<1,l,mid,L,R),querymx(rt<<1|1,mid+1,r,L,R));
        if(L<=mid)return querymx(rt<<1,l,mid,L,R);
        return querymx(rt<<1|1,mid+1,r,L,R);
    }
    inline void MAIN(){
        n=read(),w=read();
        while(n--){
            res l=read();
            for(res i=1;i<=l;i++)a[i]=read();
            if(l*2<=w){
                res mx=0;
                for(res i=1;i<=l;i++)mx=max(a[i],mx),ans[i]+=mx;
                Ans[l+1]+=mx,Ans[w-l+1]-=mx,mx=0;
                for(res i=w;i>=w-l+1;i--)mx=max(mx,a[i+l-w]),ans[i]+=mx;
            }
            else {
                a[l+1]=0,build(1,0,l+1);
                res p=w-l;
                for(res i=1;i<=w;i++)ans[i]+=querymx(1,0,l+1,max(0,i-p),min(i,l+1));
            }
        }
        for(res i=2;i<=w;i++)Ans[i]+=Ans[i-1];
        for(res i=1;i<=w;i++)printf("%lld ",ans[i]+Ans[i]);
    }
}
int main(){
//    srand(19260817);
//    freopen("signin.in","r",stdin);
//    freopen("signin.out","w",stdout);
    MAIN::MAIN();
    return 0;
}