#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[201][30001][2][2][2];
int g[30001][2][2],i,j,m,n,p,k,x[30001][2][2],y[30001][2],ans,a[30001],G[30001][2];
int Min[30001],Max[30001];
void get(int x)
{ memset(g,128,sizeof(g));
  int i,j,k,p;
  for (i=1;i<=n;i++)
    for (j=0;j<2;j++)
     for (k=0;k<2;k++)
       for (p=0;p<2;p++)
        g[i][k][p]=max(g[i][k][p],f[x][i][j][k][p]);
  for (i=2;i<=n;i++)
    for (j=0;j<2;j++) 
      for (k=0;k<2;k++)
       g[i][j][k]=max(g[i][j][k],g[i-1][j][k]);
}
void Get()
{  int i,j,k;
    memset(G,128,sizeof(G));
   for (i=1;i<=n;i++)
     for (j=0;j<2;j++)
      for (k=0;k<2;k++)
      G[i][k]=max(G[i][k],x[i][j][k]);
     for (i=2;i<=n;i++)
       for (j=0;j<2;j++)
         G[i][j]=max(G[i][j],G[i-1][j]);
}
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=n;i++) a[i]+=a[i-1];
  Min[1]=a[1];
  Max[1]=a[1];
  memset(f,128,sizeof(f));
  for (i=1;i<=n;i++) Min[i]=min(Min[i-1],a[i]),Max[i]=max(Max[i-1],a[i]);
  for (i=1;i<=n;i++)
   f[1][i][0][0][0]=-a[i]+Max[i-1],
   f[1][i][0][0][1]=-3*a[i]+Max[i-1],
   f[1][i][0][1][0]=3*a[i]-Min[i-1],
   f[1][i][0][1][1]=a[i]-Min[i-1];
  get(1);
  for (i=2;i<k-1;i++)
{   for (j=i;j<=n;j++)
   {  
       f[i][j][0][0][0]=g[j-1][0][0];
       f[i][j][0][0][1]=g[j-1][0][0]-2*a[j];
       f[i][j][0][1][0]=g[j-1][0][1]+4*a[j];
       f[i][j][0][1][1]=g[j-1][0][1]+2*a[j];
       f[i][j][1][0][0]=g[j-1][1][0]-2*a[j];
       f[i][j][1][0][1]=g[j-1][1][0]-4*a[j];
       f[i][j][1][1][0]=g[j-1][1][1]+2*a[j];
       f[i][j][1][1][1]=g[j-1][1][1];
    }
    get(i);
}
   memset(x,128,sizeof(x));
   if (k>2) 
{ 
   for (j=k-1;j<=n;j++)
 {   x[j][0][0]=g[j-1][0][0]-a[j];
     x[j][0][1]=g[j-1][0][1]+3*a[j];
     x[j][1][0]=g[j-1][1][0]-3*a[j];
     x[j][1][1]=g[j-1][1][1]+a[j];
 }
} 
  else for (i=1;i<=n;i++)
   x[i][0][0]=-2*a[i]+Max[i-1],
   x[i][0][1]=2*a[i]-Min[i-1];
   memset(y,128,sizeof(y));
   Get();
  for (i=k;i<=n;i++)
 {   y[i][0]=G[i-1][0]+a[i];
     y[i][1]=G[i-1][1]-a[i];
}
  for (i=1;i<=n;i++)
    ans=max(ans,max(y[i][0],y[i][1]));
  printf("%d\n",ans);
}