#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,a[100001],b[100001],c[100001],dp[100001],ans;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=0;
        for(register int i=1;i<=n;++i)
            scanf("%lld",&c[i]);
        for(register int i=1;i<=n;++i)
            scanf("%lld",&a[i]);
        for(register int i=1;i<=n;++i)
        {
            scanf("%lld",&b[i]);
            if(a[i]>b[i])
                a[i]^=b[i]^=a[i]^=b[i];
        }
        ans=dp[2]=c[2]+b[2]-a[2]+1;
        for(register int i=3;i<=n;++i)
        {
            if(a[i]^b[i])
                dp[i]=max(c[i]+b[i]-a[i]+1,dp[i-1]-(b[i]-a[i]-1)+c[i]);
            else
                dp[i]=c[i]+1;
            ans=max(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}