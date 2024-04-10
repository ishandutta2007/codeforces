#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int a[200001];
int sum[200001];
long long ans;
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=n;i;i--)  sum[i]=sum[i+1]+(1-a[i]);
  for (i=1;i<=n;i++) if (a[i]&1) ans+=sum[i]; 
  printf("%I64d\n",ans);
}