#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const long long Inf=(long long)1e14;
int i,j,m,n,p,k;
long long c[301][301];
struct Node{int l,r,c;}a[100001];
long long f[301][301],ans=Inf;
int main()
{ scanf("%d%d%d",&n,&m,&k);
  for (i=1;i<=m;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].c);
  for (i=0;i<=300;i++) for (j=0;j<=300;j++) c[i][j]=f[i][j]=Inf;
  for (i=n;i;i--)
  {   for (j=1;j<=m;j++) 
  if (a[j].r>=i&&a[j].l<=i) c[a[j].l][i]=min((long long)a[j].c,c[a[j].l][i]);
      for (j=2;j<=i;j++) c[j][i]=min(c[j][i],c[j-1][i]);
  }
  f[0][0]=0;
  for (i=1;i<=n;i++) {
    for (j=0;j<=i;j++)
     {
        for (int I=i-j;I<=k;I++)
           f[i][I]=min(f[i][I],f[j][I-(i-j)]+c[j+1][i]);
        for (int I=0;I<=k;I++)
          f[i][I]=min(f[i][I],f[j][I]);
     }
     ans=min(ans,f[i][k]);
}
   if (ans==Inf) printf("-1\n");
   else printf("%I64d\n",ans);
}