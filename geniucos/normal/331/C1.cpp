#include<cstdio>
using namespace std;
int i,n,cif,aux,dp[1000009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
dp[0]=0;
for(i=1;i<=n;i++)
{
    dp[i]=i;
    aux=i;
    while(aux>0)
    {
        cif=aux%10;
        if(cif!=0&&dp[i-cif]<dp[i]) dp[i]=dp[i-cif];
        aux/=10;
    }
    dp[i]++;
}
printf("%d\n",dp[n]);
return 0;
}