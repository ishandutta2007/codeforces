#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans;
int vis[100001],a[100001];
int main()
{ scanf("%d%d%d",&n,&p,&k);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (;p!=k&&!vis[p];ans++)
  {  vis[p]=1; p=a[p]; }
  if (p==k) printf("%d\n",ans);
  else printf("-1\n");
}