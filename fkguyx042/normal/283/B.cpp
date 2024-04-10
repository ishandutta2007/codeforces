#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
long long f[200001][2];
int a[200001],vis[200001][2];
long long dfs(int x,int Now)
{   if (x<1||x>n) return 0;
   if (f[x][Now]) return f[x][Now];
   if (vis[x][Now]) return -1;
   vis[x][Now]=1;
   if (!Now)
    f[x][Now]=dfs(x+a[x],1-Now);
   else f[x][Now]=dfs(x-a[x],1-Now);
if (f[x][Now]!=-1) f[x][Now]+=a[x];
return f[x][Now];
}
int main()
{scanf("%d",&n);
  for (i=2;i<=n;i++) scanf("%d",&a[i]);
  for (i=2;i<=n;i++) for (j=0;j<2;j++) dfs(i,j);
  for (i=1;i<n;i++)
   if (f[i+1][1]==-1) printf("-1\n");
   else printf("%I64d\n",f[i+1][1]+i);
}