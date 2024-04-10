#include<cstdio>
#include<algorithm>

using namespace std;

int n,a[250],i,maxt,poz;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	a[n+1]=a[1];
	maxt=2500;
	for(i=1;i<=n;++i)
		if(max(a[i]-a[i+1],a[i+1]-a[i])<maxt)
			maxt=max(a[i]-a[i+1],a[i+1]-a[i]),poz=i;

	printf("%d %d",poz,(poz%n)+1);
}