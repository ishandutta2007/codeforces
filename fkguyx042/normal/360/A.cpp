#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int a[5005],b[5005],l[5005],r[5005],sum[5005],type[5005],Max;
int main()
{ 
   scanf("%d%d",&n,&m);
   for (i=1;i<=m;i++) scanf("%d%d%d%d",&type[i],&l[i],&r[i],&sum[i]);
   for (i=1;i<=n;i++) a[i]=1000000000;
   for (i=1;i<=m;i++)
    if (type[i]==1)
    { 
        for (j=l[i];j<=r[i];j++) b[j]+=sum[i];
    }
    else 
    for (j=l[i];j<=r[i];j++) a[j]=min(a[j],sum[i]-b[j]);
    memset(b,0,sizeof(b));
   for (i=1;i<=m;i++)
   if (type[i]==1)
   { 
      for (j=l[i];j<=r[i];j++) b[j]+=sum[i];
  } 
  else 
  { Max=a[l[i]]+b[l[i]];
   for (j=l[i];j<=r[i];j++)
   Max=max(Max,a[j]+b[j]);
   if (Max!=sum[i]) {
      printf("NO\n");
	  return 0;
}
}
printf("YES\n");
for (i=1;i<=n;i++) printf("%d ",a[i]);
}