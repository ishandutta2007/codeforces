#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[100001];
long long l,r,mid,i,j,m,n;
bool check(long long x)
{ int i,j;
   long long sum=0;
   a[0]=x;
   for (i=1;i<=n;i++) {
     sum+=(a[i-1]-a[i]); 
      if (sum<0) return false;
}
return true;
}
int main()
{scanf("%I64d",&n);
  for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
  l=0,r=(long long)1e11;
  for (;(l+r)>>1ll!=mid;)
  { mid=(l+r)>>1ll;
    if (check(mid)) r=mid; else l=mid;
  }
  printf("%I64d\n",r);
}