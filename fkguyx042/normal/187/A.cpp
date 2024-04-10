#include<cstdio>
using namespace std;
int a[200001],b[200001],A[200001];
int i,j,m,n,p,k;
int main()
{scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (j=1;j<=n;j++) scanf("%d",&b[j]),A[b[j]]=j;
  for (i=2;i<=n;i++) if (A[a[i]]<A[a[i-1]]) break;
  printf("%d\n",n-i+1);
}