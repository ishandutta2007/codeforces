#include<cstdio>
#include<algorithm>
int i,j,m,n,p,k;
int main()
{scanf("%d%d",&n,&k);
  for (i=k+1;i;i--) printf("%d ",i);
  for (i=k+2;i<=n;i++) printf("%d ",i);
}