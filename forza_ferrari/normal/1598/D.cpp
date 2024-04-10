#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,a[200001],b[200001],ta[200001],tb[200001],ans;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(register int i=1;i<=n;++i)
            ta[i]=tb[i]=0;
        for(register int i=1;i<=n;++i)
        {
            scanf("%lld%lld",&a[i],&b[i]);
            ++ta[a[i]];
            ++tb[b[i]];
        }
        ans=n*(n-1)*(n-2)/6;
        for(register int i=1;i<=n;++i)
            ans-=(ta[a[i]]-1)*(tb[b[i]]-1);
        printf("%lld\n",ans);
    }
    return 0;
}