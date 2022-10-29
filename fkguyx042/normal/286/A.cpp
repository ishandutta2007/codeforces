#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int main()
{ scanf("%d",&n);
  if (n%4>1) printf("-1\n");
  else {
   for (i=1;i<=n/2;i++) if (i&1) printf("%d ",i+1); else printf("%d ",n-i+2);
   if (n&1) printf("%d ",n/2+1);
   for (i=n/2+1+(n&1);i<=n;i++) 
     if ((i-n/2-(n&1))&1) printf("%d ",n-i);
     else printf("%d ",i-1);
}
}