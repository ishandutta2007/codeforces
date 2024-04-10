#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,a[1000001],ans,sum;
signed main()
{
    scanf("%lld",&n);
    for(register int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    if(sum==1)
    {
        puts("-1");
        return 0;
    }
    ans=1ll<<60;
    for(register int i=2;i*i<=sum;++i)
    {
        if(sum%i)
            continue;
        while(sum%i==0)
            sum/=i;
        int res=0,tot=0;
        for(register int j=1;j<=n;++j)
        {
            res=(res+a[j])%i;
            tot+=min(res,i-res);
        }
        ans=min(ans,tot);
    }
    if(sum^1)
    {
        int res=0,tot=0;
        for(register int i=1;i<=n;++i)
        {
            res=(res+a[i])%sum;
            tot+=min(res,sum-res);
        }
        ans=min(ans,tot);
    }
    printf("%lld\n",ans);
    return 0;
}