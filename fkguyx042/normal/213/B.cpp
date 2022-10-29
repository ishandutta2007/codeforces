#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)(1e9)+7;
int i,j,m,n,p,k;
long long f[105][11],ans;
int a[10],c[105][105];
int main()
{scanf("%d",&n);
  for (i=0;i<10;i++) scanf("%d",&a[i]);
  for (i=0;i<=n;i++)
  { c[i][0]=1;
     for (j=1;j<=i;j++)
       c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mo;
  }
  for (i=0;i<=n;i++)
  {  f[i][9]=i>=a[9]?1:0;
    for (j=8;j>=1;j--)
      for (k=a[j];k<=i;k++)
        f[i][j]=(f[i][j]+1ll*f[i-k][j+1]*c[i][k])%Mo;
    for (k=a[0];k<=i;k++) f[i][0]=(f[i][0]+1ll*f[i-k][1]*c[i-1][k])%Mo;
}
for (i=1;i<=n;i++)
 (ans+=f[i][0])%=Mo;
 printf("%I64d\n",ans);
}