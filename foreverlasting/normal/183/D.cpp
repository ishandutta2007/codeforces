//2018.9.13 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
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
#define lb long double
const int N=3e3+10,M=3e2+10;
namespace MAIN{
    int n,m;
    double p[N][M],dp[M][N],pos[M],ans,last[N];
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=n;i++)
            for(res j=1;j<=m;j++)
                p[i][j]=read()/1000.00;
        for(res i=1;i<=m;i++){
            dp[i][0]=1;
            for(res j=1;j<=n;j++)
                dp[i][j]=dp[i][j-1]*(1-p[j][i]);
            pos[i]=1-dp[i][n];
        }
        for(res i=1;i<=n;i++){
            res x=0;
            for(res j=1;j<=m;j++)
                if(pos[j]>pos[x])x=j;
            ans+=pos[x];
            memcpy(last,dp[x],sizeof(last));
            dp[x][0]=0.;
            for(res i=1;i<=n;i++)
                dp[x][i]=dp[x][i-1]*(1-p[i][x])+last[i-1]*p[i][x];
            pos[x]-=dp[x][n];
        }
        printf("%.12f\n",ans);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}