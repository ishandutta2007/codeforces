#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 20
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,a[N],ans[N],sum[N];
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]);
	 ans[n]=-1; sum[n]=a[n];
	 for (i=n-1;i;--i)  sum[i]=min(sum[i+1],a[i]);
	 for (i=1;i<n;++i)
	 {
	 	  if (sum[i+1]>=a[i]) ans[i]=-1;
	 	  else 
	 	  {
	 	  	  int l=i+1,r=n+1,mid=0;
	 	  	  while ((l+r)>>1!=mid)
	 	  	  {
	 	  	  	  mid=(l+r)>>1;
	 	  	  	  if (sum[mid]<a[i]) l=mid; else r=mid;
			  }
			  ans[i]=l-i-1;
		  }
	}
	for (i=1;i<=n;++i) printf("%d ",ans[i]);
}