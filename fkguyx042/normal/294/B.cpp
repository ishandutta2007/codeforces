#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[101][201];
int i,j,m,n,p,k;
struct node{int l;int r;}a[100001];
int main()
 {scanf("%d",&n);
   for (i=1;i<=n;i++)
     scanf("%d%d",&a[i].l,&a[i].r);
 memset(f,60,sizeof(f));
 f[0][0]=0;
 for (i=1;i<=n;i++)
  { for (j=a[i].l;j<=200;j++)
       if (f[i-1][j-a[i].l]<=2000) f[i][j]=min(f[i][j],f[i-1][j-a[i].l]);
    for (j=0;j<=200;j++)
       if (f[i-1][j]<=2000) f[i][j]=min(f[i][j],f[i-1][j]+a[i].r);
}
for (i=0;i<=200;i++)
  if (i>=f[n][i])
   { printf("%d\n",i);
     return 0;
}
}