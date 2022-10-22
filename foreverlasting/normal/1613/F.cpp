//2021.12.2 by ljz
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
const int kcz=998244353;
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
//2021.12.2 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=4e5+10;
namespace MAIN{
    int n;
    vector<int> V[N];
    int du[N];
    void dfs(res x,res fax){
        for(auto tox:V[x]){
            if(tox==fax)continue;
            du[x]++,dfs(tox,x);
        }
    }
    int Og[N],pos[N];
#define poly vector<int>
    inline void FFT(poly &A,const res &type,const res &lim){
        for(res i=0;i<lim;i++)if(i<pos[i])swap(A[i],A[pos[i]]);
        for(res mid=1;mid<lim;mid<<=1){
            res wn=qpow(type==1?G:GI,(kcz-1)/(mid<<1));
            Og[0]=1;
            for(res i=1;i<mid;i++)Og[i]=mul(Og[i-1],wn);
            for(res j=0;j<lim;j+=mid<<1)
                for(res k=0;k<mid;k++){
                    res x=A[j+k],y=mul(A[j+mid+k],Og[k]);
                    A[j+k]=Add(x,y),A[j+mid+k]=Add(x,kcz-y);
                }
        }
        if(type==-1){
            res INV=qpow(lim,kcz-2);
            for(res i=0;i<lim;i++)A[i]=mul(A[i],INV);
        }
    }
    poly solve(res l,res r){
        if(l==r){
            poly A;
            A.pb(1),A.pb(du[l]);
            return A;
        }
        res mid=(l+r)>>1;
        poly L=solve(l,mid),R=solve(mid+1,r);
        res lim=1,qaq=0;
        while(lim<=r-l+1)lim<<=1,qaq++;
        for(res i=0;i<lim;i++)pos[i]=(pos[i>>1]>>1)|((i&1)<<(qaq-1));
        for(res i=mid-l+2;i<lim;i++)L.pb(0);
        for(res i=r-mid+1;i<lim;i++)R.pb(0);
//        printf("%d %d\n",l,r);
//        for(auto x:L)printf("%d ",x);puts("");
//        for(auto x:R)printf("%d ",x);puts("");
//        puts("----");
        FFT(L,1,lim),FFT(R,1,lim);
        poly aqua(lim);
        for(res i=0;i<lim;i++)aqua[i]=mul(L[i],R[i]);
        FFT(aqua,-1,lim),aqua.resize(r-l+2);
//        printf("%d %d\n",l,r);
//        for(auto x:aqua)printf("%d ",x);puts("");
//        puts("-------");
        return aqua;
    }
    int fac[N],f[N];
    inline void MAIN(){
        fac[0]=fac[1]=1,n=read();
        for(res i=2;i<=n;i++)fac[i]=mul(fac[i-1],i);
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            V[u].pb(v),V[v].pb(u);
        }
        dfs(1,0);
        poly aqua=solve(1,n);
//        for(auto x:aqua)printf("%d ",x);puts("");
        for(res i=0;i<=n;i++)f[i]=mul(aqua[i],fac[n-i]);
        res ans=0;
        for(res i=0,cur=1;i<=n;i++,cur^=1)add(ans,cur?f[i]:kcz-f[i]);
        printf("%d\n",ans);
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