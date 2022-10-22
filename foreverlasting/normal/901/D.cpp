//2022.1.14 by ljz
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
const int kcz=1234567891;
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
#define mul(x,y) (int)((LL)(x)*(y)%kcz)
//#define Mul(x,y,d) (int)((ull)(x)*(y)/(d)%kcz)
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
        if(y&1)ret=(int)(1ll*ret*x%ljc);
        x=(int)(1ll*x*x%ljc),y>>=1;
    }
    return ret;
}
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2022.1.14 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=1e5+10;
namespace MAIN{
    int n,m;
    LL C[N];
    Pair edge[N];
    int fa[N];
    inline int find(res x){
        while(x!=fa[x])x=fa[x]=fa[fa[x]];
        return x;
    }
    vector<Pair> G[N];
    int dep[N],F[N][21],Fa[N];
    LL a[N],val[N];
    int fl[N];
    void dfs(res x,res fax,res depx){
        dep[x]=depx,F[x][0]=fax;
        for(res i=1;i<=20;i++)F[x][i]=F[F[x][i-1]][i-1];
        for(auto [tox,id]:G[x]){
            if(tox==fax)continue;
            Fa[tox]=id,dfs(tox,x,depx+1);
        }
        for(auto [tox,id]:G[x])if(tox==fax){val[id]=C[x]-a[x],a[fax]+=val[id],a[x]=C[x];break;}
    }
    inline int getlca(res x,res y){
        if(dep[x]<dep[y])swap(x,y);
        res d=dep[x]-dep[y];
        for(res i=20;~i;i--)if(d&(1<<i))x=F[x][i];
        if(x==y)return x;
        for(res i=20;~i;i--)if(F[x][i]!=F[y][i])x=F[x][i],y=F[y][i];
        return F[x][0];
    }
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=n;i++)C[i]=read(),fa[i]=i;
        for(res i=1;i<=m;i++){
            res u=read(),v=read();
            edge[i]=mp(u,v);
            res fu=find(u),fv=find(v);
            if(fu==fv)continue;
            fl[i]=1,G[u].pb(mp(v,i)),G[v].pb(mp(u,i)),fa[fu]=fv;
        }
        dfs(1,0,1);
        RG LL p=C[1]-a[1];
        if(p&1){puts("NO");return;}
        if(!p){
            puts("YES");
            for(res i=1;i<=m;i++)printf("%lld\n",val[i]);
            return;
        }
//        for(res _=1;_<=m;_++)printf("%lld\n",val[_]);
        for(res i=1;i<=m;i++){
            if(fl[i])continue;
            auto [u,v]=edge[i];
            res lca=getlca(u,v);
            if(~(dep[u]+dep[v]-2*dep[lca])&1){
//                if(lca==1){
//                    puts("YES"),val[i]+=p/2,p=-p;
//                    res now=u;
//                    while(now!=lca)val[Fa[now]]+=p/2,now=F[now][0],p=-p;
//                    now=v,p=a[1]-C[1];
//                    while(now!=lca)val[Fa[now]]+=p/2,now=F[now][0],p=-p;
//                    for(res _=1;_<=m;_++)printf("%lld\n",val[_]);
//                    return;
//                }
                if(~(dep[u]-dep[lca])&1)p=-p;
                puts("YES");
                if(~(dep[lca]-dep[1])&1)p=-p;
                val[i]+=p/2,p=-p;
                res now=u;
                while(now!=lca)val[Fa[now]]+=p/2,now=F[now][0],p=-p;
                now=v;
                p=C[1]-a[1];
                if(~(dep[u]-dep[lca])&1)p=-p;
                if(~(dep[lca]-dep[1])&1)p=-p;
                p=-p;
                while(now!=lca)val[Fa[now]]+=p/2,now=F[now][0],p=-p;
                now=lca;
                while(now!=1)val[Fa[now]]+=p,now=F[now][0],p=-p;
                for(res _=1;_<=m;_++)printf("%lld\n",val[_]);
                return;
            }
        }
        puts("NO");
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