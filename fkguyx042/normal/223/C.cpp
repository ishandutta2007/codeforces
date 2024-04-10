#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 2005
#define M 200005
#define seed 23333
#define Mo 1000000007

using namespace std;
int i,j,m,n,p,k,w[N],a[N],ans[N];
int power(int x,int y)
{
	  int sum=1;
	  for (;y;y>>=1)
	  {
	  	  if (y&1) sum=1ll*sum*x%Mo;
	  	  x=1ll*x*x%Mo;
	  }
	  return sum;
}
int main()
{
	w[0]=1;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;++i) scanf("%d",&a[i]);
	if (k==0)
	{
		  for (i=1;i<=n;++i) printf("%d ",a[i]);
		  puts("");
	      return 0;
	}
	--k;
	for (i=1;i<=n;++i) w[i]=1ll*w[i-1]*(k+i)%Mo*power(i,Mo-2)%Mo;
	for (i=1;i<=n;++i)
	{
		  for (j=i;j<=n;++j)
		    ans[j]=(ans[j]+1ll*a[i]*w[j-i]%Mo)%Mo;
	}
	for (i=1;i<=n;++i) printf("%d ",ans[i]);
}