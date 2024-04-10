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
const int N=2e5+10;
namespace MAIN{
    int n;
    int a[N];
    vector<int> vec[N];
    struct P{
//        int pre,suf,sum,ans;
//        inline P operator + (const RG P &x){
//            RG P y;
//            y.pre=max(pre,sum+x.pre);
//            y.suf=max(x.suf,x.sum+suf);
//            y.sum=sum+x.sum;
//            y.ans=max({ans,x.ans,suf+x.pre});
//            return y;
//        }
//        inline void init(){
//            pre=suf=ans=0,sum=-1;
//        }
//        inline void change(){
//            pre=suf=sum=ans=1;
//        }
        int mx,mn;
        P() {}
        P(res a,res b) {mx=a,mn=b;}
        inline void init(const res &p){
            mx=mn=-p;
        }
        inline P operator + (const RG P &x){
            RG P y;
            y.mx=max(mx,x.mx),y.mn=min(mn,x.mn);
            return y;
        }
        inline void change(const res &val){
            mx+=val,mn+=val;
        }
        inline void print(){
            printf("%d %d\n",mx,mn);
        }
    }tr[N<<2];
    int laz[N<<2];
    inline void pushup(const res &rt){
        tr[rt]=tr[rt<<1]+tr[rt<<1|1];
    }
    void build(res rt,res l,res r){
        laz[rt]=0;
        if(l==r){tr[rt].init(l);return;}
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r),pushup(rt);
//        tr[rt].print();
    }
    inline void pushdown(const res &rt){
        if(laz[rt])tr[rt<<1].change(laz[rt]),laz[rt<<1]+=laz[rt],tr[rt<<1|1].change(laz[rt]),laz[rt<<1|1]+=laz[rt],laz[rt]=0;
    }
    void modify(res rt,res l,res r,const res &L,const res &R){
        if(L<=l&&r<=R){tr[rt].change(2),laz[rt]+=2;return;}
        res mid=(l+r)>>1;
        pushdown(rt);
        if(L<=mid)modify(rt<<1,l,mid,L,R);
        if(R>mid)modify(rt<<1|1,mid+1,r,L,R);
        pushup(rt);
    }
    P query(res rt,res l,res r,const res &L,const res &R){
        if(L<=l&&r<=R)return tr[rt];
        res mid=(l+r)>>1;
        RG P ret=P(-inf,inf);
        pushdown(rt);
        if(L<=mid)ret=query(rt<<1,l,mid,L,R);
        if(R>mid)ret=ret+query(rt<<1|1,mid+1,r,L,R);
        pushup(rt);
        return ret;
    }
    int ans[N];
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)a[i]=read(),vec[a[i]].pb(i);
        build(1,0,n);
        for(res i=1;i<=n;i++){
            for(auto x:vec[i])modify(1,0,n,x,n);
            for(auto x:vec[i])ans[x]=(query(1,0,n,x,n).mx-query(1,0,n,0,x-1).mn-1)/2;
        }
        build(1,0,n);
        for(res i=n;i;i--){
            for(auto x:vec[i])modify(1,0,n,x,n);
            for(auto x:vec[i])ans[x]=max(ans[x],(query(1,0,n,x,n).mx-query(1,0,n,0,x-1).mn)/2);
        }
        for(res i=1;i<=n;i++)printf("%d ",ans[i]);
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