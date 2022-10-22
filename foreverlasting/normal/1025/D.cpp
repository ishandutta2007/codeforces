//2019.2.20 by ljz
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
const int N=7e2+10;
namespace MAIN{
    int n;
    int a[N];
    bool mp[N][N],dp[N][N][2];
    inline int gcd(res x,res y){
        while(y){
            res t=x;
            x=y,y=t%y;
        }
        return x;
    }
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)a[i]=read();
        for(res i=1;i<=n;i++){
            dp[i][i][0]=dp[i][i][1]=1;
            for(res j=i;j<=n;j++)if(gcd(a[i],a[j])>1)mp[i][j]=mp[j][i]=1;
        }
        for(res l=n;l;l--)
            for(res r=l;r<=n;r++)
                for(res k=l;k<=r;k++)
                    if(dp[l][k][0]&&dp[k][r][1])
                        dp[l-1][r][1]|=mp[l-1][k],dp[l][r+1][0]|=mp[k][r+1];
        for(res k=1;k<=n;k++)if(dp[1][k][0]&&dp[k][n][1]){puts("Yes");return;}
        puts("No");
    }
}
int main(){
//    freopen("secret.in","r",stdin);
//    freopen("secret.out","w",stdout);
    MAIN::MAIN();
    return 0;
}