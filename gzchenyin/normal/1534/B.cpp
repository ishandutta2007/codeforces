#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,t,a[400005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        a[n+1]=0;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int tmp=max(a[i-1],a[i+1]);
            if(a[i]>tmp) 
            {
                ans+=a[i]-tmp;
                a[i]=tmp;
            }
        }
        for(int i=0;i<=n;i++)
        {
            ans+=abs(a[i]-a[i+1]);
        }
        printf("%lld\n",ans);
    }
}