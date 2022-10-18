#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,m,p,r[201],g[201],b[201],ans,dp[202][202][202];
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&p);
    for(register int i=1;i<=n;++i)
        scanf("%lld",&r[i]);
    for(register int i=1;i<=m;++i)
        scanf("%lld",&g[i]);
    for(register int i=1;i<=p;++i)
        scanf("%lld",&b[i]);
    sort(r+1,r+n+1);
    sort(g+1,g+m+1);
    sort(b+1,b+p+1);
    for(register int i=n;i>=0;--i)
        for(register int j=m;j>=0;--j)
            for(register int k=p;k>=0;--k)
            {
                dp[i][j][k]=max(dp[i+1][j+1][k]+r[i+1]*g[j+1],max(dp[i+1][j][k+1]+r[i+1]*b[k+1],dp[i][j+1][k+1]+g[j+1]*b[k+1]));
                ans=max(ans,dp[i][j][k]);
            }
    printf("%lld\n",ans);
    return 0;
}