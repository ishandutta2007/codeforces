#include <bits/stdc++.h>
using namespace std;
int main()
{
    long i,j,k,a[1001],b[1001],c[1001],d[1001],n,m,dp[1001][11]={0},ans=0;
    cin>>n>>m>>c[0]>>d[0];
    for(i=1;i<=m;++i)
    cin>>a[i]>>b[i]>>c[i]>>d[i];
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    for(k=0;k<=a[j]/b[j] && k*c[j]<=i;++k)
    dp[i][j]=max(dp[i][j],dp[i-k*c[j]][j-1]+k*d[j]);
    for(i=0;i<=n;++i)
    ans=max(ans,dp[i][m]+((n-i)/c[0])*d[0]);
    cout<<ans;
    return 0;
}