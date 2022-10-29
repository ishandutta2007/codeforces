#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
using namespace std;
int x[1001],y[1001],vis[1001],ans,n,i;
void dfs(int X)
{  int i;
   vis[X]=1;
   for (i=1;i<=n;i++)
     if (!vis[i])
    {  if (x[X]==x[i]||y[X]==y[i]) dfs(i);
}
}
int main()
{scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d%d",&x[i],&y[i]);
  dfs(1);
  for (i=2;i<=n;i++)
   if (!vis[i])
   {  ans++;
     dfs(i);
}
printf("%d\n",ans);
}