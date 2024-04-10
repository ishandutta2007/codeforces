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
#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
long long n,c,a[N],b[N];
int i;
long long check(long long x)
{
	  int i;
	  long long sum=0;
	  for (i=1;i<=n;++i)
	  {
	  	   if (1.*x*a[i]/b[i]>c+1) return c+1;
	  	   sum+=1ll*x*a[i]/b[i]+1;
	  	   if (sum>c) return c+1;
	  }
	  return sum;
}
int main()
{
	  scanf("%I64d%I64d",&n,&c); long long flag=0;
	  for (i=1;i<=n;++i)
	  	    scanf("%I64d%I64d",&a[i],&b[i]),flag+=a[i];
	  if (!flag)
	  {
	  	    if (c!=n) puts("0");
	  	    else puts("-1");
	  	    exit(0);
	  }
	  long long l=0,r=1e18,mid=0;
	  while ((l+r)>>1!=mid)
	  {
	  	  mid=(l+r)>>1;
	  	  if (check(mid)<c) l=mid; else r=mid;
	  }
	  long long L=0,R=1e18,Mid=0;
	  while ((L+R)>>1!=Mid)
	  {
	     Mid=(L+R)>>1; 
		 if (check(Mid)>c) R=Mid; else L=Mid;
	  }
	  printf("%I64d\n",max(0ll,R-l-1));
}