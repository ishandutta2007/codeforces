#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1000001],b[1000001],c[1000001],fail[1000001],d[1000001];
int i,j,m,n,p,k,ans;
int main()
{ scanf("%d%d",&n,&m);
  if (m==1) { printf("%d\n",n);}
  else {
  	  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  	  for (i=1;i<n;i++) c[i]=a[i]-a[i+1];
  	  n--;
  	  for (i=1;i<=m;i++) scanf("%d",&b[i]);
  	  for (i=1;i<m;i++) d[i]=b[i]-b[i+1];
  	  m--;
      for (i=2,j=0;i<=m;i++)
      {   while (j&&d[i]!=d[j+1]) j=fail[j];
         if (d[i]==d[j+1]) j++;
         fail[i]=j;
      }
      for (i=1,j=0;i<=n;i++)
      {  while (j&&c[i]!=d[j+1]) j=fail[j];
         if (c[i]==d[j+1]) j++;
         if (j==m) ans++,j=fail[j];
    }
printf("%d\n",ans);
}
}