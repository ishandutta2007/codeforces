//2019.7.21 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 1e18+1e9
#define eps 1e-10
#define RG register
#define db double
#define lb long db
#define pc(x) __builtin_popcount(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define gc getchar
#define Pi 2.0*acos(-1.0)
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
//inline void write(RG __int128 x){
//    if(x>10)write(x/10);
//    putchar(x%10+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e5+10;
namespace MAIN{
    int n,m;
    struct P{
        int x,y;
        db d;
        P() {}
        P(res x,res y):x(x),y(y),d(sqrt(1.0*x*x+1.0*y*y)) {}
        inline void init(){
            x=read(),y=read(),d=sqrt(1.0*x*x+1.0*y*y);
        }
    }a[N];
    db l,r=1.0/0.0;
    struct Seg{
        db l,r;
        bool typ;
        Seg() {}
        Seg(RG db l,RG db r,RG bool typ):l(l),r(r),typ(typ) {}
        inline bool operator < (const RG Seg &b) const {
            return typ!=b.typ?typ<b.typ:l<b.l;
        }
    }p[N<<1];
    int F[N<<1][20];
    bool fl[N<<1];
    inline bool check(const RG db &lim){
        res tot=0;
        for(res i=1;i<=n;i++){
            RG db X=atan2(a[i].y,a[i].x),Y=acos(lim/a[i].d);
            p[++tot]=Seg(X-Y,X+Y,0),p[++tot]=Seg(X-Y+Pi,X+Y+Pi,1);
        }
        sort(p+1,p+tot+1);
        for(res i=1;i<=tot;i++)fl[i]=1;
        RG db ret=1.0/0.0;
        for(res i=tot;i;i--)
            if(p[i].r>=ret)fl[i]=0;
            else ret=p[i].r;
        tot=0;
        for(res i=1;i<=n;i++)if(fl[i])p[++tot]=p[i];
        for(res i=1;i<=tot;i++)p[i+tot]=Seg(p[i].l+Pi,p[i].r+Pi,1);
        tot<<=1;
        for(res i=1,j=1;i<=tot;i++){
            while(j<=tot&&p[i].r>=p[j].l)j++;
            F[i][0]=j;
        }
        for(res j=1;1<<j<=tot;j++)
            for(res i=1;i<=tot;i++)
                F[i][j]=F[F[i][j-1]][j-1];
        tot>>=1;
        for(res i=1;i<=tot;i++){
            res j=i,tmp=0;
            for(res k=m;k;k>>=1,tmp++)
                if(k&1)j=F[j][tmp];
            if(!j||j>=i+tot)return 1;
        }
        return 0;
    }
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=n;i++)a[i].init(),r=min(r,a[i].d);
        if(m>=n){printf("%.10lf\n",r);return;}
        while(r-l>eps){
            RG db mid=(l+r)/2;
            if(check(mid))l=mid;
            else r=mid;
        }
        printf("%.10lf\n",l);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}