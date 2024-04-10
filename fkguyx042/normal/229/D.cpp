#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int dp[5001],tower[5001],sum[5001];
int main()
 {scanf("%d",&n);
  for (i=1;i<=n;i++)
  { scanf("%d",&tower[i]);
    sum[i]=sum[i-1]+tower[i];
  }
  for (i=1;i<=n;i++)
   for (j=i-1;j>=0;j--)
    if (sum[i]-sum[j]>=tower[j])
    {   tower[i]=sum[i]-sum[j];
        dp[i]=dp[j]+i-j-1;
        break;
    }
    printf("%d\n",dp[n]);
}