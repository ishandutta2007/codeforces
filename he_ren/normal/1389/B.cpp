#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXZ = 5 + 5;
const int inf = 0x3f3f3f3f;

int n,d,z;
int a[MAXN];
ll sum[MAXN];

void solve(void)
{
	scanf("%d%d%d",&n,&d,&z);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	ll ans = sum[d+1];
	for(int i=0; i<=z; ++i)
	{
		int now = d+1 - i*2;
		if(now<=0) continue;
		
		ll res = sum[now];
		
		ll mx = 0;
		for(int k=1; k<=now && k+1<=n; ++k)
			mx = max(mx, (ll)a[k] + a[k+1]);
		
		ans = max(ans, res + mx * i);
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}