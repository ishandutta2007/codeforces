#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXM = 10 + 5;
const ll linf = 0x3f3f3f3f;

int a[MAXN];
ll sum[MAXN];

ll mx[MAXM];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	ll ans = 0;
	
	for(int i=0; i<m; ++i)
		mx[i] = -linf;
	
	mx[0] = -d;
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<m; ++j)
			ans = max(ans, sum[i] + mx[j]);
		
		mx[i%m] = max(mx[i%m], -sum[i]);
		mx[i%m] -= d;
	}
	printf("%lld\n",ans);
	return 0;
}