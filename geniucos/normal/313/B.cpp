#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,l1,r1,i,m,dp[100009];
char sir[100009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
gets(sir+1);
n=strlen(sir+1);
scanf("%d",&m);
for(i=2;i<=n;i++)
{
    dp[i]=dp[i-1];
    if(sir[i]==sir[i-1]) dp[i]++;
}
for(i=1;i<=m;i++)
{
    scanf("%d",&l1);
    scanf("%d",&r1);
    printf("%d\n",dp[r1]-dp[l1]);
}
return 0;
}