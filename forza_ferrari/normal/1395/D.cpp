#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
int n,m,d,a[100001],dp[100001][3],sum,cnt1,cnt2;
vector<int> q1,q2;
signed main()
{
    cnt1=cnt2=-1;
    scanf("%lld%lld%lld",&n,&d,&m);
    for(register int i=1;i<=n;++i)
    {
        dp[i][0]=-1;
        scanf("%lld",&a[i]);
        if(a[i]>m)
        {
            q1.push_back(a[i]);
            ++cnt1;
        }
        else
        {
            q2.push_back(a[i]);
            sum+=a[i];
            ++cnt2;
        }
    }
    if(q1.empty())
    {
        printf("%lld\n",sum);
        return 0;
    }
    sort(q1.begin(),q1.end());
    sort(q2.begin(),q2.end());
    dp[n][0]=q1[cnt1];
    dp[n][1]=cnt1-1;
    dp[n][2]=cnt2;
    for(register int i=n-1;i>=1;--i)
    {
        if(dp[i+1][2]>=0)
        {
            dp[i][0]=dp[i+1][0]+q2[dp[i+1][2]];
            dp[i][1]=dp[i+1][1];
            dp[i][2]=dp[i+1][2]-1;
        }
        if(i+d<n&&dp[i+d+1][1]>=0)
            if(dp[i+d+1][0]+q1[dp[i+d+1][1]]>dp[i][0])
            {
                dp[i][0]=dp[i+d+1][0]+q1[dp[i+d+1][1]];
                dp[i][1]=dp[i+d+1][1]-1;
                dp[i][2]=dp[i+d+1][2];
            }
        if(dp[i][0]==-1)
        {
            dp[i][0]=dp[i+1][0];
            dp[i][1]=dp[i+1][1];
            dp[i][2]=dp[i+1][2];
        }
    }
    int ans=0;
    for(register int i=1;i<=n;++i)
        ans=max(ans,dp[i][0]);
    printf("%lld\n",ans);
    return 0;
}