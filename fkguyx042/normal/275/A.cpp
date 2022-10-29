#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int a[5][5],b[5][5];
int main()
{  for (i=1;i<=3;i++)for (j=1;j<=3;j++) scanf("%d",&a[i][j]);
  memset(b,1,sizeof(b));
  for (i=1;i<=3;i++)
    for  (j=1;j<=3;j++)
       b[i][j]+=a[i][j-1]+a[i-1][j]+a[i][j+1]+a[i+1][j]+a[i][j];
  for (i=1;i<=3;i++)
  {  for (j=1;j<=3;j++)
      printf("%d",b[i][j]%2);
     printf("\n");
}
}