#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll sum = 0;
	priority_queue<int> q;
	for(int i=1; i<=n; ++i)
		sum += a[i], q.push(-a[i]);
	
	ll ans = 0;
	while(sum % (n-1))
	{
		int x = q.top(); q.pop();
		--x; ++sum; ++ans;
		q.push(x);
	}
	
	for(int i=1; i<=n; ++i)
		a[i] = -q.top(), q.pop();
	
	int num = sum / (n-1), mx = a[n];
	int lst = 0;
	for(int i=1; i<=n && mx > num; ++i)
	{
		int can = (mx + lst - a[i]) / (n-1);
		if(!can){ lst += mx - a[i]; continue;}
		
		int take = min(mx - num, can);
		
		num += take;
		ans += (ll)take * (n-1);
		
		a[i] += take * (n-1) - lst;
		lst = mx - a[i];
	}
	
	if(mx > num) ans += n-1;
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}