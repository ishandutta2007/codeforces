#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int t,n,k,a[200001],ans;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        for(register int i=1;i<=n;++i)
            scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        ans=a[n];
        for(register int i=n-1;i>=n-k;--i)
            ans+=a[i];
        printf("%lld\n",ans);
    }
    return 0;
}