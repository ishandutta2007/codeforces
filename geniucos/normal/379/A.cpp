#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int i,a,b,s,r,dp[1009];
int mod(int a)
{
    if(a<0) return -a;
    return a;
}
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&a);
scanf("%d",&b);
dp[0]=0;
for(i=1;i<=a;i++)
    dp[i]=i/b+dp[i/b+i%b];
printf("%d\n",dp[a]+a);
return 0;
}