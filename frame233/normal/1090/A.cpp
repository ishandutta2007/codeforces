#include<cstdio>
const int N=200005;
int a[N],c[N];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
	int n,x,maxx=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int m;
		scanf("%d",&m);
		c[i]=m;
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&x);
			a[i]=max(a[i],x);
		}
		maxx=max(maxx,a[i]);
	}
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		ans+=1LL*(maxx-a[i])*c[i];
	}
	printf("%lld\n",ans);
	return 0;
}
// Dpair AK IOI