//2019.7.6 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define eps 5.6e-8
#define RG register
#define db long double
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
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int kcz=1e9+7;
const int N=2e2+10;
namespace MAIN{
    int n;
    struct P{
        int x,y;
        P() {}
        P(res x,res y):x(x),y(y) {}
    }a[N];
    inline LL operator * (const RG P &A,const RG P &B){
        return 1LL*A.x*B.y-1LL*A.y*B.x;
    }
    inline P operator - (const RG P &A,const RG P &B){
        return P(A.x-B.x,A.y-B.y);
    }
    inline void add(res &x,const res &y){
        x+=y,x>=kcz?x-=kcz:1;
    }
    inline int Add(const res &x,const res &y){
        return x+y>=kcz?x+y-kcz:x+y;
    }
    inline int mul(const res &x,const res &y){
        return int(1LL*x*y%kcz);
    }
    int dp[N][N];
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++){
            res x=read(),y=read();
            a[i]=P(x,y);
        }
        RG LL tmp=a[n]*a[1];
        for(res i=1;i<n;i++)tmp+=a[i]*a[i+1];
        if(tmp>0)reverse(a+1,a+n+1);
        for(res i=1;i<n;i++)dp[i][i+1]=1;
        for(res len=2;len<n;len++)
            for(res l=1,r=l+len;r<=n;l++,r++)
                for(res k=l;k<=r;k++)
                    if((a[r]-a[l])*(a[k]-a[l])>0)add(dp[l][r],mul(dp[l][k],dp[k][r]));
        printf("%d\n",dp[1][n]);
    }
}
int main() {
//    srand((unsigned)time(NULL));
    // freopen("zao.in","r",stdin);
    // freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}