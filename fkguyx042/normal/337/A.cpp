#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans=10000;
int a[10001];
int check(int Max,int Min)
{ int i,sum=0;
  for (i=1;i<=m;i++)
   if (a[i]<=Max&&a[i]>=Min) sum++;
   return sum; }
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
   scanf("%d",&a[i]);
   for (i=1;i<=m;i++)
     for (j=1;j<=m;j++)
     if (a[i]>=a[j])
      if (check(a[i],a[j])>=n)
       ans=min(ans,a[i]-a[j]);
printf("%d\n",ans);
}