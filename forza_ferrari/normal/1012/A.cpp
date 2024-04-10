#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,a[200001],ans;
signed main()
{
    scanf("%lld",&n);
    for(register int i=1;i<=2*n;++i)
        scanf("%lld",&a[i]);
    sort(a+1,a+2*n+1);
    ans=(a[2*n]-a[n+1])*(a[n]-a[1]);
    for(register int i=2;i<=n;++i)
        ans=min(ans,(a[2*n]-a[1])*(a[i+n-1]-a[i]));
    printf("%lld\n",ans);
    return 0;
}