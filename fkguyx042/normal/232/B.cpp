#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
long long i,j,m,n,p,k,Mp,Max;
long long f[101][10001],c[101][101],G[101][101][2];
long long power(long long x,long long y) 
{ long long sum=1; 
  if (!x) return 1;
   for (;y;y>>=1) 
   {  if (y&1) sum=1ll*sum*x%Mo;
      x=1ll*x*x%Mo;
  }
  return sum;
}
int main()
{ scanf("%I64d%I64d%I64d",&n,&m,&k);
  for (i=1;i<=100;i++)
    for (j=1;j<=i;j++) 
    {  c[i][j]=1;
        for (p=2;p<=i;p++) (c[i][j]*=p)%=Mo;
        for (p=2;p<=j;p++) (c[i][j]*=power(p,Mo-2))%=Mo;
        for (p=2;p<=i-j;p++) (c[i][j]*=power(p,Mo-2))%=Mo;
    }
    for (i=0;i<=100;i++) for (j=0;j<=100;j++) for (p=0;p<2;p++) G[i][j][p]=1;
    //memset(G,1,sizeof(G));
    for (i=1;i<=100;i++) for (j=1;j<=i;j++)
      G[i][j][0]=power(c[i][j],m/n),G[i][j][1]=power(c[i][j],m/n+1);
    f[0][0]=1;
   for (i=1;i<=n;i++)
     for (j=0,Mp=min(i*n,k);j<=Mp;j++)
        for (p=0,Max=min(j,n);p<=Max;p++)
           if (f[i-1][j-p]!=0)
          (f[i][j]+=f[i-1][j-p]*G[n][p][m%n>=i?1:0])%=Mo;//power(c[n][p],m/n+(m%n>=i?1:0)))%=Mo;
  printf("%I64d\n",f[n][k]);
}