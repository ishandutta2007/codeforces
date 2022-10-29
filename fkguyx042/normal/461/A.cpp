#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int a[300001];
long long ans,sum;
int main()
{scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i]; 
  sort(a+1,a+n+1);
  ans=sum;
  for (i=1;i<n;i++)
  ans+=sum,sum-=a[i];
  printf("%I64d\n",ans);
}