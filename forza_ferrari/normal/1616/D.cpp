#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int t,n,a[50001],m,dp[50001][3];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            dp[i][0]=dp[i][1]=dp[i][2]=0;
        }
        cin>>m;
        for(int i=1;i<=n;++i)
            a[i]-=m;
        dp[0][0]=dp[0][1]=dp[0][2]=0;
        for(int i=1;i<=n;++i)
        {
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            dp[i][1]=dp[i-1][0]+1;
            if(i>1&&a[i]+a[i-1]>=0)
                {
                    dp[i][2]=max(dp[i][2],dp[i-1][1]+1);
                    if(i>2&&a[i]+a[i-1]+a[i-2]>=0&&a[i-1]+a[i-2]>=0)
                        dp[i][2]=max(dp[i][2],dp[i-1][2]+1);
                }
        }
        cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<'\n';
    }
    return 0;
}