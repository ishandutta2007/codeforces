#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a[22],b[22];
long long ans[22][22],f[22][22][22],s[22][22];
void cheng(long long A[22][22],long long B[22][22])
{  long long c[22][22];
int k,i,j;
   memset(c,50,sizeof(c));
   for (k=0;k<=n;k++)
     for (i=0;i<=n;i++)
       for (j=0;j<=n;j++)
         c[i][j]=min(c[i][j],A[i][k]+B[k][j]);
    for (i=0;i<=n;i++)
      for (j=0;j<=n;j++) A[i][j]=c[i][j];
}
int main()
{ scanf("%d%d",&n,&m);
  for (i=0;i<n;i++) scanf("%d",&a[i]);
  for (i=0;i<n;i++) scanf("%d",&b[i]);
  memset(f,50,sizeof(f));
  for (i=0;i<=n;i++)
  {   f[i][0][i]=0;
      for (j=0;j<n;j++)
        for (k=0;k<=n;k++)
        {  f[i][j+1][k+1]=min(f[i][j+1][k+1],f[i][j][k]+a[j]);
           if (k>0) f[i][j+1][k-1]=min(f[i][j+1][k-1],f[i][j][k]+b[j]);
        }
  }
  memset(ans,50,sizeof(ans));
  for (i=0;i<=n;i++) ans[i][i]=0;
  for (i=0;i<=n;i++)
    for (j=0;j<=n;j++)
        s[i][j]=f[i][n][j];
  for (;m;m>>=1)
  {  if (m&1)  cheng(ans,s);
    cheng(s,s);
  }
  printf("%I64d\n",ans[0][0]);
}