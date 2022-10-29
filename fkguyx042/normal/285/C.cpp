#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int i,j,m,n,p,k;
int a[1000001];
long long ans;
int main()
{scanf("%d",&n);
for (i=1;i<=n;i++) scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  for (i=1;i<=n;i++) ans+=abs(i-a[i]);
  printf("%I64d\n",ans);}