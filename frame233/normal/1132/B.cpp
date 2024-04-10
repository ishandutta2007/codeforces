#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=300005;
int a[N];
int main()
{
	int n,m,x;
	ll s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),s+=a[i];
	std::sort(a+1,a+n+1);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&x);
		printf("%lld\n",s-a[n-x+1]);
	}
	return 0;
}
//Dpair AK IOI
//Dpair bless me