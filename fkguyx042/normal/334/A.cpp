#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int main()
{ scanf("%d",&n);
  for (i=1;i<=n*n/2;)
  {  for (j=1;j<=n/2;j++)
     {   printf("%d %d",i,n*n-i+1); i++;
        if (j==n/2) printf("\n"); else printf(" ");
     }
}
}