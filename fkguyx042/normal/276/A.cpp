#include<cstdio>
#include<algorithm>
using namespace std;
int a[10001],i,j,m,n,p,k;
int f[10001],g[10001],ans=-(int)1e9;
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++)

  { scanf("%d%d",&f[i],&g[i]);
    if (g[i]>k) ans=max(ans,f[i]-(g[i]-k));
    else ans=max(ans,f[i]);
}
printf("%d\n",ans);
}