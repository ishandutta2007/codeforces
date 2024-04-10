#include<cstdio>
#include<algorithm>
using namespace std;
int x[5001],y[5001];
int a[5001][5001],i,j,m,n,p,k,X,Y;
char c[2];
int main()
{ scanf("%d%d%d",&n,&m,&k);
  for (i=1;i<=n;i++) for (j=1;j<=m;j++) scanf("%d",&a[i][j]);
  for (i=1;i<=n;i++) x[i]=i; for (j=1;j<=m;j++) y[j]=j;
  for (;k--;)
  {scanf("%s",&c);
    scanf("%d%d",&X,&Y);
    if (c[0]=='c') swap(y[X],y[Y]);
    if (c[0]=='r') swap(x[X],x[Y]);
    if (c[0]=='g') printf("%d\n",a[x[X]][y[Y]]);
}
}