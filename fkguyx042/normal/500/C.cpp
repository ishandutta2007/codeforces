#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1001],vis[1001],order[10001],w[10001];
int i,j,m,n,p,k,ans;
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++) scanf("%d",&w[i]);
  for (i=1;i<=m;i++) { 
  scanf("%d",&order[i]);
  if (!vis[order[i]]) a[++a[0]]=order[i],vis[order[i]]=1;
  }
  for (i=1;i<=m;i++)
 {   for (j=1;j<=a[0];j++) { 
        if (a[j]==order[i]) break;
        ans+=w[a[j]];
     }
     for (k=j;k>1;k--) a[k]=a[k-1];
     a[1]=order[i];
 }
 printf("%d\n",ans);
}