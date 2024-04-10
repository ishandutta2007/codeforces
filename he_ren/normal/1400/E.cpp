#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct State
{
	int a;
	ll f,g;
};

int a[MAXN];
ll dp[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	a[++n] = 0;
	
	stack<State> sta;
	sta.push((State){0,0,0});
	
	for(int i=1; i<=n; ++i)
	{
		dp[i] = linf;
		ll g = linf;
		while(!sta.empty() && sta.top().a >= a[i])
		{
			dp[i] = min(dp[i], sta.top().f + i - 1);
			g = min(g, sta.top().f);
			sta.pop();
		}
		g -= a[i];
		
		if(!sta.empty())
			g = min(g, sta.top().g),
			dp[i] = min(dp[i], sta.top().g + i - 1 + a[i]);
		
		g = min(g, dp[i] - i - a[i]);
		sta.push((State){a[i], dp[i]-i, g});
	}
	
	printf("%lld\n",dp[n]);
	return 0;
}