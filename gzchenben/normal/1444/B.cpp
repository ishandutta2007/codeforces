#include<cstdio>
#include<algorithm>
#define mod (998244353)
using namespace std;
int n,a[600005];
long long ans1,ans2,tmp1=1,tmp2=1;
long long qpow(long long x,long long y)
{
    long long res=1;
    while(y)
    {
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+2*n+1);
    for(int i=1;i<=n;i++)
    {
        tmp1=tmp1*i%mod;
        tmp2=tmp2*(2*n-i+1)%mod;
        ans2=(ans2+a[2*n-i+1]-a[i])%mod;
    }
    ans1=tmp2*qpow(tmp1,mod-2)%mod;
    printf("%lld\n",ans1*ans2%mod);
}