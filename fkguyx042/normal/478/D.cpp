#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int h,r,g,i,j,m,n,p,k,dp[2000010],ans;
int main()
{ scanf("%d%d",&r,&g);
  for (i=1;i*(i+1)/2<=r+g;i++);
  i--;
  h=i;
  int sum=h*(h+1)/2;
  dp[0]=1;
  for (i=1;i<=h;i++)
   for (j=r;j>=i;j--)
    (dp[j]+=dp[j-i])%=Mo;
 for (i=0;i<=r;i++)
   if (sum-i<=g) (ans+=dp[i])%=Mo;
   printf("%d\n",ans);
}