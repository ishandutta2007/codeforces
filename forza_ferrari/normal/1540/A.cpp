#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int t,n,d[100001],sum[100001],ans;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        ans=0;
        scanf("%lld",&n);
        for(register int i=1;i<=n;++i)
            scanf("%lld",&d[i]);
        if(n==1)
        {
            puts("0");
            continue;
        }
        sort(d+1,d+n+1);
        for(register int i=1;i<=n;++i)
            sum[i]=sum[i-1]+d[i];
        ans=d[n];
        for(register int i=2;i<=n;++i)
            ans-=d[i]*(i-1)-sum[i-1];
        printf("%lld\n",ans);
    }
    return 0;
}