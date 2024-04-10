#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans,sum;
int a[100001],b[100001];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  scanf("%d",&m);
  for (i=1;i<=m;i++) scanf("%d",&b[i]);
  for (i=1;i<=n;i++)
   for (j=1;j<=m;j++)
     if (b[j]%a[i]==0)
     {  if (b[j]/a[i]>ans) { ans=b[j]/a[i]; sum=1; }
     else if (b[j]/a[i]==ans) sum++;
}
printf("%d\n",sum);
}