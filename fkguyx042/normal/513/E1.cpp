#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a[405];
long long f[51][405][405],ans;
int main()
{ scanf("%d%d",&n,&k); 
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=2;i<=n;i++) a[i]+=a[i-1];
  memset(f,128,sizeof(f));
  for (i=1;i<=n;i++)
   for (j=0;j<i;j++)
     f[1][i][j]=0;
  for (i=2;i<=k;i++)
   for (j=i;j<=n;j++)
     for (int I=1;I<j;I++)
      for (int J=0;J<I;J++)
        f[i][j][I]=max(f[i][j][I],f[i-1][I][J]+abs(a[j]-a[I]-a[I]+a[J]));
   for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    ans=max(ans,f[k][i][j]);
    printf("%I64d\n",ans);
  // for (;;);
}