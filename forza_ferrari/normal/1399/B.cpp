#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,a[51],b[51],min1,min2,ans;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        ans=0;
        min1=min2=2147483647;
        scanf("%lld",&n);
        for(register int i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
            min1=min(min1,a[i]);
        }
        for(register int i=1;i<=n;++i)
        {
            scanf("%lld",&b[i]);
            min2=min(min2,b[i]);
        }
        for(register int i=1;i<=n;++i)
            ans+=max(a[i]-min1,b[i]-min2);
        printf("%lld\n",ans);
    }
    return 0;
}