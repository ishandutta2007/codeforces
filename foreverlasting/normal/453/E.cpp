//2021.11.30 by ljz
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
const int kcz=1000000001;
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
//2021.11.30 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=2e5+10;
namespace MAIN{
    int n;
#define tup tuple<int,int,int>
    set<tup> S;
    int s[N],m[N],u[N];
    set<int> T;
    int ls[N*30],rs[N*30],tot;
    pair<LL,LL> su[N*30];
    inline pair<LL,LL> operator + (pair<LL,LL> a,pair<LL,LL> b){
        return mp(a.fi+b.fi,a.se+b.se);
    }
    void build(res &rt,res l,res r){
        rt=++tot;
        if(l==r){su[rt]=mp(u[l],0ll);return;}
        res mid=(l+r)>>1;
        build(ls[rt],l,mid),build(rs[rt],mid+1,r),su[rt]=su[ls[rt]]+su[rs[rt]];
    }
    void insert(res &rt,res RT,res l,res r,const res &p){
        rt=++tot;
        ls[rt]=ls[RT],rs[rt]=rs[RT],su[rt]=su[RT];
        if(l==r){if(u[l])su[rt]=mp(0ll,m[l]);return;}
        res mid=(l+r)>>1;
        if(p<=mid)insert(ls[rt],ls[RT],l,mid,p);
        else insert(rs[rt],rs[RT],mid+1,r,p);
        su[rt]=su[ls[rt]]+su[rs[rt]];
    }
    pair<LL,LL> query(res rt,res l,res r,const res &L,const res &R){
        if(!rt)return su[rt];
        if(L<=l&&r<=R)return su[rt];
        res mid=(l+r)>>1;
        RG pair<LL,LL> ret=mp(0ll,0ll);
        if(L<=mid)ret=query(ls[rt],l,mid,L,R);
        if(R>mid)ret=ret+query(rs[rt],mid+1,r,L,R);
        return ret;
    }
    int rt[N];
    int id[N];
    inline bool cmp(const res &A,const res &B){
        if(!u[A])return 0;
        if(!u[B])return 1;
        return (LL)m[A]*u[B]-(LL)m[B]*u[A]<0;
    }
    inline pair<LL,LL> calc(const res &L,const res &R,const res &t){
        res l=0,r=n,ret=0;
        while(l<=r){
            res mid=(l+r)>>1;
            if(m[id[mid]]<=(LL)t*u[id[mid]])l=mid+1,ret=mid;
            else r=mid-1;
        }
        return query(rt[ret],1,n,L,R);
    }
    set<tup>::iterator L,R;
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)s[i]=read(),m[i]=read(),u[i]=read(),T.insert(i),id[i]=i;
        S.insert(tup(0,0,0));
        build(rt[0],1,n),sort(id+1,id+n+1,cmp);
        for(res i=1;i<=n;i++)insert(rt[i],rt[i-1],1,n,id[i]);
        res q=read();
        while(q--){
            res t=read(),l=read(),r=read();
            LL ans=0;
            auto IT=T.lower_bound(l);
            while(IT!=T.end()&&(*IT)<=r){
                res i=(*IT);
                ans+=min((LL)m[i],(LL)u[i]*t+s[i]),T.erase(IT),IT=T.lower_bound(l);
            }
            if(S.empty())L=R=S.end();
            else {
                if(r==n)R=S.end();
                else {
                    auto it=(--S.upper_bound(tup(r+1,0,0)));
                    tup tmp=(*it);
                    if(r>=get<1>(tmp))R=(++it);
                    else S.erase(it),S.insert(tup(get<0>(tmp),r,get<2>(tmp))),R=S.insert(tup(r+1,get<1>(tmp),get<2>(tmp))).fi;
                }
                auto it=(--S.upper_bound(tup(l+1,0,0)));
                tup tmp=(*it);
                if(l>get<1>(tmp))L=(++it);
                else if(l>get<0>(tmp))S.erase(it),S.insert(tup(get<0>(tmp),l-1,get<2>(tmp))),L=S.insert(tup(l,get<1>(tmp),get<2>(tmp))).fi;
                else {
                    if(l==get<0>(tmp))L=it;
                }
            }
            auto nL=L;
            for(;L!=R;L++){
                pair<LL,LL> ret=calc(get<0>(*L),get<1>(*L),t-get<2>(*L));
                ans+=ret.fi*(t-get<2>(*L))+ret.se;
            }
            S.erase(nL,R),S.insert(tup(l,r,t)),printf("%lld\n",ans);
        }
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