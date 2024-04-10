#include<cstdio>
#include<algorithm>
using namespace std;
const long long INF=1e15;
int n,t,a[105],b[105];
long long dp[20005],tmpdp[20005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int j=0;j<=100*n;j++) tmpdp[j]=dp[j]=INF;
        tmpdp[0]=0;
        int Sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=100*n;j++)
            {
                int tmp1=j,tmp2=Sum-j;
                if(tmpdp[j]==INF) continue;
                dp[j+a[i]]=min(dp[j+a[i]],tmpdp[j]+a[i]*tmp1+b[i]*tmp2);
                dp[j+b[i]]=min(dp[j+b[i]],tmpdp[j]+a[i]*tmp2+b[i]*tmp1);
                // printf("dp[%d]->%lld\n",j+a[i],tmpdp[j]+a[i]*tmp1+b[i]*tmp2);
                // printf("dp[%d]->%lld\n",j+b[i],tmpdp[j]+a[i]*tmp2+b[i]*tmp1);
            }
            Sum+=a[i]+b[i];
            for(int j=0;j<=100*n;j++)
            {
                tmpdp[j]=dp[j];
                dp[j]=INF;
            }
        }
        long long sum1=INF,sum2=0;
        for(int i=0;i<=100*n;i++) sum1=min(sum1,tmpdp[i]);
        for(int i=0;i<=n;i++) sum2+=(a[i]*a[i]+b[i]*b[i]);
        printf("%lld\n",sum2*(n-1)+sum1*2);
    }
}