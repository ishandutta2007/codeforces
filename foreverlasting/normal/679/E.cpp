//2019.7.3 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 1100005
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
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e5+10;
const LL pw[]={1LL,42LL,1764LL,74088LL,3111696LL,130691232LL,5489031744LL,230539333248LL,9682651996416LL,406671383849472LL,17080198121677824LL,717368321110468608LL};
namespace MAIN{
    int n,q;
    LL di[N<<2],ad[N<<2],co[N<<2];
    int lo[N<<2];
    inline int Log(const RG LL &x){
        return int(lower_bound(pw,pw+12,x)-pw);
    }
    void build(res rt,res l,res r){
//        L[rt]=l,R[rt]=r;
        if(l==r){
            res x=read();
            lo[rt]=Log(x),di[rt]=pw[lo[rt]]-x;
            return;
        }
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
        di[rt]=min(di[rt<<1],di[rt<<1|1]);
    }
//    inline void Change(const res &rt,const RG LL &Co,const RG LL &Ad){
//        if(Co)lo[rt]=Log(Co),di[rt]=pw[lo[rt]]-Co,co[rt]=Co,ad[rt]=0,val[rt]=Co;
//        if(Ad)di[rt]-=Ad,ad[rt]+=Ad,val[rt]+=Ad;
//    }
//    inline void Pushdown(const res &rt){
//        Change(rt<<1,co[rt],ad[rt]),Change(rt<<1|1,co[rt],ad[rt]),co[rt]=ad[rt]=0;
//    }
//    void rebuild(res rt,res l,res r){
//        if(l==r){
//            lo[rt]=Log(val[rt]),di[rt]=pw[lo[rt]]-val[rt];
//            return;
//        }
//        Pushdown(rt);
//        res mid=(l+r)>>1;
//        rebuild(rt<<1,l,mid),rebuild(rt<<1|1,mid+1,r);
//        di[rt]=min(di[rt<<1],di[rt<<1|1]);
//    }
//    inline void change(const res &rt,const RG LL &Co,const RG LL &Ad){
//        if(Co)lo[rt]=Log(Co),di[rt]=pw[lo[rt]]-Co,co[rt]=Co,ad[rt]=0;
//        if(Ad){
//            if(co[rt])co[rt]+=Ad;
//            else di[rt]-=Ad,ad[rt]+=Ad;
//        }
////        if(di[rt]<0)rebuild(rt,L[rt],R[rt]);
//    }
    inline void add(const res &rt,const RG LL &Ad){
        co[rt]?co[rt]+=Ad:ad[rt]+=Ad,di[rt]-=Ad;
    }
    inline void cov(const res &rt,const RG LL &Co){
        lo[rt]=Log(Co),di[rt]=pw[lo[rt]]-Co,co[rt]=Co,ad[rt]=0;
    }
    inline void pushdown(const res &rt){
        if(!co[rt]&&!ad[rt])return;
        if(co[rt])cov(rt<<1,co[rt]),cov(rt<<1|1,co[rt]),co[rt]=0;
        if(ad[rt])add(rt<<1,ad[rt]),add(rt<<1|1,ad[rt]),ad[rt]=0;
    }
    void modify(res rt,res l,res r,const res &L,const res &R,const res &co,const res &ad){
        if(L<=l&&r<=R){co?cov(rt,co):add(rt,ad);return;}
        pushdown(rt);
        res mid=(l+r)>>1;
        if(L<=mid)modify(rt<<1,l,mid,L,R,co,ad);
        if(R>mid)modify(rt<<1|1,mid+1,r,L,R,co,ad);
        di[rt]=min(di[rt<<1],di[rt<<1|1]);
    }
    LL get(res rt,res l,res r,const res &p){
        if(l==r)return pw[lo[rt]]-di[rt];
        pushdown(rt);
        res mid=(l+r)>>1;
        if(p<=mid)return get(rt<<1,l,mid,p);
        return get(rt<<1|1,mid+1,r,p);
    }
    LL query(res rt,res l,res r){
        if(di[rt]>=0)return di[rt];
        if(l==r){
            RG LL x=pw[lo[rt]]-di[rt];
            lo[rt]=Log(x),di[rt]=pw[lo[rt]]-x;
            return di[rt];
        }
        pushdown(rt);
        res mid=(l+r)>>1;
        query(rt<<1,l,mid),query(rt<<1|1,mid+1,r),di[rt]=min(di[rt<<1],di[rt<<1|1]);
        return di[rt];
    }
    inline void MAIN(){
        n=read(),q=read(),build(1,1,n);
        while(q--){
            res opt=read();
            if(opt==2){
                res l=read(),r=read(),x=read();
                modify(1,1,n,l,r,x,0);
            }
            else if(opt==1){
                res p=read();
                printf("%lld\n",get(1,1,n,p));
            }
            else{
                res l=read(),r=read(),x=read();
                modify(1,1,n,l,r,0,x);
                while(!query(1,1,n))modify(1,1,n,l,r,0,x);
            }
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