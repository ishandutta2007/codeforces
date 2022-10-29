#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int a[1000001],Last[1000001];
int main()
{ scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%d",&a[i]);
  int k=a[n];
  Last[n]=1;
  for (i=n-1;i;i--)
  if (k>0) k-=a[i],Last[i]=0;
  else k+=a[i],Last[i]=1;
  if (k<0) for (i=1;i<=n;i++) Last[i]=1-Last[i];
  for (i=1;i<=n;i++)
  if (!Last[i]) printf("-"); else printf("+");
}