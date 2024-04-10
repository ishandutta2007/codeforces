//2019.4.3 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-5
#define RG register
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void swap(res &x,res &y){
    x^=y^=x^=y;
}
const int N=1e6+10;
namespace MAIN{
    int n,m;
    int used[N];
    int dp[N][3][3];
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=n;i++)used[read()]++;
        memset(dp,-1,sizeof(dp)),dp[1][0][0]=0;
        for(res i=1;i<=m;i++)
            for(res j=0;j<=2;j++)
                for(res k=0;k<=2;k++){
                    if(dp[i][j][k]==-1||j+k>used[i])continue;
                    res tmp=dp[i][j][k];
                    for(res l=0;l<=2&&j+k+l<=used[i];l++)
                        dp[i+1][k][l]=max(dp[i+1][k][l],tmp+l+(used[i]-j-k-l)/3);
                }
        printf("%d\n",dp[m+1][0][0]);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}