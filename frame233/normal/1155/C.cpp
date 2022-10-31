#include<cstdio>
const int N=300005;
typedef long long ll;
ll a[N],p[N];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	ll g=0,x;
	for(int i=2;i<=n;++i) g=gcd(g,a[i]-a[i-1]);
	for(int i=1;i<=m;++i)
	{
		scanf("%lld",&x);
		if(!(g%x))
		{
			printf("YES\n%lld %d\n",a[1],i);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}