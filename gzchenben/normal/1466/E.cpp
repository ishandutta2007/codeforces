#include<cstdio>
#define mod (1000000007)
using namespace std;
int n,t;
long long a[500005],BIT[61],num[61];
int main()
{
    BIT[1]=1;
    for(int i=2;i<=60;i++)
    {
        BIT[i]=BIT[i-1]*2;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            for(int j=1;j<=60;j++)
            {
                if(a[i] & BIT[j]) num[j]++;
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            long long sumAnd=0,sumOr=0;
            for(int j=1;j<=60;j++)
            {
                if(a[i] & BIT[j])
                {
                    sumAnd+=BIT[j]%mod*num[j]%mod;
                    sumOr+=BIT[j]%mod*n%mod;
                }
                else
                {
                    sumOr+=BIT[j]%mod*num[j]%mod;
                }
            }
            ans=(ans+((sumAnd%mod)*(sumOr%mod)%mod))%mod;
        }
        printf("%lld\n",ans);
        for(int i=1;i<=60;i++) num[i]=0;
    }
}