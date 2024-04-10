#include<cstdio>
using namespace std;
const long long mod=1000000007;
int n,q;
long long Fac[3000005],InvFac[3000005],dp[3000005][3];
long long QuickPow(long long x,long long y)
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
long long C(int x,int y)
{
    if(x>y) return 0;
    else return Fac[y]*InvFac[x]%mod*InvFac[y-x]%mod;
}
int main()
{
    scanf("%d%d",&n,&q);
    Fac[0]=1;
    for(int i=1;i<=3*n+1;i++)
    {
        Fac[i]=Fac[i-1]*i%mod;
    }
    InvFac[3*n+1]=QuickPow(Fac[3*n+1],mod-2);
    for(int i=3*n;i>=0;i--)
    {
        InvFac[i]=InvFac[i+1]*(i+1)%mod;
    }
    long long Inv3=QuickPow(3,mod-2);
    for(int i=0;i<=3*n;i++)
    {
        //Sum = C(i+1,3n) dp[i][1]-dp[i][0]=dp[i-1][0] dp[i][2]-dp[i][1]=dp[i-1][   1]
        long long Sum=C(i+1,3*n);
        if(i==0) 
        {
            dp[i][0]=dp[i][1]=dp[i][2]=Sum*Inv3%mod;
            continue;
        }
        dp[i][0]=(Sum-dp[i-1][0]-(dp[i-1][0]+dp[i-1][1])+3*mod)%mod*Inv3%mod;
        dp[i][1]=(dp[i][0]+dp[i-1][0])%mod;
        dp[i][2]=(dp[i][1]+dp[i-1][1])%mod;
    }
    for(int i=1;i<=q;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%lld\n",(dp[x][0]+C(x,3*n))%mod);
    }
}