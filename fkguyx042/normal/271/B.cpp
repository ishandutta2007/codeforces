#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int a[501][501];
int Prime[100020],vis[200001],ans=(int)1e9,r[501],l[501];
int main()
 {scanf("%d%d",&n,&m);
    for (i=2;i<=200000;i++)
      if (!vis[i])
      {  Prime[++Prime[0]]=i;
         for(j=i;j<=200000;j+=i)
         vis[j]=1;
      }
   for (i=1;i<=n;i++)
   for (j=1;j<=m;j++) 
   scanf("%d",&a[i][j]),a[i][j]=Prime[lower_bound(Prime+1,Prime+Prime[0]+1,a[i][j])-Prime]-a[i][j];
   for (i=1;i<=n;i++)
    for (j=1;j<=m;j++) r[i]+=a[i][j],l[j]+=a[i][j];
   for (i=1;i<=n;i++) ans=min(ans,r[i]);
   for (i=1;i<=m;i++) ans=min(ans,l[i]);
   printf("%d\n",ans);
}