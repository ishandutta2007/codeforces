#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long f[101],tot,n,l,r;
int a[1001],i;
int main()
{ scanf("%I64d%I64d",&n,&tot);
  f[1]=1;
  for (i=2;i<=n;i++) f[i]=f[i-1]*2ll; l=0,r=n+1;
  for (i=1;i<=n;i++)
  if (f[n-i]<tot) tot-=f[n-i],a[--r]=i;
  else a[++l]=i;
  for (i=1;i<=n;i++) printf("%d ",a[i]);
}