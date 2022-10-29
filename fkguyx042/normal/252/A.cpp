#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[101],i,ans,n,j;
int main()
{ scanf("%d",&n); 
  for (i=1;i<=n;i++) scanf("%d",&a[i]),a[i]^=a[i-1];
  for (i=1;i<=n;i++)
    for (j=i;j<=n;j++)
      ans=max(ans,a[j]^a[i-1]);
    printf("%d\n",ans);
}