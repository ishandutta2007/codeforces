#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,p,k,a[105],b[105],n,m,vis[105],ans;
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  scanf("%d",&m);
  for (i=1;i<=m;i++) scanf("%d",&b[i]);
  sort(a+1,a+n+1);
  sort(b+1,b+m+1);
  for (i=n;i;i--)
{  for (j=m;j;j--)
     if (abs(a[i]-b[j])<=1&&!vis[j]) { ans++; vis[j]=1; break; }
}
printf("%d\n",ans);
}