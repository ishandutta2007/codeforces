#include<iostream>
#include<cstdio>
using namespace std;
int n,dp[605][305][305],a[305][305];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    for(int i=1;i<n+n;++i)
        for(int j=0;j<=n+1;++j)
            for(int k=0;k<=n+1;++k)
                dp[i][j][k]=-1e9;
    dp[1][1][1]=a[1][1];
    for(int i=2;i<n+n;++i)
        for(int j=1;j<=n;++j)
            if(i-j+1>=1&&i-j+1<=n)
                for(int k=1;k<=n;++k)
                    if(i-k+1>=1&&i-k+1<=n)
                        dp[i][j][k]=max(max(dp[i-1][j-1][k-1],dp[i-1][j-1][k]),max(dp[i-1][j][k-1],dp[i-1][j][k]))+((j==k)? a[j][i-j+1]:a[j][i-j+1]+a[k][i-k+1]);
    cout<<dp[n+n-1][n][n]<<'\n';
    return 0;
}