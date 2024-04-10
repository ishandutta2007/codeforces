#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;
int E1,E2,i,j,k,n,m;
double s,sol,p,A[100009],sum;
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
double Pow(double a,int b)
{
    int i;
    double p=1;
    for(i=0;(1<<i)<=b;i++)
    {
        if((b&(1<<i))) p=(double)p*a;
        a=(double)a*a;
    }
    return p;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d%d",&m,&n);
for(i=1;i<=m;i++)
    A[i]=Pow((double)i/m,n);
for(i=1;i<=m;i++)
{
    A[i]-=s;
    sol+=A[i]*i;
    s+=A[i];
}
/*dp[0][0]=1;
for(j=0;j<=m;j++)
    s[0][j]=1;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        dp[i][j]=(double)dp[i-1][j]*((double)(j-1)/m)+s[i-1][j]*((double)1/m);
        s[i][j]=(double)s[i][j-1]+dp[i][j];
    }
for(i=1;i<=n;i++,printf("\n"))
    for(j=1;j<=m;j++)
        printf("%.5lf ",dp[i][j]);
for(j=m;j>=1;j--)
{
    sum+=dp[n][j];
    AA[j]=sum;
}
for(j=1;j<=m;j++)
    printf("%.6lf ",AA[j]);
sol=0;
for(j=1;j<=m;j++)
    sol+=j*dp[n][j];
printf("%.6lf\n",sol);*/
/*p=1;
E2=m-1;
E1=n;
for(i=n;i<=n+m-2;i++)
{
    p=(double)p*i;
    if(E1&&p>0.0001) E1--,p/=m;
    if(E2&&p>0.0001) p/=E2,E2--;
}
for(i=1;i<=E2;i++)
    p=(double)p/i;
for(i=1;i<=E1;i++)
    p/=m;
sol=(double)p*m;
for(k=m-1;k>=1;k--)
{
    p=(double)p/(n+k-1)*k;
    sol+=(double)p*k;
}*/
printf("%.6lf\n",sol);
return 0;
}