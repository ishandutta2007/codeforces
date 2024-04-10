#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans;
int A[11],B[11],vis[11][11];
char c;
int main()
{ scanf("%d%d",&n,&m);
  c=getchar();
  for (i=1;i<=n;i++)
  {  for (j=1;j<=m;j++) {
      c=getchar(); if (c=='S') A[i]=B[j]=1,vis[i][j]=1; }
      c=getchar(); }
for (i=1;i<=n;i++)
  for (j=1;j<=m;j++)
   if (!(A[i]&B[j]))  if (!vis[i][j])ans++; printf("%d\n",ans);
}