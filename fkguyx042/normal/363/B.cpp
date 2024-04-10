#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans=0;
int a[200001];
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1];
  for (i=1;i<=n-k+1;i++)
   if (ans==0||a[i+k-1]-a[i-1]<a[ans+k-1]-a[ans-1])
     ans=i;
   printf("%d\n",ans);
}