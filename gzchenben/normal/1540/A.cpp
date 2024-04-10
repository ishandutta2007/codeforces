#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,d[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&d[i]);
        }
        sort(d+1,d+n+1);
        long long ans=0,sum=0;
        for(int i=2;i<=n;i++)
        {
            ans+=(long long)(i-1)*d[i]-sum;
            sum+=d[i];
        }
        printf("%lld\n",-ans+d[n]);
    }
}