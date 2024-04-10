//2022.5.9 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
#include<random>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res int
#define LL long long
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
//inline int gc(){
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
inline void write(unl x){
    if(x>10)write(x/10);
    putchar(int(x%10)+'0');
}
const int kcz=1000000007;
//const int G=3,GI=332748118;
inline void add(res &x,const res &y){
    x+=y,x>=kcz?x-=kcz:1;
}
inline int Add(const res &x,const res &y){
    return x+y>=kcz?x+y-kcz:x+y;
}
inline int mul(const res &x,const res &y){
    return (int)((LL)x*y%kcz);
}
//#define add(x,y) ((x)+=(y),(x)>=kcz?(x)-=kcz:1)
//#define Add(x,y) ((x)+(y)>=kcz?(x)+(y)-kcz:(x)+(y))
//#define mul(x,y) (int)((LL)(x)*(y)%kcz)
#define Mul(x,y,d) (int)((ull)(x)*(y)/(d)%kcz)
inline int qpow(res x,res y=kcz-2){
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
//inline int qpow(res x,res y,const res &ljc){
//    res ret=1;
//    while(y){
//        if(y&1)ret=(int)(1ll*ret*x%ljc);
//        x=(int)(1ll*x*x%ljc),y>>=1;
//    }
//    return ret;
//}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//std::mt19937(std::random_device()())
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2022.5.9 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=2e5+10;
namespace MAIN{
    int n,q;
    int p[N],mx[N][21],lg[N],pos[N];
    inline int gm(const res &l,const res &r){
        res k=lg[r-l+1];
        return max(mx[l][k],mx[r-(1<<k)+1][k]);
    }
#define tup tuple<int,int,int,int>
    vector<tup> in[N],que[N];
    vector<int> A[N];
    void solve(res l,res r){
        if(l>=r)return;
        res mid=pos[gm(l,r)];
        solve(l,mid-1),solve(mid+1,r);
        for(auto x:A[p[mid]]){
            res L=pos[x],R=pos[p[mid]/x];
            if(L>=R||L<l||R>r)continue;
            L=min(L,mid),R=max(R,mid);
            in[l].emplace_back(R,r,1,0),in[L+1].emplace_back(R,r,-1,0);
        }
    }
    LL sum[N<<2];
    int num[N<<2],tag[N<<2],Tag[N<<2],mn[N<<2];
    void build(res rt,res l,res r){
        num[rt]=r-l+1;
        if(l==r)return;
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
    }
    inline void change_mn(const res &rt,const res &v){
        mn[rt]+=v,tag[rt]+=v;
    }
    inline void change_s(const res &rt,const res &v){
        sum[rt]+=(LL)v*num[rt],Tag[rt]+=v;
    }
    inline void pushdown(const res &rt){
        if(tag[rt])change_mn(rt<<1,tag[rt]),change_mn(rt<<1|1,tag[rt]),tag[rt]=0;
        if(Tag[rt]){
            if(mn[rt]==mn[rt<<1])change_s(rt<<1,Tag[rt]);
            if(mn[rt]==mn[rt<<1|1])change_s(rt<<1|1,Tag[rt]);
            Tag[rt]=0;
        }
    }
    void modify(res rt,res l,res r,const res &L,const res &R,const res &v){
        if(L<=l&&r<=R){change_mn(rt,v);return;}
        res mid=(l+r)>>1;
        pushdown(rt);
        if(L<=mid)modify(rt<<1,l,mid,L,R,v);
        if(R>mid)modify(rt<<1|1,mid+1,r,L,R,v);
        mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
        num[rt]=0;
        if(mn[rt]==mn[rt<<1])num[rt]=num[rt<<1];
        if(mn[rt]==mn[rt<<1|1])num[rt]+=num[rt<<1|1];
    }
    LL query(res rt,res l,res r,const res &L,const res &R){
        if(L<=l&&r<=R)return sum[rt];
        res mid=(l+r)>>1;
        pushdown(rt);
        LL ret=0;
        if(L<=mid)ret=query(rt<<1,l,mid,L,R);
        if(R>mid)ret+=query(rt<<1|1,mid+1,r,L,R);
        return ret;
    }
//    void solve(res rt,res l,res r){
//        printf("%d %d %d %d %d %lld\n",rt,l,r,mn[rt],num[rt],sum[rt]);
//        if(l==r)return;
//        res mid=(l+r)>>1;
//        pushdown(rt);
//        solve(rt<<1,l,mid),solve(rt<<1|1,mid+1,r);
//    }
    LL ans[N*5];
    inline void MAIN(const res &Case){
        n=read(),q=read();
        for(res i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
        for(res i=1;i<=n;i++)pos[p[i]=mx[i][0]=read()]=i;
        for(res j=1;j<=20;j++)for(res i=1;i+(1<<j)-1<=n;i++)mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
        for(res i=1;i<=n;i++)for(res j=i;j<=n;j+=i)A[j].pb(i);
        solve(1,n),build(1,1,n);
        for(res i=1;i<=q;i++){
            res l=read(),r=read();
            que[l-1].emplace_back(l,r,-1,i);
            que[r].emplace_back(l,r,1,i);
        }
        for(res i=1;i<=n;i++){
            for(auto [l,r,v,I]:in[i])modify(1,1,n,l,r,v);
            if(!mn[1])change_s(1,1);
            for(auto [l,r,v,I]:que[i])ans[I]+=(((LL)r-l+1)*i-query(1,1,n,l,r))*v;
        }
//        solve(1,1,n);
        for(res i=1;i<=q;i++)printf("%lld\n",ans[i]);
    }
}
int main(){
//    srand(time(0));
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    res Case=1;
    for(res T=1;T<=Case;T++)MAIN::MAIN(T);
//    Ot();
    return 0;
}