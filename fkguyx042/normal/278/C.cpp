#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[101][101];
int b[101][101];
int c[101][101];
int flag[101]; 
int i,j,m,n,p,k,ans,ans1;
void dfs(int num)
 {  int i;
   flag[num]=1;
    for (i=1;i<=n;i++)
     if (!flag[i]&&c[num][i])
      dfs(i);
}
int main()
 {scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
   { scanf("%d",&a[i][0]);
     for (j=1;j<=a[i][0];j++)
     { scanf("%d",&a[i][j]);
      b[i][a[i][j]]=1; }
      }
 for (i=1;i<=n;i++)
  for (j=i+1;j<=n;j++)
    for (k=1;k<=m;k++)
     if (b[i][k]&&b[j][k])c[i][j]=c[j][i]=1;
 for (k=1;k<=n;k++)
  for (i=1;i<=n;i++)
   if (i!=k&&c[i][k])
    for (j=1;j<=n;j++)
     if (j!=k&&i!=j&&c[k][j])
       c[i][j]=1;
 for (i=1;i<=n;i++)
  if (!flag[i])
   { if (a[i][0]==0) ans++;
      else { ans1++; dfs(i); } 
}
if (ans1>0) ans+=ans1-1;
printf("%d\n",ans);
return 0;
}