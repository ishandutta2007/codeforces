#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100001],i,j,m,n,p,k;
long long ans;
bool check(long long x)
{ long long sum=0;
  for (i=1;i<=n;i++)
   if (a[i]>x) return 0;
   else  sum+=x-a[i];
   if (sum>=x) return true;
  return false;
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  long long l=0,r=1ll<<31,mid=0;
  while ((l+r)>>1ll!=mid)
  { mid=(l+r)>>1ll;
    if (check(mid)) r=mid;
	 else l=mid;
}
printf("%I64d\n",r);
}