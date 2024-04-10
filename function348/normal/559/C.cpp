#include<cstdio>
#include<iostream>
#include<algorithm>
#define FR first
#define SC second
using namespace std;
const int N=200100,p=1000000007;
typedef pair<int,int> PII;
int n,m,k;
PII a[N];
int c[N],d[N],f[N];
int C(int n,int m) { return 1LL*c[n+m]*d[n]%p*d[m]%p;}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++) scanf("%d%d",&a[i].FR,&a[i].SC);
	sort(a+1,a+1+k);
	d[0]=c[0]=d[1]=1;
	for (int i=1;i<=n+m;i++) c[i]=i;
	for (int i=2;i<=n+m;i++) d[i]=-1LL*(p/i)*d[p%i]%p;
	for (int i=2;i<=n+m;i++) c[i]=1LL*c[i-1]*c[i]%p;
	for (int i=2;i<=n+m;i++) d[i]=1LL*d[i-1]*d[i]%p;
	for (int i=1;i<=k;i++)
	{
		f[i]=C(a[i].FR-1,a[i].SC-1);
		for (int j=1;j<i;j++)
		if (a[j].FR<=a[i].FR&&a[j].SC<=a[i].SC)
			f[i]=(f[i]-1LL*C(a[i].FR-a[j].FR,a[i].SC-a[j].SC)*f[j])%p;
	}
	int ans=C(n-1,m-1);
	for (int i=1;i<=k;i++) ans=(ans-1LL*C(n-a[i].FR,m-a[i].SC)*f[i])%p;
	if (ans<0) ans+=p;
	printf("%d\n",ans);
	return 0;
}