#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long i,j,m,n,k,ans;
long long gcd(long long a,long long b) { return b==0?a:gcd(b,a%b); }
long long get(long long x,long long y) {return x*y/gcd(x,y); }
int main()
{scanf("%I64d",&n);
  for (i=max(1ll,n-100);i<=n;i++)
    for (j=max(1ll,n-100);j<=n;j++)
      for (k=max(1ll,n-100);k<=n;k++)
        ans=max(ans,get(i,get(j,k)));
    printf("%I64d\n",ans);
}