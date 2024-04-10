#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans;
int vis[1001],Vis[1001];
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
  { scanf("%d%d",&p,&k);
     vis[p]=Vis[k]=1;
  }
  for (i=2;i<n;i++)
  {  if (vis[i]==0)
         ans++;
      if (Vis[i]==0) ans++;
}
   if ((n&1)&&(!vis[n/2+1])&&(!Vis[n/2+1])) ans--;
printf("%d\n",ans);
}