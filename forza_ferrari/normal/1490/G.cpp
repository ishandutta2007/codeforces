#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int t,n,m,a[200001],sum[200001],maxn[200001];
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        maxn[0]=-1e18;
        sum[0]=0;
        for(register int i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
            sum[i]=sum[i-1]+a[i];
            maxn[i]=-1e18;
            maxn[i]=max(maxn[i-1],sum[i]);
        }
        while(m--)
        {
            int x;
            scanf("%lld",&x);
            if(maxn[n]>=x)
            {
                printf("%lld ",(long long)(lower_bound(maxn+1,maxn+n+1,x)-maxn-1));
                continue;
            }
            if(sum[n]<=0&&x>0)
            {
                printf("-1 ");
                continue;
            }
            int l=0,r=1e9,mid,ans=1e9;
            while(l<r)
            {
                mid=(l+r)>>1;
                if(mid*sum[n]+maxn[n]>=x)
                {
                    r=mid;
                    ans=mid;
                }
                else
                    l=mid+1;
            }
            printf("%lld ",(long long)(ans*n+(long long)(lower_bound(maxn+1,maxn+n+1,x-ans*sum[n])-maxn-1)));
        }
        puts("");
    }
    return 0;
}