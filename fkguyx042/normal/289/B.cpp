#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int i,j,m,n,p,k,mid,ans;
int a[10001],d;
int main()
{ scanf("%d%d%d",&n,&m,&d);
  n*=m;
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  mid=min(n,(n>>1)+1);
  for (i=1;i<=n;i++)
  if (abs(a[i]-a[mid])%d!=0) {printf("-1\n"); return 0;}
  else ans+=abs(a[i]-a[mid])/d;
printf("%d\n",ans);
}