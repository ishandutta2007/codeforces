#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100001];
int b[100001];
int i,j,m,n,p,k;
int main()
{ scanf("%d%d%d",&n,&m,&k);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (j=1;j<=m;j++) scanf("%d",&b[j]);
  sort(a+1,a+n+1); sort(b+1,b+m+1);
  while (n>0&&m>0)
{  if (b[m]>=a[n]) { n--; m--; } else break; }
if (n>0) printf("YES\n"); else printf("NO\n");
}