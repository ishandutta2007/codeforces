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

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,a[N],f[N];
double prob[N],g[N],ans;
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]);
	  sort(a+1,a+n+1);
	  for (i=1;i<=n;++i)
	    for (j=i+1;j<=n;++j) f[a[j]-a[i]]++;
	  for (i=1;i<=10000;++i) prob[i]=1.*f[i]/(n*(n-1)/2);
	  for (i=1;i<=10000;++i)
	     for (j=1;j<=10000;++j)
	          g[i+j]+=prob[i]*prob[j];
	  for (i=1;i<=20000;++i)
	     for (j=i+1;j<=5000;++j) ans+=prob[j]*g[i];
	  printf("%.10lf\n",ans);
}