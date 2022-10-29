#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans;
int f[100010],F[100010],a[100010];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  f[1]=F[n]=1;
  for (i=2;i<=n;i++)
   if (a[i]>a[i-1]) f[i]=f[i-1]+1; else f[i]=1;
  for (i=n-1;i;i--)
  if (a[i]<a[i+1])
   F[i]=F[i+1]+1; else F[i]=1;
  for (i=1;i<=n;i++)
   ans=max(ans,f[i]+(i>1));
  a[n+1]=(int)1e9;
  for (i=2;i<=n;i++)
   if (a[i+1]-a[i-1]>1)
    ans=max(ans,f[i-1]+F[i+1]+1);
    if (ans>n) ans=n;
printf("%d\n",ans);
}