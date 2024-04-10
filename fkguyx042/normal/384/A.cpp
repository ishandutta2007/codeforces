#include<cstdio>
#include<algorithm>
using namespace std;
int i,j,m,n,p,k,ans;
int a[1001][1001];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++)
   if (i&1)
    for (j=1;j<=n;j+=2) a[i][j]=1,ans++;
   else for (j=2;j<=n;j+=2) a[i][j]=1,ans++;
printf("%d\n",ans);
for  (i=1;i<=n;i++)
{  for (j=1;j<=n;j++)
    if (a[i][j]) printf("C"); else printf(".");
    printf("\n");
}
}