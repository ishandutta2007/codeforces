#include<cstdio>
#include<algorithm>
using namespace std;
int t,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		long long x,y,n,m;
		scanf("%lld%lld%lld%lld",&x,&y,&n,&m);
		if(n+m>x+y) printf("NO\n");
		else if(min(x,y)<m) printf("NO\n");
		else printf("YES\n");
	}
}