#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	
	int mn=-1,mx=0;
	for(int i=0; i<=n; ++i)
	{
		ll nn = n-i;
		ll now = (nn*(nn-1))>>1;
		if(((nn+1)>>1)<=m && m<=now)
		{
			if(mn==-1) mn=i;
			mx=i;
		}
	}
	printf("%d %d",mn,mx);
	return 0;
}