#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,k,a[100001];
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        int ans=-1e18;
        scanf("%lld%lld",&n,&k);
        for(register int i=1;i<=n;++i)
            scanf("%lld",&a[i]);
        for(register int i=max(n-300,1ll);i<=n;++i)
            for(register int j=i+1;j<=n;++j)
                ans=max(ans,i*j-k*(a[i]|a[j]));
        printf("%lld\n",ans);
    }
    return 0;
}