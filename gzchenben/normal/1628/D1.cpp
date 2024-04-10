#include<cstdio>
using namespace std;
const int N=2000;
const long long Mod=1e9+7;
long long dp[2005][2005];
long long qpow(long long x,long long y)
{
    long long res=1;
    while(y)
    {
        if(y&1) res=res*x%Mod;
        x=x*x%Mod;
        y>>=1;
    }
    return res;
}
long long Inv(long long x)
{
    return qpow(x,Mod-2);
}
void Init()
{
    long long Inv2=Inv(2);
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
            {
                dp[i][j]=0;
                continue;
            }
            if(i==j) 
            {
                dp[i][j]=dp[i-1][j-1]+1;
                continue;
            }
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])*Inv2%Mod;
        }
    }
}
int main()
{
    Init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        printf("%lld\n",dp[n][m]*k%Mod);
    }
}