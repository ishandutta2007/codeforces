#include<cstdio>
#include<algorithm>
#define N 1000005
using namespace std;
int a[N],last[N],i,j,ans,n,s;
int main()
{
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]),last[a[i]]=a[i];
  sort(a+1,a+n+1);s=a[n];
  for (i=1;i<=s;i++)
    last[i]+=(last[i]==0)*last[i-1];
  for (i=1;i<=n;i++)
    if (a[i]!=a[i-1])
      for (ans=max(ans,s%a[i]),j=a[i]<<1;j<=s;j+=a[i])
        ans=max(ans,last[j-1]%a[i]);
  printf("%d",ans);
}