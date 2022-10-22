#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn=110000;

int i,a[maxn],bests[maxn],bestd[maxn],aux,n,s,sum[maxn],maxt,rez;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]),s+=a[i];
	aux=0;
	for(i=1;i<=n;++i)
		aux-=a[i],bests[i]=max(bests[i-1]+a[i],aux);
    
	aux=0;
	for(i=n;i;--i)
		aux-=a[i],bestd[i]=max(bestd[i+1]+a[i],aux);

	rez=s;
	for(i=1;i<=n;++i)
		rez=max(rez,bests[i-1]+bestd[i]);

	for(i=1;i<=n;++i)
		a[i]=-a[i],sum[i]=sum[i-1]+a[i];

	maxt=0;
	for(i=1;i<=n;++i)
		rez=max(rez,-s-2*sum[i]+2*maxt),maxt=max(maxt,sum[i]);

	printf("%d",rez);
}