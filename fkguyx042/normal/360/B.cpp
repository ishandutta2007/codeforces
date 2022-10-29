#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int f[2005],a[2005];
bool check(long long x)
{  
    int i,Ans=10000000;
    memset(f,60,sizeof(f));
    for (i=1;i<=n;i++)
    {
    	   f[i]=i-1;
    	   for (j=1;j<i;j++)
    	   if (1ll*abs(a[i]-a[j])<=1ll*(i-j)*x)
    	    f[i]=min(f[i],f[j]+i-j-1);
    }
    for (i=1;i<=n;i++) Ans=min(Ans,f[i]+(n-i));
    return Ans<=k;
}
int main()
{
	  scanf("%d%d",&n,&k);
	  for (i=1;i<=n;i++) scanf("%d",&a[i]);
	  long long l=0,r=(long long)2e9,mid=0;
	  for (;(l+r)>>1!=mid;)
	  {
	  	  mid=(l+r)>>1ll;
	  	  if (check(mid)) r=mid;
	  	  else l=mid;
	  	  if (r==1)
	  	   r=1;
      }
      printf("%I64d\n",r);
  }