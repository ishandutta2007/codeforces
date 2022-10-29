#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a[100001],ans,Ans;
long long b[100001];
inline int check(int x)
{  int l=0,r=x+1,mid=0;
  for (;(l+r)>>1!=mid;)
  {  mid=(l+r)>>1;
    if (1ll*a[x]*(x-mid)-(b[x]-b[mid])<=k) r=mid; else l=mid; }
    return x-r;
} 
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  for (i=1;i<=n;i++) b[i]=b[i-1]+a[i];
  for (i=1;i<=n;i++) 
  if (ans<check(i))
  {  ans=check(i);
     Ans=a[i];}
  printf("%d %d\n",ans,Ans);
}