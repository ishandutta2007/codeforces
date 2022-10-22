#include<cstdio>
#include<map>
#define mod (1000000007)
using namespace std;
int n,t;
long long dp[200005],sum,a[200005],s[200005];
map<long long,long long> mp;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            s[i]=s[i-1]+a[i];
        }
        sum=1;
        dp[0]=1;
        mp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=(sum-mp[s[i-1]]+mod)%mod;
            mp[s[i-1]]=(mp[s[i-1]]+dp[i])%mod;
            sum=(sum+dp[i])%mod;
        }
        printf("%lld\n",sum);
    }
}