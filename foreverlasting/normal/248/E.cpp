//2018.10.17 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register LL
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline LL read(){
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
inline LL _abs(const res &x){
    return x>0?x:-x;
}
inline LL _max(const res &x,const res &y){
    return x>y?x:y;
}
inline LL _min(const res &x,const res &y){
    return x<y?x:y;
}
const LL N=1e5+10;
const LL A=1e3+10;
namespace MAIN{
    LL n,m;
    LL a[N],b[N],C[A][A];
    inline void pre(){
        C[0][0]=1;
        for(res i=1;i<=A-10;i++){
            C[i][0]=1;
            for(res j=1;j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    double dp[N][100+10],ans;
    inline void MAIN(){
        pre();
        n=read();
        for(res i=1;i<=n;i++)a[i]=b[i]=read(),dp[i][a[i]]=1,ans+=dp[i][0];
        m=read();
        while(m--){
            res u=read(),v=read(),k=read();
            ans-=dp[u][0];
            for(res i=0;i<=a[u];i++){
                double tmp=0,t=C[b[u]][k];
                for(res j=0;j<=k;j++)tmp+=dp[u][i+j]*C[i+j][j]*C[b[u]-i-j][k-j]/t;
                dp[u][i]=tmp;
            }
            b[u]-=k,b[v]+=k,ans+=dp[u][0];
            printf("%.10lf\n",ans);
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}