#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define int long long
int t,n,a[300005],ans,sum,maxn;
bool b[300005];
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        memset(b,0,sizeof b);
        ans=0;
        for(register int i=1;i<=n;++i)
            scanf("%lld",&a[i]);
        for(register int i=2;i<n;++i)
            if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))
            {
                b[i]=1;
                ++ans;
            }
        maxn=ans;
        for(register int i=1;i<=n;++i)
        {
            int tmp=a[i];
            a[i]=a[i-1];
            sum=0;
            for(register int j=max(i-2,2ll);j<=min(n-1,i+2);++j)
                if((a[j]>a[j-1]&&a[j]>a[j+1])||(a[j]<a[j-1]&&a[j]<a[j+1]))
                {
                    if(!b[j])
                        ++sum;
                }
                else
                    if(b[j])
                        --sum;
            maxn=min(maxn,ans+sum);
            sum=0;
            a[i]=a[i+1];
            for(register int j=max(i-2,2ll);j<=min(n-1,i+2);++j)
                if((a[j]>a[j-1]&&a[j]>a[j+1])||(a[j]<a[j-1]&&a[j]<a[j+1]))
                {
                    if(!b[j])
                        ++sum;
                }
                else
                    if(b[j])
                        --sum;
            a[i]=tmp;
            maxn=min(maxn,ans+sum);
        }
        printf("%lld\n",maxn);
    }
    return 0;
}