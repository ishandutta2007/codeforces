#include<cstdio>
#include<algorithm>
using namespace std;
int b[1000001],f[1000001][2],a[50001][20],f1[100001];
int i,j,m,n,p,k;
int main()
 {scanf("%d%d%d",&n,&m,&k);
  for (i=1;i<=n;i++)
   for (j=1;j<=m;j++)
    scanf("%d",&a[i][j]);
  for (i=1;i<=k;i++)
   { scanf("%d%d",&f[i][0],&f[i][1]);
     b[f[i][1]]++;
   }
 for (i=1;i<=n;i++)
  for (j=1;j<=m;j++)
   if (a[i][j])
    f1[i]+=b[j];
 for (j=1;j<=k;j++)
  f1[f[j][0]]--;
 for (i=1;i<=n-1;i++) printf("%d ",f1[i]);
 printf("%d\n",f1[n]);
 return 0;
}