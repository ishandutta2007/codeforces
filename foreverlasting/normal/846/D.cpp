//2019.7.19 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define eps 1e-10
#define RG register
#define db long double
#define lb long db
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
//inline void write(RG __int128 x){
//    if(x>10)write(x/10);
//    putchar(x%10+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=5e5+10;
const int R=5e2+10;
namespace MAIN{
    int n,m,k,q;
    struct P{
        int x,y,t;
        P() {}
        P(res x,res y,res t):x(x),y(y),t(t) {}
        inline bool operator < (const RG P &b) const {
            return t<b.t;
        }
        inline void init(){
            x=read(),y=read(),t=read();
        }
    }a[N];
    int sum[R][R];
    inline bool check(const res &lim){
        for(res i=1;i<=n;i++)
            for(res j=1;j<=m;j++)
                sum[i][j]=0;
        for(res i=1;i<=lim;i++)sum[a[i].x][a[i].y]=1;
        for(res i=1;i<=n;i++)
            for(res j=1;j<=m;j++){
                sum[i][j]=sum[i-1][j]+sum[i][j-1]+sum[i][j]-sum[i-1][j-1];
                if(k<=i&&k<=j&&sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k]==k*k)return 1;
        }
        return 0;
    }
    inline void MAIN(){
        n=read(),m=read(),k=read(),q=read(),a[0].t=-1;
        for(res i=1;i<=q;i++)a[i].init();
        sort(a+1,a+q+1);
        res l=1,r=q,ret=0;
        while(l<=r){
            res mid=(l+r)>>1;
            if(check(mid))r=mid-1,ret=mid;
            else l=mid+1;
        }
        printf("%d\n",a[ret].t);
    }
}
int main() {
//    srand((unsigned)time(NULL));
//    freopen("route.in","r",stdin);
//    freopen("route.out","w",stdout);
    MAIN::MAIN();
    return 0;
}