#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,minn,maxn,a[200001],b[200001],dp[200001],ans;
inline bool check(int x)
{
    for(register int i=1;i<=n;++i)
    {
        b[i]=a[i]>=x? 1:-1;
        dp[i]=dp[i-1]+b[i];
    }
    int minn=0;
    for(register int i=k;i<=n;++i)
    {
        minn=min(minn,dp[i-k]);
        if(dp[i]-minn>=1)
            return 1;
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(register int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int l=1,r=n,mid;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else
            r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}