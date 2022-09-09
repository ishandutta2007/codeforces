#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int lb = 20;
const int LB = lb + 5;

int a[MAXN];
int cnt[LB];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		for(int j=0; j<lb; ++j)
			if((a[i]>>j)&1) ++cnt[j];
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
	{
		ll now = 0;
		for(int j=0; j<lb; ++j)
			if(cnt[j])
				now |= (1<<j),
				--cnt[j];
		if(!now) break;
		ans += now * now;
	}
	printf("%lld",ans);
	return 0;
}