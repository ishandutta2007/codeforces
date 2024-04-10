#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[505][505],f[505][505];
int a[505],vis[505],i,j,n,k;
long long ans[505];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) for (j=1;j<=n;j++) scanf("%d",&A[i][j]);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (k=n;k;k--)
  {    for (i=1;i<=n;i++)
         if (i!=a[k])
        for (j=1;j<=n;j++)
          if (i!=j&&a[k]!=j) 
           A[i][j]=min(A[i][j],A[i][a[k]]+A[a[k]][j]);  
       for (i=n;i>=k;i--)
         for (j=i-1;j>=k;j--)
           ans[k]+=A[a[i]][a[j]]+A[a[j]][a[i]];
   }
  for (i=1;i<=n;i++) { printf("%I64d",ans[i]);
     if (i==n) printf("\n"); else printf(" ");
}
}