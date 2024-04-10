//2021.9.18 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res register int
#define LL long long
#define sup 0x7fffffff
#define inf 0x80000000
#define INF 0x3f3f3f3f3f3f3f
//#define unl __int128
#define eps 1e-5
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
//#define ctz(x) __builtin_ctz(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
//#define poly vector<int>
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
//inline void print(RG LL x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);
//}
inline int read() {
    res s=0,ch=gc(),laz=1;
    while(ch<'0'||ch>'9'){if(ch=='-')laz=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*laz;
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
//    res ch=gc(),laz=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')laz=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*laz;
//}
//inline void write(RG unl x){
//    if(x>10)write(x/10);
//    putchar(int(x%10)+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
int kcz=1000000007;
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
#define add(x,y) (x+=y,x>=kcz?x-=kcz:1)
#define Add(x,y) (x+y>=kcz?x+y-kcz:x+y)
#define mul(x,y) int(1ll*x*y%kcz)
#define Mul(x,y,d) int(1LL*x*y/d%kcz)
inline int qpow(res x,res y=kcz-2){
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
inline int Qpow(res x,res y,const res &ljc){
    res ret=1;
    while(y){
        if(y&1)ret=int(1ll*ret*x%ljc);
        x=int(1ll*x*x%ljc),y>>=1;
    }
    return ret;
}
//mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2021.9.18 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=2e5+10;
namespace MAIN{
    int n;
    vector<int> G[N];
    int du[N],he,ta;
    priority_queue<Pair,vector<Pair>,greater<Pair> >Q;
    inline void MAIN(){
        res Case=read();
        while(Case--){
            n=read();
            for(res i=1;i<=n;i++)vector<int>().swap(G[i]),du[i]=0;
            he=1,ta=0;
            for(res i=1;i<=n;i++){
                res k=read();
                if(!k)Q.push(mp(1,i)),ta++;
                else {
                    for(res j=1;j<=k;j++)G[read()].pb(i);
                    du[i]=k;
                }
            }
            res mx=0;
            for(res i=1;i<=n;i++)sort(G[i].begin(),G[i].end());
            while(he<=ta){
                res u=Q.top().se,v=Q.top().fi;
                mx=max(mx,v);
                Q.pop();
                he++;
                for(auto tox:G[u]){
                    du[tox]--;
                    if(!du[tox])Q.push(mp(v+(tox<u),tox)),ta++;
                }
            }
            if(ta!=n)puts("-1");
            else {
                printf("%d\n",mx);
            }
        }
    }
}
int main(){
//    srand(19260817);
//    freopen("data.in","r",stdin);
//    freopen("1.out","w",stdout);
    MAIN::MAIN();
//    Ot();
    return 0;
}