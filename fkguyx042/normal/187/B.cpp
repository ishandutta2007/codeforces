#include<cstdio>
#include<algorithm>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,q,x,y;
int g[61][61][61],f[61][61][61];
int main()
{  scanf("%d%d%d",&n,&m,&q);
   for (i=1;i<=m;i++)
   {
     for (j=1;j<=n;j++)
       for (k=1;k<=n;k++) scanf("%d",&g[i][j][k]);
       for (int k=1;k<=n;k++)
         for (int I=1;I<=n;I++)
           for (j=1;j<=n;j++)
             g[i][I][j]=min(g[i][I][j],g[i][I][k]+g[i][k][j]);
}
  memset(f,60,sizeof(f));
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      for (k=1;k<=m;k++)
        f[i][j][0]=min(f[i][j][0],g[k][i][j]);
for (int size=1;size<=n;size++)
  for (k=1;k<=n;k++)
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        f[i][j][size]=min(f[i][j][size],f[i][k][size-1]+f[k][j][0]);
 for (;q--;)
 { scanf("%d%d%d",&x,&y,&k);
    k=min(n,k);
    printf("%d\n",f[x][y][k]);
}
}