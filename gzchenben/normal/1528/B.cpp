#include<cstdio>
#define mod (998244353)
using namespace std;
int n;
long long sum,f[1000005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            f[j]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        f[i]=(f[i]+sum)%mod;
        sum=(sum+f[i])%mod;
    }
    printf("%lld\n",f[n]);
}