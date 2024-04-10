#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;

int a[MAXN];

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
		
		ll sum=0;
		for(int i=1; i<=n; ++i) sum+=a[i];
		printf("%lld\n",min(sum,(ll)m));
	}
	return 0;
}