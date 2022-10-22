//2018.9.14 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define ll long long
#define inf 0x3f3f3f3f
#define eps 1e-8
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int N=2e3+10;
#define lb double
namespace MAIN{
    int n,a,b;
    lb dp[N],fp[N],fv[N],p[N],v[N];
    inline void calc(lb x,lb y){
        for(res i=1;i<=n;i++){
            dp[i]=dp[i-1],fp[i]=fp[i-1],fv[i]=fv[i-1];
            if(dp[i-1]+p[i]>dp[i]+x)dp[i]=dp[i-1]+p[i]-x,fp[i]=fp[i-1]+1,fv[i]=fv[i-1];
            if(dp[i-1]+v[i]>dp[i]+y)dp[i]=dp[i-1]+v[i]-y,fv[i]=fv[i-1]+1,fp[i]=fp[i-1];
            if(dp[i-1]+p[i]+v[i]-p[i]*v[i]>dp[i]+x+y)dp[i]=dp[i-1]+p[i]+v[i]-p[i]*v[i]-x-y,fp[i]=fp[i-1]+1,fv[i]=fv[i-1]+1;
        }
    }
    inline void MAIN(){
        n=read(),a=read(),b=read();
        for(res i=1;i<=n;i++)scanf("%lf",&p[i]);
        for(res i=1;i<=n;i++)scanf("%lf",&v[i]);
        lb l=0,r=1,L=0,R=1;
        while(r-l>eps){
            lb mid=(l+r)/2;
            L=0,R=1;
            while(R-L>eps){
                lb MID=(L+R)/2;
                calc(mid,MID);
                fv[n]>b?L=MID:R=MID;
            }
            calc(mid,R);
            fp[n]>a?l=mid:r=mid;
        }
        calc(r,R);
        printf("%.6lf\n",dp[n]+a*r+b*R);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}