//2019.6.15 by ljz
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
typedef pair<LL,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
inline void add(res &x,const res &y,const res &kcz){
    x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
}
inline int Add(const res &x,const res &y,const res &kcz){
    return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
}
inline int mul(const res &x,const res &y,const res &kcz){
    return int(1LL*x*y%kcz);
}
inline int qpow(res x,res y,const res &kcz){
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x,kcz);
        y>>=1,x=mul(x,x,kcz);
    }
    return ret;
}
#define gc getchar
//inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
inline int read() {
    res s=0,ch=gc();
    while(ch<'0'||ch>'9')ch=gc();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s;
}
//inline int read() {
//    res s=0,ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
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
const int N=1e5+10;
namespace MAIN {
    int n,m,seed,vmax;
    inline int rnd(){
        res ret=seed;
        seed=Add(mul(seed,7,1000000007),13,1000000007);
        return ret;
    }
    struct P{
        int l,r;
        mutable LL val;
        P() {}
        P(res l,res r,RG LL val):l(l),r(r),val(val) {}
        inline bool operator < (const P &b) const {
            return l<b.l;
        }
    };
    set<P> S;
    typedef set<P>::iterator it;
#define Split RG it q=split(r+1),p=split(l);
    inline it split(const res &l){
        RG it I=S.lower_bound(P(l,-1,0));
        if(I!=S.end()&&I->l==l)return I;
        I--;
        RG P o=*I;
        S.erase(I),S.insert(P(o.l,l-1,o.val));
        return S.insert(P(l,o.r,o.val)).fi;
    }
    inline void mod(const res &l,const res &r,const res &val){
        Split for(RG it i=p;i!=q;i++)i->val+=val;
    }
    inline void cov(const res &l,const res &r,const res &val){
        Split S.erase(p,q),S.insert(P(l,r,val));
    }
    Pair vec[N];
    int vecx,ret;
    inline LL kth(const res &l,const res &r,res k){
        Split vecx=0;
        for(RG it i=p;i!=q;i++)vec[++vecx]=mp(i->val,i->r-i->l+1);
        sort(vec+1,vec+vecx+1);
        for(res i=1;i<=vecx;i++){
            k-=vec[i].se;
            if(k<=0)return vec[i].fi;
        }
    }
    inline int query(const res &l,const res &r,const res &x,const res &kcz){
        Split ret=0;
        for(RG it i=p;i!=q;i++)add(ret,mul(i->r-i->l+1,qpow(int(i->val%kcz),x,kcz),kcz),kcz);
        return ret;
    }
    inline void MAIN(){
        n=read(),m=read(),seed=read(),vmax=read();
        for(res i=1;i<=n;i++)S.insert(P(i,i,rnd()%vmax+1));
        S.insert(P(n+1,n+1,0));
        while(m--){
            res op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x,kcz=0;
            if(l>r)swap(l,r);
            if(op==3)x=rnd()%(r-l+1)+1;
            else x=rnd()%vmax+1;
            if(op==4)kcz=rnd()%vmax+1;
            if(op==1)mod(l,r,x);
            if(op==2)cov(l,r,x);
            if(op==3)printf("%lld\n",kth(l,r,x));
            if(op==4)printf("%d\n",query(l,r,x,kcz));
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