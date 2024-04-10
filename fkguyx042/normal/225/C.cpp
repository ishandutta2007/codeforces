#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans,x,y;
const int INF=(int)1e9;
int f[1001][2][1002];
char c;
int a[1001];
int main()
{ scanf("%d%d%d%d",&n,&m,&x,&y);
  for (i=1;i<=n;i++)
  { c=getchar();
    for (j=1;j<=m;j++)
     c=getchar(),a[j]+=(c=='#');
  }
  memset(f,60,sizeof(f));
  f[1][0][1]=a[1];
    f[1][1][1]=n-a[1];
 for (i=2;i<=m;i++)
    for (j=1;j<=y;j++) {
     if (f[i-1][0][j]<INF)
    {    f[i][0][j+1]=min(f[i][0][j+1],f[i-1][0][j]+a[i]);
      if (j>=x)      f[i][1][1]=min(f[i][1][1],f[i-1][0][j]+(n-a[i]));
    }
    if (f[i-1][1][j ]<INF)
    {  f[i][1][j+1]=min(f[i][1][j+1],f[i-1][1][j]+(n-a[i]));
      if (j>=x)  f[i][0][1]=min(f[i][0][1],f[i-1][1][j]+a[i]);
 
   }
}
ans=INF;
 for (i=x;i<=y;i++) ans=min(ans,min(f[m][0][i],f[m][1][i]));
 printf("%d\n",ans);
 }