#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int seed=10003;
int i,j,m,n,p,k,cnt,x,y;
long long h[1000001],val[1000001],pre,ans,H[1000001];
int main()
{ val[1]=1;
  scanf("%d%d",&n,&m);
  for (i=2;i<=n;i++) val[i]=val[i-1]*seed;
  for (i=1;i<=m;i++)
{   scanf("%d%d",&x,&y);
    h[x]+=val[y];
    h[y]+=val[x];
}
  pre=-1; cnt=0;
  for (i=1;i<=n;i++) H[i]=h[i]+val[i];
  sort(h+1,h+n+1);
  for (i=1;i<=n;i++)
  if (h[i]==pre) cnt++,ans+=cnt;
  else cnt=0,pre=h[i];
  sort(H+1,H+n+1);
  pre=-1,cnt=0;
  for (i=1;i<=n;i++)
  if (H[i]==pre) cnt++,ans+=cnt;
  else cnt=0,pre=H[i];
  printf("%I64d\n",ans);
}