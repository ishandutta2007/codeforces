#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a[101][101];
int main()
{ scanf("%d",&k);
  for (i=100;i;i--)
    if (i*(i-1)*(i-2)/6<=k) break;
    k-=i*(i-1)*(i-2)/6;
    for (j=1;j<=i;j++)
      for (p=1;p<=i;p++) 
        a[j][p]=(j!=p);
    for (;k;)
    {    for (j=100;j;j--) if (j*(j-1)/2<=k) break;
          k-=j*(j-1)/2;
         for (p=1,++i;p<=j;p++) a[i][p]=a[p][i]=1;
    }
    printf("%d\n",i);
    for (j=1;j<=i;j++)
     {  for (k=1;k<=i;k++) printf("%d",a[j][k]);
        printf("\n");
     }
}