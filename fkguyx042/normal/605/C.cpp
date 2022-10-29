#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005

using namespace std;
int i,j,m,n,k;
double a[N],b[N],p,q,ans;
double check(double x)
{
	  double y=1;
	  for (i=1;i<=n;++i) y=min(y,(1-b[i]*x)/a[i]);
	  ans=max(ans,p*y+q*x);
	  return p*y+q*x;
}
int main()
{
	 scanf("%d%lf%lf",&n,&p,&q);
	 for (i=1;i<=n;++i) scanf("%lf%lf",&a[i],&b[i]);
	 double l=0,r=1./(*max_element(b+1,b+n+1));//r=1./(*max_element(b+1,b+n+1));
	 ans=1e-20;
	 //while (r-l>1e-7)
	 for (;r-l>1e-12;)
	 {
	 	double len=(r-l)/3.,mid1=l+len,mid2=r-len;
	 	if (check(mid1)<=check(mid2)) l=mid1;
	 	else r=mid2;
	 }
	 printf("%.10lf\n",ans);
}