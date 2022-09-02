#include <stdio.h>
#include <algorithm>
using namespace std;
int a[5005],bp[5005];
int n,m;
int calc(int val)
{
	int tot=0;
	for(int i=1;i<=m;i++)
	{
		while(val%bp[i]==0) { tot--; val/=bp[i]; }
	}
	for(int i=2;i*i<=val;i++)
	{
		while(val%i==0) { tot++; val/=i; }
	}
	return tot+(val!=1);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&bp[i]);
	int ret=0;
	for(int i=1;i<=n;i++) ret+=calc(a[i]);
	int g[5005]; g[0]=a[1];
	for(int i=1;i<=n;i++) g[i]=__gcd(g[i-1],a[i]);
	int gen=1;
	for(int i=n;i>=1;i--)
	{
		if(calc(g[i]/gen) < 0)
		{
			ret -= calc(g[i]/gen)*i;
			gen=g[i];
		}
	}
	printf("%d\n",ret);
}