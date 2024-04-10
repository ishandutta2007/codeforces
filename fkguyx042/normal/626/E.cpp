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

#define N 200005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
double ans;
int i,j,m,n,p,k,a[N],len,str;
long long b[N];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (i=1;i<=n;++i) b[i]=a[i]+b[i-1];
	ans=-1.;
	for (i=1;i<=n;++i)
	{
		  int l=0,r=min(i-1,n-i)+1,mid=0;
		  while ((l+r)>>1!=mid)
		  {
		  	  mid=(l+r)>>1;
		  	  if (1ll*(mid*2-2+1)*(a[i-mid]+a[n-mid+1])>=1ll*(a[i]+b[n]-b[n-mid+1]+b[i-1]-b[i-mid])*2) l=mid; else r=mid;
	      }
	      double sum=1.*(b[n]-b[n-l]+b[i-1]-b[i-l-1]+a[i])/(mid*2+1);
	      if (ans<sum-a[i])
	      { 
	          ans=sum-a[i]; len=l; str=i;
	      }
	}
	printf("%d\n",len*2+1);
	for (i=len;i;--i) printf("%d ",a[str-i]);
	printf("%d ",a[str]);
	for (i=1;i<=len;++i) printf("%d ",a[n-i+1]); 
}