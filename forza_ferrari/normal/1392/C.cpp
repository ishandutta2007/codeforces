#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,k,ans,a[200001],maxn;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=maxn=k=0;
        for(register int i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
            maxn=max(maxn,a[i]);
            a[i]=maxn-a[i];
            if(a[i]>k)
                ans+=a[i]-k;
            k=a[i];
        }
        printf("%lld\n",ans);
    }
	return 0;
}