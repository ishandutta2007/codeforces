//2019.6.13 by ljz
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
#define pb push_back
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
//inline void swap(res &x,res &y) {
//    x^=y^=x^=y;
//}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6+10;
namespace MAIN {
    int n,m;
    LL kcz;
    LL sum[N<<2];
    typedef vector<LL> vec;
    vec f[N<<2];
    inline void pushup(const res &rt){
        res ls=rt<<1,rs=rt<<1|1;
        RG vec a=f[ls],b=f[rs],&c=f[rt];
        res sza=int(a.size())-1,szb=int(b.size())-1,j=1;
        sum[rt]=sum[ls]+sum[rs];
        c.resize(sza+szb+1);
        for(res i=0;i<=sza;i++){
            RG LL gr=sum[ls]-i*kcz,fr=(i==sza?INF:a[i+1])+gr;
            j--;
            while(j<=szb&&b[j]<fr)c[i+j]=max(a[i],b[j]-gr),j++;
        }
        c[0]=-INF;
    }
    void build(res rt,res l,res r){
        if(l==r){sum[rt]=read(),f[rt].pb(-INF),f[rt].pb(kcz-sum[rt]);return;}
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r),pushup(rt);
    }
    LL query(res rt,res l,res r,const res &L,const res &R,RG LL now){
        if(L<=l&&r<=R)return now+sum[rt]-kcz*(upper_bound(f[rt].begin(),f[rt].end(),now)-f[rt].begin()-1);
        res mid=(l+r)>>1;
        if(R<=mid)return query(rt<<1,l,mid,L,R,now);
        if(L>mid)return query(rt<<1|1,mid+1,r,L,R,now);
        return query(rt<<1|1,mid+1,r,mid+1,R,query(rt<<1,l,mid,L,mid,now));
    }
    inline void MAIN(){
        n=read(),m=read(),kcz=read(),build(1,1,n);
        while(m--){
            res l=read(),r=read();
            printf("%lld\n",query(1,1,n,l,r,0));
        }
    }
}
int main() {
//    srand((unsigned)time(NULL));
    // freopen("zao.in","r",stdin);
    // freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}