#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,p;
long long n,m,k,l,r,mid;
inline bool check(long long x)
{ long long sum=0;
 for (i=1;i<=n;i++)
   sum+=min(x/i,m);
   if (sum>=k) return true; return false; } 
int main()
{ scanf("%I64d%I64d%I64d",&n,&m,&k);
  l=1; r=1ll*n*m+1;
  for (;(l+r)>>1ll!=mid;)
  { mid=(l+r)>>1ll;
    if (check(mid)) r=mid; else l=mid; }
printf("%I64d\n",r);
}