#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

int a[MAXN];

int main(void)
{
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	ll ans=0;
	while(1)
	{
		ll now=0;
		int cnt=0;
		for(int i=1; i<=n; ++i)
			if(now+a[i]<=m)
				now+=a[i], ++cnt;
		if(!cnt) break;
		ans += (m/now)*cnt;
		m%=now;
	}
	printf("%lld",ans);
	return 0;
}