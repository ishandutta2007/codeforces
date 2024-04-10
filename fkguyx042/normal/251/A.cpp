#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,d,a[100001],x,y;
long long ans;
int main()
{ scanf("%d%d",&n,&d);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  for (i=1;i<=n-2;i++)
  {  x=upper_bound(a+1,a+n+1,a[i]+d)-a;
     --x;
     y=x-i;
     if (y>0) ans+=1ll*y*(y-1)/2;
}
printf("%I64d\n",ans);

}