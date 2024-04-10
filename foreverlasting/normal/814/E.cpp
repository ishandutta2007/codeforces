//2019.9.22 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define unl __int128
#define eps 5.6e-8
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
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
#define kcz 1000000007
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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
//char sr[1<<21],z[20];
//int C=-1,Z=0;
//inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
//inline void print(res x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);sr[++C]='\n';
//}
//inline int read() {
//    res s=0,ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
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
//inline void swap(res &x,res &y) {
//    x^=y^=x^=y;
//}
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
const int N=300+10;
namespace MAIN {
    int n;
    int f[N][N],g[N][N][N],fac[N];
    int du[N];
    int C[N][N];
    int inv2=(kcz+1)>>1;
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)du[i]=read();
        C[0][0]=1;
        for(res i=1;i<=n;i++){
            C[i][0]=1;
            for(res j=1;j<=i;j++)C[i][j]=Add(C[i-1][j],C[i-1][j-1]);
        }
        fac[0]=fac[1]=1;
        for(res i=2;i<=n;i++)fac[i]=mul(fac[i-1],i);
        g[0][0][0]=1;
        for(res k=3;k<=n;k++)
            for(res l=3;l<=k;l++)
                add(g[0][0][k],mul(g[0][0][k-l],mul(C[k-1][l-1],mul(fac[l-1],inv2))));
        for(res j=1;j<=n;j++)
            for(res k=0;k+j<=n;k++){
                if(j>=2)add(g[0][j][k],mul(g[0][j-2][k],j-1));
                if(k)add(g[0][j][k],mul(g[0][j][k-1],k));
            }
        for(res i=1;i<=n;i++){
            for(res j=0;i+j<=n;j++)
                for(res k=0;i+j+k<=n;k++){
                    if(j)add(g[i][j][k],mul(g[i-1][j-1][k],j));
                    if(k)add(g[i][j][k],mul(g[i-1][j+1][k-1],k));
                }
        }
        res D=du[1]+1;
        f[D][D-1]=1;
        for(res i=D+1;i<=n;i++)
            for(res j=1;i-j>=D;j++){
                res a2=0,a3=0;
                for(res k=1;i-j-k>0;k++){
                    if(du[i-j-k+1]==2)a2++;
                    else a3++;
                    add(f[i][j],mul(g[j][a2][a3],f[i-j][k]));
                }
            }
        res a2=0,a3=0,ans=0;
        for(res k=1;k<n;k++){
            if(du[n-k+1]==2)a2++;
            else a3++;
            add(ans,mul(g[0][a2][a3],f[n][k]));
        }
        printf("%d\n",ans);
    }
}
int main() {
//    srand(19260817);
//    freopen("path.in","r",stdin);
//    freopen("path.out","w",stdout);
    MAIN::MAIN();
//    Ot();
    return 0;
}