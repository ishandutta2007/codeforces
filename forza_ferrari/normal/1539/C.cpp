#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,k,m,a[200001],p[200001],cnt,ans;
signed main()
{
    scanf("%lld%lld%lld",&n,&k,&m);
    for(register int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(register int i=1;i<n;++i)
        if(a[i+1]-a[i]>m)
            p[++cnt]=a[i+1]-a[i];
    sort(p+1,p+cnt+1);
    ans=cnt+1;
    for(register int i=1;i<=cnt;++i)
        if((p[i]-1)/m<=k)
        {
            k-=(p[i]-1)/m;
            --ans;
        }
        else
            break;
    printf("%lld\n",ans);
    return 0;
}