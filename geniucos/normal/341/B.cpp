#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int i,n,aib[100006],dp[100006],a[100006];
int mod(int x)
{
    if(x<0) return -x;
    return x;
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
int inside(int x1,int y1,int x2,int y2,int x,int y)
{
    return (x>=x1&&x<=x2&&y>=y1&&y<=y2);
}
void U(int p,int val)
{
    while(p<=n)
    {
        if(val>aib[p]) aib[p]=val;
        p+=(p-(p&(p-1)));
    }
}
int Q(int p)
{
    int maxi=0;
    while(p)
    {
        if(aib[p]>maxi) maxi=aib[p];
        p&=p-1;
    }
    return maxi;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
for(i=1;i<=n;i++)
{
    dp[i]=Q(a[i])+1;
    U(a[i],dp[i]);
}
printf("%d\n",Q(n));
return 0;
}