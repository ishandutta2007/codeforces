#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int main()
{  scanf("%d",&n);
   if (n&1)
{  for (i=0;i<n;i++) printf("%d ",i); printf("\n");
   for (i=0;i<n;i++) printf("%d ",i); printf("\n");
   for (i=0;i<n;i++) printf("%d ",i*2%n); printf("\n");
}
else printf("-1\n");             
}