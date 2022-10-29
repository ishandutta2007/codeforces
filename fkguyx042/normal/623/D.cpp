#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<ctime>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 105
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,k,t;
double liv[N],ans,p[N],val[N];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%lf",&p[i]),p[i]/=100.;
	for (i=1;i<=n;++i) liv[i]=1.;
	for (t=1;clock()<=1666;++t)
	{
		  for (i=1;i<=n;++i) val[i]=liv[i]*p[i]/(1-liv[i]);
		  val[k=0]=-1.;
		  for (i=1;i<=n;++i) if (val[i]>val[k]) k=i;
		  double prob=1.;
		  for (i=1;i<=n;++i)
		    if (i==k) prob*=p[i]*liv[i];
		    else prob*=(1-liv[i]);
		  liv[k]*=(1-p[k]);
		  ans+=t*prob;
	}
	printf("%.10lf\n",ans);
}