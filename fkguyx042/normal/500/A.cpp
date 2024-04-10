#include<cstdio>
using namespace std;
int i,j,m,n,A[300001],t;
int main()
{ scanf("%d%d",&n,&t);
  for (i=1;i<n;i++) scanf("%d",&A[i]);
  for (j=1;j<t;j=j+A[j]);
  if (j==t) printf("YES\n");
  else printf("NO\n");
}