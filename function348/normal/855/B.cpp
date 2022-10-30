#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,p,q,r;
int inf=1000000000;
int a[100100],b[100010],c[100010];
int main()
{
	scanf("%d%d%d%d",&n,&p,&q,&r);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	b[n+1]=-inf;c[n+1]=inf;
	for (int i=n;i>=1;i--) b[i]=max(b[i+1],a[i]);
	for (int i=n;i>=1;i--) c[i]=min(c[i+1],a[i]);
	int x=-inf,y=inf;
	long long ans=-1LL<<62;
	for (int i=1;i<=n;i++)
	{
		x=max(x,a[i]);
		y=min(y,a[i]);
		ans=max(ans,max(1LL*x*p,1LL*y*p)+1LL*a[i]*q+max(1LL*b[i]*r,1LL*c[i]*r));
	}
	cout<<ans<<endl;
	return 0;
}