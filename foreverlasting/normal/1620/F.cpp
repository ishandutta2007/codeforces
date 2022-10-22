//2022.1.1 by ljz
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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2022.1.1 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=1e6+10;
namespace MAIN{
    int n;
    int a[N];
    int f[N][2][2],pre[N][2][2];
    int id;
    inline void ckmin(res &h,const res &g,const res &x,const res &y,const res &X,const res &Y){
        h>g?h=g,pre[id][X][Y]=x*2+y:1;
    }
    int b[N];
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)a[i]=read();
        for(res i=1;i<=n;i++)for(res j=0;j<=1;j++)for(res k=0;k<=1;k++)f[i][j][k]=n+1;
        f[1][0][0]=f[1][0][1]=-n-1;
        for(res i=2;i<=n;i++){
            res p=a[i];
            id=i;
            if(p>f[i-1][0][0]){
                if(p<a[i-1])ckmin(f[i][1][0],a[i-1],0,0,1,0);
                else ckmin(f[i][0][0],f[i-1][0][0],0,0,0,0);
            }
            if(p>f[i-1][0][1]){
                if(p<-a[i-1])ckmin(f[i][1][0],-a[i-1],0,1,1,0);
                else ckmin(f[i][0][0],f[i-1][0][1],0,1,0,0);
            }
            if(p>a[i-1]){
                if(p>f[i-1][1][0])ckmin(f[i][0][0],a[i-1],1,0,0,0);
                else ckmin(f[i][1][0],f[i-1][1][0],1,0,1,0);
            }
            if(p>-a[i-1]){
                if(p>f[i-1][1][1])ckmin(f[i][0][0],-a[i-1],1,1,0,0);
                else ckmin(f[i][1][0],f[i-1][1][1],1,1,1,0);
            }
            p=-a[i];
            if(p>f[i-1][0][0]){
                if(p<a[i-1])ckmin(f[i][1][1],a[i-1],0,0,1,1);
                else ckmin(f[i][0][1],f[i-1][0][0],0,0,0,1);
            }
            if(p>f[i-1][0][1]){
                if(p<-a[i-1])ckmin(f[i][1][1],-a[i-1],0,1,1,1);
                else ckmin(f[i][0][1],f[i-1][0][1],0,1,0,1);
            }
            if(p>a[i-1]){
                if(p>f[i-1][1][0])ckmin(f[i][0][1],a[i-1],1,0,0,1);
                else ckmin(f[i][1][1],f[i-1][1][0],1,0,1,1);
            }
            if(p>-a[i-1]){
                if(p>f[i-1][1][1])ckmin(f[i][0][1],-a[i-1],1,1,0,1);
                else ckmin(f[i][1][1],f[i-1][1][1],1,1,1,1);
            }
//            printf("%d %d %d %d\n",f[i][0][0],f[i][0][1],f[i][1][0],f[i][1][1]);
        }
        res nx=0,ny=0;
        if(f[n][0][0]<=n)nx=ny=0;
        else if(f[n][0][1]<=n)nx=0,ny=1;
        else if(f[n][1][0]<=n)nx=1,ny=0;
        else if(f[n][1][1]<=n)nx=ny=1;
        else {puts("NO");return;}
        puts("YES");
        for(res i=n;i;i--){
            if(ny==0){
                b[i]=a[i];
                res p=pre[i][nx][ny];
                ny=p&1,nx=p>>1;
            }
            else {
                b[i]=-a[i];
                res p=pre[i][nx][ny];
                ny=p&1,nx=p>>1;
            }
        }
        for(res i=1;i<=n;i++)printf("%d ",b[i]);
        puts("");
    }
}
int main(){
//    srand(19260817);
//    freopen("data.in","r",stdin);
//    freopen("1.out","fw",stdout);
    res Case=read();
    while(Case--)MAIN::MAIN();
//    Ot();
    return 0;
}