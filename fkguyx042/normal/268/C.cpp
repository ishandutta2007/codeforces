#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,i,x;
int main()
{ scanf("%d%d",&n,&m);
  if (n==m){printf("%d\n",n+1);
   for (i=0;i<=n;i++) printf("%d %d\n",n-i,i);
 }
else {
  x=min(n,m);
  printf("%d\n",x+1);
  for (i=0;i<=x;i++) printf("%d %d\n",n-i,m-i); }
}